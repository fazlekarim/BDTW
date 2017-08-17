/*
 * Euclidean.h
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include <cmath>
#include <cstdio>
#include <vector>


#include "../timeseries/TimeSeries.h"

#ifndef BDTW_H_
#define BDTW_H_

class BDTW {
public:
	BDTW();
	virtual ~BDTW();

	// Squared ED between two time series
	static double dtw_ub_all(TimeSeries x, TimeSeries y, double warping);

	// Regular ED between two time series
	static double dtw_ub(double** x2, double** y2);

	// The simple ED between two given observations/points
	static double** bdtw_runs(TimeSeries x);

};

#endif /* EUCLIDEAN_H_ */
