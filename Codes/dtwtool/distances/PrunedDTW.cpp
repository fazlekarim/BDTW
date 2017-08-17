/*
 * PrunedDTW.cpp
 *
 *  Created on: Jan 21, 2015
 *      Author: diego
 */

#include "PrunedDTW.h"

#include "PrunedDTW.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>

PrunedDTW::PrunedDTW() {
	// TODO Auto-generated constructor stub
	setWarpingRate(100.0);
}

PrunedDTW::PrunedDTW(double warping) {
	// TODO Auto-generated constructor stub
	setWarpingRate(warping);
}

PrunedDTW::~PrunedDTW() {
	// TODO Auto-generated destructor stub
}

/**
 **/
double PrunedDTW::prunedDTW(TimeSeries p, TimeSeries q) {
	return prunedDTW(p, q, 1);
}





double PrunedDTW::prunedDTW(TimeSeries p, TimeSeries q, double warping) {

	// "DTW matrix" in linear space.
	double dtwMatrix[2][p.getLength()+1];
	// The absolute size of the warping window (to each side of the main diagonal)
	int w = Util::getWarpingRadius(p,warping);

	// Start column
	int sc = 1;
	bool found_lower;

	// End column
	int ec = 1;
	int ec_next;

	// Upper bound, calculated by the Euclidean distance
	double UB[q.getLength()+1];

	// Calculating UB and initializing DTW matrix
	UB[q.getLength()] = 0;
	for (int i = q.getLength()-1; i >= 0; i--) {

		UB[i] = UB[i+1] + Euclidean::euclidean(
				p.getValueAt(i),q.getValueAt(i));

		dtwMatrix[0][i] = INFINITY;
		dtwMatrix[1][i] = INFINITY;

	}
	dtwMatrix[0][q.getLength()] = INFINITY;
	dtwMatrix[1][q.getLength()] = INFINITY;
	dtwMatrix[0][0] = 0;
	
	
//	double** data1reduced = BDTW::bdtw_runs(p);
////	double random = data1reduced[0][5];
//	
//	double** data2reduced = BDTW::bdtw_runs(q);
//////	
//	double bdup = BDTW::dtw_ub(data1reduced,data2reduced);
	
//	double bdup1 = BDTW::dtw_ub_all(p,q);

//	double bdup = BDTW::dtw_ub(BDTW::bdtw_runs(p),BDTW::bdtw_runs(q));
	
	
	
//	double ub1;
	
//	if (bdup1<=UB[0]){
//		ub1=bdup1;
//	}
//	if (bdup1>UB[0]){
//		ub1=UB[0];
//	}
	// Upper bound, calculated by the Euclidean distance (for now)
	double ub = UB[0];
//	double ub = ub1;

		std::ofstream myfile2;
		
	
		myfile2.open ("/mnt/c/TS_Tab/Pruned1.txt");
	
	

	// Distance calculation
	for (int i = 1; i <= q.getLength(); i++) {

		int thisI = i % 2;
		int prevI = (i-1) % 2;

		int beg = std::max(sc,i-w);
		int end = std::min(i+w,p.getLength());
		ub = UB[i-1] + dtwMatrix[prevI][i-1];

		// Fixing values to this iteration
		dtwMatrix[thisI][beg-1] = INFINITY;
		dtwMatrix[thisI][i] = INFINITY;
		found_lower = false;

		for (int j = beg; j <= end; j++) {

			// Fixing the case when prune the end and let garbagge in the vector
			if (j > ec) {

				dtwMatrix[thisI][j] = dtwMatrix[thisI][j-1];

			} else {

				dtwMatrix[thisI][j] = std::min(dtwMatrix[thisI][j-1],std::min(dtwMatrix[prevI][j],
						dtwMatrix[prevI][j-1]));

			}

			dtwMatrix[thisI][j] += Euclidean::euclidean(q.getValueAt(i-1),p.getValueAt(j-1));

			if (dtwMatrix[thisI][j] > ub) {

				if (!found_lower) {
					sc = j + 1;
				}

				if (j > ec) {
					dtwMatrix[thisI][j+1] = INFINITY;
					break; // Prune
				}

			} else {

				found_lower = true;
				ec_next = j;

			}
			
			myfile2<<dtwMatrix[thisI][j+1];
			myfile2<<",";

		}
		
		myfile2<<"\n";


		// Update information of the last column with value < UB
		ec_next++;
		ec = ec_next;

	}
	  

	return dtwMatrix[q.getLength()%2][p.getLength()];
	//double bdup = BDTW::dtw_ub_all(p,q,warping);
	//return bdup;

}


double PrunedDTW::prunedDTW(TimeSeries p, TimeSeries q, double warping, double ub) {

	// "DTW matrix" in linear space.
	double dtwMatrix[2][p.getLength()+1];
	// The absolute size of the warping window (to each side of the main diagonal)
	int w = Util::getWarpingRadius(p,warping);

	// Start column
	int sc = 1;
	bool found_lower;

	// End column
	int ec = 1;
	int ec_next = 1;

	// Initialization (all elements of the first line are INFINITY, except the 0th, and
	// the same value is given to the first element of the first analyzed line).
	for (int i = 0; i <= p.getLength(); i++) {
		dtwMatrix[0][i] = INFINITY;
		dtwMatrix[1][i] = INFINITY;
	}
	dtwMatrix[0][0] = 0;

	// Distance calculation
	
		std::ofstream myfile2;
		
	
		myfile2.open ("/mnt/c/TS_Tab/Pruned.txt");
	for (int i = 1; i <= q.getLength(); i++) {

		int thisI = i % 2;
		int prevI = (i-1) % 2;

		int beg = std::max(sc,i-w);
		int end = std::min(i+w,p.getLength());

		// Fixing values to this iteration
		dtwMatrix[thisI][beg-1] = INFINITY;
		found_lower = false;
		


		for (int j = beg; j <= end; j++) {

			// Fixing the case when prune the end and let garbagge in the vector
			if (j > ec) {

				dtwMatrix[thisI][j] = dtwMatrix[thisI][j-1];

			} else {

				dtwMatrix[thisI][j] = std::min(dtwMatrix[thisI][j-1],std::min(dtwMatrix[prevI][j],
						dtwMatrix[prevI][j-1]));

			}

			dtwMatrix[thisI][j] += Euclidean::euclidean(q.getValueAt(i-1),p.getValueAt(j-1));

			if (dtwMatrix[thisI][j] > ub) {

				if (!found_lower) {
					sc = j + 1;
				}

				if (j > ec) {
					dtwMatrix[thisI][j+1] = INFINITY;
					break; // Prune
				}

			} else {

				found_lower = true;
				ec_next = j;

			}
			
			myfile2<<dtwMatrix[thisI][j+1];
			myfile2<<",";

		}
		myfile2<<"\n";

		// Update information of the last column with value < UB
		ec_next++;
		ec = ec_next;

	}
	
	myfile2.close();

	return dtwMatrix[q.getLength()%2][p.getLength()];

}


void PrunedDTW::setWarpingRate(double warping) {
	PrunedDTW::warpingRate = std::min(std::max(warping,0.0),100.0);
}

double PrunedDTW::getWarpingRate() {
	return PrunedDTW::warpingRate;
}
