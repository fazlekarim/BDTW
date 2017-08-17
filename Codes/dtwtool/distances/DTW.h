/*
 * DTW.h
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include <algorithm>
#include <cmath>
#include <cstdio>

#include "../util/Util.h"
#include "../timeseries/TimeSeries.h"
#include "Euclidean.h"


#ifndef DTW_H_
#define DTW_H_

class DTW {
private:
	double warpingRate;

public:
	DTW();
	DTW(double warping);
	virtual ~DTW();

	static double dtw(TimeSeries p, TimeSeries q);
	static double dtw(TimeSeries p, TimeSeries q, double warping);

	void setWarpingRate(double warping);
	double getWarpingRate();

};

#endif /* DTW_H_ */
