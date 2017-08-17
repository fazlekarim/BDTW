/*
 * DTW.cpp
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include "DTW.h"

DTW::DTW() {
	setWarpingRate(100.0);
}

DTW::DTW(double warping) {
	setWarpingRate(std::min(std::max(warping,0.0),100.0));
}

DTW::~DTW() {
	// TODO Auto-generated destructor stub
}

/**
 **/
double DTW::dtw(TimeSeries p, TimeSeries q) {
	return dtw(p, q, 100.0);
}

/**
 **/
double DTW::dtw(TimeSeries p, TimeSeries q, double warping) {

	// "DTW matrix" in linear space.
	double dtwMatrix[2][p.getLength()+1];
	// The absolute size of the warping window (to each side of the main diagonal)
	int w = Util::getWarpingRadius(p,warping);

	// Initialization (all elements of the first line are INFINITY, except the 0th, and
	// the same value is given to the first element of the first analyzed line).
	for (int i = 0; i <= p.getLength(); i++) {
		dtwMatrix[0][i] = INFINITY;
		dtwMatrix[1][i] = INFINITY;
	}
	dtwMatrix[0][0] = 0;

	// Distance calculation
	for (int i = 1; i <= q.getLength(); i++) {

		int beg = std::max(1,i-w);
		int end = std::min(i+w,p.getLength());

		int thisI = i % 2;
		int prevI = (i-1) % 2;

		// Fixing values to this iteration
		dtwMatrix[i%2][beg-1] = INFINITY;

		for (int j = beg; j <= end; j++) {

			// DTW(i,j) = c(i-1,j-1) + min(DTW(i-1,j-1), DTW(i,j-1), DTW(i-1,j)).
			dtwMatrix[i%2][j] = Euclidean::euclidean(q.getValueAt(i-1),p.getValueAt(j-1))
				+ std::min(dtwMatrix[thisI][j-1],std::min(dtwMatrix[prevI][j], dtwMatrix[prevI][j-1]));

		}

	}

	return dtwMatrix[q.getLength()%2][p.getLength()];

}/**/

void DTW::setWarpingRate(double warping) {
	DTW::warpingRate = std::min(std::max(warping,0.0),100.0);
}

double DTW::getWarpingRate() {
	return DTW::warpingRate;
}
