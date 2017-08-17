##========================================================================
## Encodes the Time Series into Values and Repetitions
##========================================================================
function Runs_Reducer(series1)
  val = [series1[1]]
  rep = [1]

  for i in 2:length(series1)
    if i == 2 && series1[i] == series1[i-1]
      append!(val, series1[i])
      append!(rep, 1)
    elseif i == length(series1) && series1[i] == series1[i-1]
      append!(val, series1[i])
      append!(rep, 1)
    elseif series1[i] == series1[i-1] && i != 2 && i != length(series1)
      rep[length(rep)] = rep[length(rep)] + 1
    else series1[i] != series1[i-1]
      append!(val, series1[i])
      append!(rep, 1)
    end
  end

  mat = hcat(val, rep)
  mat = mat'
  return(mat)
end

##========================================================================
## Computes the upper bound of Blocked DTW distance
## Takes in Reduced series (Runs_Reducer)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
##========================================================================
function BDTW_UB(Rseries1, Rseries2, z = 0)
  l1 = length(Rseries1[1,1:end])
  l2 = length(Rseries2[1,1:end])

  E = Inf*ones(l1,l2)

  E[1,1] = (Rseries1[1,1] - Rseries2[1,1])^2

  for i in 2:l1
    E[i,1] = E[i-1,1] + Rseries1[2,i]*(Rseries1[1,i] - Rseries2[1,1])^2
  end

  for i in 2:l2
    E[1,i] = E[1,i-1] + Rseries2[2,i]*(Rseries1[1,1] - Rseries2[1,i])^2
  end

  for j in 2:l2
    for i in 2:l1
      if Rseries1[2,i] == 1 &&  Rseries2[2,j] == 1      #Case No Runs
        E[i,j] = min(E[(i-1),j], E[(i-1),(j-1)], E[i,(j-1)]) + (Rseries1[1,i] - Rseries2[1,j])^2
      elseif Rseries1[2,i] != 1 &&  Rseries2[2,j] == 1      #Case One Run
        t = E[i-1,j] + Rseries1[2,i]*(Rseries1[1,i] - Rseries2[1,j])^2
        d = E[i-1,j-1] + Rseries1[2,i]*(Rseries1[1,i] - Rseries2[1,j])^2
        l = E[i,j-1] + (Rseries1[1,i] - Rseries2[1,j])^2
        E[i,j] = min(t, d, l)
      elseif Rseries1[2,i] == 1 &&  Rseries2[2,j] != 1      #Case One Run
        t = E[i-1,j] + (Rseries1[1,i] - Rseries2[1,j])^2
        d = E[i-1,j-1] + Rseries2[2,j]*(Rseries1[1,i] - Rseries2[1,j])^2
        l = E[i,j-1] + Rseries2[2,j]*(Rseries1[1,i] - Rseries2[1,j])^2
        E[i,j] = min(t, d, l)
      elseif Rseries1[2,i] != 1 &&  Rseries2[2,j] != 1      #Case two Runs
        t = E[i-1,j] + Rseries1[2,i]*(Rseries1[1,i] - Rseries2[1,j])^2
        d = E[i-1,j-1] + max(Rseries1[2,i],Rseries2[2,j])*(Rseries1[1,i] - Rseries2[1,j])^2
        l = E[i,j-1] + Rseries2[2,j]*(Rseries1[1,i] - Rseries2[1,j])^2
        E[i,j] = min(t, d, l)
      end
    end
  end

  if z == 0
    return(sqrt(E[l1,l2]))
  else
    return(E)
  end
end

##========================================================================
## Classification Algorithm where Blocked DTW is the distance measure
##========================================================================
function Classification_BDTW(d)
    train = readdlm(string("/Archive/",d,"/",d,"_TRAIN.txt"), ',')
    test = readdlm(string("/Archive/",d,"/",d,"_TEST.txt"), ',')
    #Get Labes
    train_labels = train[:,1]
    test_labels = test[:,1]

    #Subset Train and Test
    train = train[:,2:end]
    test = test[:,2:end]

    #Get the Number of Rows in each set
    l_train = length(train[:,1])
    l_test = length(test[:,1])

    wrong = 0
    predicted_class = zeros(l_test)

    for j in  1:l_test
        BSF = 1000000
        for i in 1:l_train
            distance = BDTW_UB(Runs_Reducer(train[i,:]), Runs_Reducer(test[j,:]))
            if distance < BSF
                predicted_class[j] = train_labels[i]
                BSF = distance
            end
        end
        if predicted_class[j] != test_labels[j]
            wrong = wrong + 1
        end
    end
    return(wrong/l_test)
end

##========================================================================
##Computes the Kim Lower Bounding Distance
##========================================================================
function LB_Kim(series1, series2)
  A = (series1[1] - series2[1])^2
  D = (series1[length(series1)] - series2[length(series2)])^2
  return(sqrt(A+D))
