##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=dtwtool
ConfigurationName      :=Debug
WorkspacePath          :=/mnt/c/DTW1/dtwTool_warpingUB
ProjectPath            :=/mnt/c/DTW1/dtwTool_warpingUB/dtwtool
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ashkan
Date                   :=23/10/16
CodeLitePath           :=/home/ashkan/.codelite
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="dtwtool.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/timeseries_DataSet.cpp$(ObjectSuffix) $(IntermediateDirectory)/timeseries_TimeSeries.cpp$(ObjectSuffix) $(IntermediateDirectory)/distances_Euclidean.cpp$(ObjectSuffix) $(IntermediateDirectory)/distances_PrunedDTW.cpp$(ObjectSuffix) $(IntermediateDirectory)/distances_DTW.cpp$(ObjectSuffix) $(IntermediateDirectory)/util_Util.cpp$(ObjectSuffix) $(IntermediateDirectory)/util_ParseInput.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/timeseries_DataSet.cpp$(ObjectSuffix): timeseries/DataSet.cpp $(IntermediateDirectory)/timeseries_DataSet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/c/DTW1/dtwTool_warpingUB/dtwtool/timeseries/DataSet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/timeseries_DataSet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/timeseries_DataSet.cpp$(DependSuffix): timeseries/DataSet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/timeseries_DataSet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/timeseries_DataSet.cpp$(DependSuffix) -MM timeseries/DataSet.cpp

$(IntermediateDirectory)/timeseries_DataSet.cpp$(PreprocessSuffix): timeseries/DataSet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/timeseries_DataSet.cpp$(PreprocessSuffix)timeseries/DataSet.cpp

$(IntermediateDirectory)/timeseries_TimeSeries.cpp$(ObjectSuffix): timeseries/TimeSeries.cpp $(IntermediateDirectory)/timeseries_TimeSeries.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/c/DTW1/dtwTool_warpingUB/dtwtool/timeseries/TimeSeries.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/timeseries_TimeSeries.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/timeseries_TimeSeries.cpp$(DependSuffix): timeseries/TimeSeries.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/timeseries_TimeSeries.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/timeseries_TimeSeries.cpp$(DependSuffix) -MM timeseries/TimeSeries.cpp

$(IntermediateDirectory)/timeseries_TimeSeries.cpp$(PreprocessSuffix): timeseries/TimeSeries.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/timeseries_TimeSeries.cpp$(PreprocessSuffix)timeseries/TimeSeries.cpp

$(IntermediateDirectory)/distances_Euclidean.cpp$(ObjectSuffix): distances/Euclidean.cpp $(IntermediateDirectory)/distances_Euclidean.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/c/DTW1/dtwTool_warpingUB/dtwtool/distances/Euclidean.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/distances_Euclidean.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/distances_Euclidean.cpp$(DependSuffix): distances/Euclidean.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/distances_Euclidean.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/distances_Euclidean.cpp$(DependSuffix) -MM distances/Euclidean.cpp

$(IntermediateDirectory)/distances_Euclidean.cpp$(PreprocessSuffix): distances/Euclidean.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/distances_Euclidean.cpp$(PreprocessSuffix)distances/Euclidean.cpp

$(IntermediateDirectory)/distances_PrunedDTW.cpp$(ObjectSuffix): distances/PrunedDTW.cpp $(IntermediateDirectory)/distances_PrunedDTW.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/c/DTW1/dtwTool_warpingUB/dtwtool/distances/PrunedDTW.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/distances_PrunedDTW.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/distances_PrunedDTW.cpp$(DependSuffix): distances/PrunedDTW.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/distances_PrunedDTW.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/distances_PrunedDTW.cpp$(DependSuffix) -MM distances/PrunedDTW.cpp

$(IntermediateDirectory)/distances_PrunedDTW.cpp$(PreprocessSuffix): distances/PrunedDTW.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/distances_PrunedDTW.cpp$(PreprocessSuffix)distances/PrunedDTW.cpp

$(IntermediateDirectory)/distances_DTW.cpp$(ObjectSuffix): distances/DTW.cpp $(IntermediateDirectory)/distances_DTW.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/c/DTW1/dtwTool_warpingUB/dtwtool/distances/DTW.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/distances_DTW.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/distances_DTW.cpp$(DependSuffix): distances/DTW.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/distances_DTW.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/distances_DTW.cpp$(DependSuffix) -MM distances/DTW.cpp

$(IntermediateDirectory)/distances_DTW.cpp$(PreprocessSuffix): distances/DTW.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/distances_DTW.cpp$(PreprocessSuffix)distances/DTW.cpp

$(IntermediateDirectory)/util_Util.cpp$(ObjectSuffix): util/Util.cpp $(IntermediateDirectory)/util_Util.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/c/DTW1/dtwTool_warpingUB/dtwtool/util/Util.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/util_Util.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/util_Util.cpp$(DependSuffix): util/Util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/util_Util.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/util_Util.cpp$(DependSuffix) -MM util/Util.cpp

$(IntermediateDirectory)/util_Util.cpp$(PreprocessSuffix): util/Util.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/util_Util.cpp$(PreprocessSuffix)util/Util.cpp

$(IntermediateDirectory)/util_ParseInput.cpp$(ObjectSuffix): util/ParseInput.cpp $(IntermediateDirectory)/util_ParseInput.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/c/DTW1/dtwTool_warpingUB/dtwtool/util/ParseInput.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/util_ParseInput.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/util_ParseInput.cpp$(DependSuffix): util/ParseInput.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/util_ParseInput.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/util_ParseInput.cpp$(DependSuffix) -MM util/ParseInput.cpp

$(IntermediateDirectory)/util_ParseInput.cpp$(PreprocessSuffix): util/ParseInput.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/util_ParseInput.cpp$(PreprocessSuffix)util/ParseInput.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/c/DTW1/dtwTool_warpingUB/dtwtool/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix)main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


