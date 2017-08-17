#include <cstdio>
#include <cstring>
#include <ctime>

#include "distances/DTW.h"
#include "distances/PrunedDTW.h"
#include "util/ParseInput.h"
#include "distances/BDTW.h"


int main(int argc, char* argv[]) {
	
	argc = 3;
	//argv[1]="/home/ashkan/SFA/SFA-master/datasets/CBF1/CBF_TRAIN.txt";
	//argv[2]="/home/ashkan/SFA/SFA-master/datasets/CBF1/CBF_TEST";
	//argv[1]="/home/ashkan/elect_T";
	//argv[2]="/home/ashkan/elect_Test";
	
//	char* nameoffile[] = {"LargeKitchenAppliances","FaceFour","Earthquakes","Computers","RefrigerationDevices","ElectricDevices","Two_Patterns"};
	char* nameoffile[] = {"SM"};
//	char* nameoffile[] = {"Earthquakes","Computers","RefrigerationDevices","ElectricDevices","Two_Patterns","FaceFour","ScreenType"};
	char* locationoffile ="/mnt/c/TS_Tab/";
	
	for (int start = 0; start<1; start++){
	char* trainfile = "_TRAIN.txt";
	char* testfile = "_TEST.txt";
	//char* trainfile = ".txt";
	//char* testfile = ".txt";
	char buffer[256];
	strncpy(buffer, locationoffile, sizeof(buffer));
	strncat(buffer, nameoffile[start], sizeof(buffer));
	strncat(buffer, trainfile, sizeof(buffer));
	
	char buffer2[256];
	strncpy(buffer2, locationoffile, sizeof(buffer));
	strncat(buffer2, nameoffile[start], sizeof(buffer));
	strncat(buffer2, testfile, sizeof(buffer));
	
	//argv[1]="/mnt/c/elect_T";
	argv[1]= buffer;
	argv[2]=buffer2;
	//argv[1]="/mnt/c/TS_Tab/SmallKitchenAppliances_TEST.txt";
	//argv[2]="/mnt/c/TS_Tab/SmallKitchenAppliances_TRAIN.txt";

	argv[3]="1";

	DataSet dsTrain, dsTest;
	ParseInput pi(0); // classIndex = 0
	clock_t t1, t2;

	double prev_dtw = INFINITY;
	double timeDTW[] = {0,0,0,0,0};
	double timeOracle[] = {0,0,0,0,0};
	double timePruned[] = {0,0,0,0,0};
	double timeAnoosh[] = {0,0,0,0,0};
	double v1, v2, v3,v4;
	double window;
	double newwindow;

	if (argc < 2) {
		printf("Parameters error\nCorrect using is:\n");
		printf("./DTWtool train_dataset test_dataset warping_window\n\n");
		return 1;
	}

	printf("Reading files\n");

	printf("%s\n", argv[1]);
	if (!pi.doParse(dsTrain, argv[1], 0)) {
		printf("Error reading train file\n");
		return 1;
	}

	printf("%s\n", argv[2]);
	if (!pi.doParse(dsTest, argv[2], 0)) {
		printf("Error reading test file\n");
		return 1;
	}

	dsTrain.addExamples(dsTest.getData());

	printf("\nFinal dataset: %d instances with %d observations each\n\n",
			dsTrain.getSize(), dsTrain.getTimeSeriesAt(0).getLength());


	int nRep = 1;
	for (int r = 0; r < nRep; r++) {

		for (int i = 0; i < dsTrain.getSize(); i++) {

			for (int j = i + 1; j < dsTrain.getSize(); j++) {

				for (int k = 1; k <= 2; k++) {
					
					if (k==1){
						window = k*1;
					} else{
						window = 1;
					}
					

					//window = k*0.1;
//					window = 1;
					t1 = clock();
					v1 = DTW::dtw(dsTrain.getTimeSeriesAt(i), dsTrain.getTimeSeriesAt(j), window);
					t2 = clock();

					timeDTW[k-1] += (double)(t2-t1)/CLOCKS_PER_SEC;

					if (k==1) {
						t1 = clock();
						v2 = PrunedDTW::prunedDTW(dsTrain.getTimeSeriesAt(i),
								dsTrain.getTimeSeriesAt(j), window);
						t2 = clock();
					} else {
						t1 = clock();
						v2 = PrunedDTW::prunedDTW(dsTrain.getTimeSeriesAt(i),
								dsTrain.getTimeSeriesAt(j), window, prev_dtw);
						t2 = clock();
					}

					timePruned[k-1] += (double)(t2-t1)/CLOCKS_PER_SEC;
					
					

					t1 = clock();
					v3 = PrunedDTW::prunedDTW(dsTrain.getTimeSeriesAt(i), dsTrain.getTimeSeriesAt(j), window, v1);
					t2 = clock();

					timeOracle[k-1] += (double)(t2-t1)/CLOCKS_PER_SEC;
					
					
					if (k==1){
						t1 = clock();
						v4 = BDTW::dtw_ub_all(dsTrain.getTimeSeriesAt(i),dsTrain.getTimeSeriesAt(j),window);
						t2 = clock();
						newwindow = v4;
					} else {
						t1 = clock();
						v4 = PrunedDTW::prunedDTW(dsTrain.getTimeSeriesAt(i),
								dsTrain.getTimeSeriesAt(j), window,newwindow);
						t2 = clock();						
					}
					
					
					timeAnoosh[k-1]+= (double)(t2-t1)/CLOCKS_PER_SEC;
					
					

					//if (abs(v1-v2) > 0.000001 || abs(v1-v3) > 0.000001) {
					//	printf("ERROR IN (%d %d) : DTW = %f / PrunedDTW = %f / OracleDTW = %f - w=%.2f\n", i, j, v1, v2, v3, window);
					//}
					
					//printf("DTW/ (%f) / PrunedDTW/(%f)/OracleDTW/%f/AnooshDtw/%f\n",v1,v2,v3,v4);

					prev_dtw = v1;

				}

			}

		}

	}
	
	std::ofstream myfile1;
	char buffer1[256];
	char* lfile = "filename.txt";
	
	strncpy(buffer1, buffer, sizeof(buffer));
	strncat(buffer1, lfile, sizeof(buffer));
	
	
	myfile1.open (buffer1);

	for (int k = 1; k <= 2; k++) {
		printf("ws = 0.%d\nDTW/PrunedDTW/OracleDTW/AnooshDTW\n%f\n%f\n%f\n%f\n\n",
			k, timeDTW[k-1], timePruned[k-1]
			, timeOracle[k-1] 
			,timeAnoosh[k-1]
			);
			
			
			myfile1<<k;
			myfile1<<"\n";
			myfile1<<"DTW:";
			myfile1<<timeDTW[k-1];
			myfile1<<"\n";
			myfile1<<"PrunedDTW:";	
			myfile1<<timePruned[k-1];
			myfile1<<"\n";
			myfile1<<"OracleDTW:";
			myfile1<<timeOracle[k-1];
			myfile1<<"\n";
			myfile1<<"AnooshDTW:";
			myfile1<<timeAnoosh[k-1];
			myfile1<<"\n";
			
	}
	}


	return 0;

}