end

##========================================================================
##Computes the Yi Lower Bounding Distance
##========================================================================
function LB_Yi(series1, series2)
  Max = reduce(max, series2)
  Min = reduce(min, series2)
  total = 0

  for i in 1:length(series1)
    if series1[i] > Max
      total = total + (series1[i] - Max)^2
    elseif series1[i] < Min
      total = total + (series1[i] - Min)^2
    end
  end

  return(sqrt(total))
end



##========================================================================
## Computes the lower bound of Blocked DTW distance
## Takes in Reduced series (Runs_Reducer)
##========================================================================
function BDTW_LB(Rseries1, Rseries2, z =0)
  l1 = length(Rseries1[1,1:end])
  l2 = length(Rseries2[1,1:end])

  E = Inf*ones(l1,l2)

  E[1,1] = (Rseries1[1,1] - Rseries2[1,1])^2

  for i in 2:l1
    E[i,1] = E[i-1,1] + Rseries1[2,i]*(Rseries1[1,i] - Rseries2[1,1])^2
  end

  for i in 2:l2
    E[1,i] = E[1,i-1] + Rseries2[2,i]*(Rseries1[1,1] - Rseries2[1,i])^2
  end

  for j in 2:l2
    for i in 2:l1
      if Rseries1[2,i] == 1 &&  Rseries2[2,j] == 1      #Case No Runs
        E[i,j] = min(E[(i-1),j], E[(i-1),(j-1)], E[i,(j-1)]) + (Rseries1[1,i] - Rseries2[1,j])^2
      elseif Rseries1[2,i] != 1 &&  Rseries2[2,j] == 1      #Case One Run
        t = E[i-1,j] + Rseries1[2,i]*(Rseries1[1,i] - Rseries2[1,j])^2
        d = E[i-1,j-1] + (Rseries1[1,i] - Rseries2[1,j])^2
        l = E[i,j-1] + (Rseries1[1,i] - Rseries2[1,j])^2
        E[i,j] = min(t, d, l)
      elseif Rseries1[2,i] == 1 &&  Rseries2[2,j] != 1      #Case One Run
        t = E[i-1,j] + (Rseries1[1,i] - Rseries2[1,j])^2
        d = E[i-1,j-1] + (Rseries1[1,i] - Rseries2[1,j])^2
        l = E[i,j-1] + Rseries2[2,j]*(Rseries1[1,i] - Rseries2[1,j])^2
        E[i,j] = min(t, d, l)
      elseif Rseries1[2,i] != 1 &&  Rseries2[2,j] != 1      #Case two Runs
        t = E[i-1,j] + Rseries1[2,i]*(Rseries1[1,i] - Rseries2[1,j])^2
        d = E[i-1,j-1] + min(Rseries1[2,i],Rseries2[2,j])*(Rseries1[1,i] - Rseries2[1,j])^2
        l = E[i,j-1] + Rseries2[2,j]*(Rseries1[1,i] - Rseries2[1,j])^2
        E[i,j] = min(t, d, l)
      end
    end
  end

  if z == 0
    return(sqrt(E[l1,l2]))
  else
    return(E)
  end
end

##========================================================================
## Classification Algorithm using LB_Kim as the Lower Bound
##========================================================================
function Classification_DTW_wKim(train, test)
  train_labels = train[:,1]
  test_labels = test[:,1]

  train = train[:,2:end]
  test = test[:,2:end]

  l_train = length(train[:,1]); l_test = length(test[:,1])

  wrong = 0.0
  predicted_class = zeros(l_test)

  for j in 1:l_test
    BSF = 1000000
    for i in 1:l_train
      LBk = LB_Kim(train[i,:], test[j,:])
      if LBk < BSF
        distance = DTW(train[i,:], test[j,:])
        if distance < BSF
          BSF = distance
          predicted_class[j] = train_labels[i]
        end
      end
    end
    if predicted_class[j] != test_labels[j]
      wrong += 1
    end
  end
  return(wrong/l_test)
end

##========================================================================
## Classification Algorithm using LB_Yi as the Lower Bound
##========================================================================
function Classification_DTW_wYi(train, test)
  train_labels = train[:,1]
  test_labels = test[:,1]

  train = train[:,2:end]
  test = test[:,2:end]

  l_train = length(train[:,1]); l_test = length(test[:,1])

  wrong = 0.0
  predicted_class = zeros(l_test)

  for j in 1:l_test
    BSF = 1000000
    for i in 1:l_train
      LBy = LB_Yi(train[i,:], test[j,:])
      if LBy < BSF
        distance = DTW(train[i,:], test[j,:])
        if distance < BSF
          BSF = distance
          predicted_class[j] = train_labels[i]
        end
      end
    end
    if predicted_class[j] != test_labels[j]
      wrong += 1
    end
  end
  return(wrong/l_test)
end

##========================================================================
## Classification Algorithm using Blocked DTW as the Lower Bound
##========================================================================
function Classification_DTW_wBDTWLB(train, test)
  train_labels = train[:,1]
  test_labels = test[:,1]

  train = train[:,2:end]
  test = test[:,2:end]

  l_train = length(train[:,1]); l_test = length(test[:,1])

  wrong = 0
  predicted_class = zeros(l_test)

  for j in  1:l_test
    BSF = 1000000
    for i in 1:l_train
      LB = BDTW_LB(Runs_Reducer(train[i,:]), Runs_Reducer(test[j,:]))
      if LB < BSF
        distance = DTW(train[i,:], test[j,:])
        if distance < BSF
          BSF = distance
          predicted_class[j] = train_labels[i]
        end
      end
    end
    if predicted_class[j] != test_labels[j]
      wrong = wrong + 1
    end
  end
  return(wrong/l_test)
end













##########################################################################################
##########################################################################################
##########################################################################################
##########################################################################################
function Classification_DTW_wKeough(train, test, w = .1)
  #Get Labes
  train_labels = train[:,1]
  test_labels = test[:,1]

  #Subset Train and Test
  train = train[:,2:end]
  test = test[:,2:end]

  #Get the Number of Rows in each set
  l_train = length(train[:,1]); l_test = length(test[:,1])

  wrong = 0.0
  predicted_class = zeros(l_test)

  for j in 1:l_test
    count1 = 0  #
    count2 = 0  #
    BSF = 1000000
    for i in 1:l_train
      LB = LB_Keough(train[i,:], test[j,:], w)
      if LB < BSF
        distance = C_DTW(train[i,:], test[j,:],w)
        if distance < BSF
          BSF = distance
          predicted_class[j] = train_labels[i]
        end
      end
    end
    if predicted_class[j] != test_labels[j]
      wrong += 1
    end
  end
  return(wrong/l_test)
end




function LB_Keough(series1, series2, w)
  x = series1
  y = series2
  yl = length(series2)
  xl = length(series1)
  LB = 0.0
  r = convert(Int64{},round(yl*w))
  U = []
  L = []

  for i in collect(1:yl)
    right = i + r
    left = i - r
    if right > yl
      right = yl
    end
    if left < 1
      left = 1
    end
    if i <= r  && (i+r) <= yl
      append!(U, maximum(y[1:right]))
      append!(L, minimum(y[1:right]))
    elseif (i+r) >= yl
      append!(U, maximum(y[left:yl]))
      append!(L, minimum(y[left:yl]))
    elseif i > r && i < (yl-r)
      append!(U, maximum(y[left:right]))
      append!(L, minimum(y[left:right]))
    end
    if x[i] > U[i]
      LB = (x[i] - U[i])^2 + LB
    end
    if x[i] < L[i]
      LB = (x[i] - L[i])^2 + LB
    end
  end

  LB = sqrt(LB)
  return(LB)
end

function DTW(series1, series2, z = 0)
  #Create Matrix of Zeros
  l1 = length(series1)
  l2 = length(series2)
  E = zeros(l1,l2)

  #Fill First Cell
  E[1,1] = (series1[1]-series2[1])^2

  #Fill First Column
  for i in 2:l1
    E[i,1] = E[(i-1),1] + (series1[i]-series2[1])^2
  end

  #Fill First Row
  for i in 2:l2
    E[1,i] = E[1,(i-1)] + (series1[1]-series2[i])^2
  end

  for j in 2:l2
    for i in 2:l1
      E[i,j] = min(E[(i-1),j], E[(i-1),(j-1)], E[i,(j-1)]) + (series1[i]-series2[j])^2
    end
  end

  if z == 0
    return(sqrt(E[end,end]))
  else
    return(E)
  end
end




function C_DTW(series1, series2, w)
  #Create Matrix of Zeros
  l1 = length(series1)
  l2 = length(series2)
  E = Inf*ones(l1,l2)
  width = convert(Int64{}, ceil(length(series1)*w))

  #Fill First Cell
  E[1,1] = (series1[1]-series2[1])^2

  #Fill First Column
  if width >= 2
    for i in 2:width
      E[i,1] = E[(i-1),1] + (series1[i]-series2[1])^2
    end

    for i in 2:l2
      E[1,i] = E[1,(i-1)] + (series1[1]-series2[i])^2
    end
  end

  z = 2
  col_count = width + 2
  for j in 2:l2
    for i in z:col_count
      E[i,j] = min(E[(i-1),j], E[(i-1),(j-1)], E[i,(j-1)]) + (series1[i]-series2[j])^2
    end
    if j > width+1
      z += 1
    end
    if (z+(width*2)) > length(E[1,:])
      col_count = length(E[1,:])
    else
      col_count += 1
    end
  end

  return(sqrt(E[end,end]))
end
