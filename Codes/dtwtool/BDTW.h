/*
 * Euclidean.h
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include <cmath>
#include <cstdio>

#include "../timeseries/TimeSeries.h"

#ifndef EUCLIDEAN_H_
#define EUCLIDEAN_H_

class Euclidean {
public:
	Euclidean();
	virtual ~Euclidean();

	// Squared ED between two time series
	static double squared_euclidean(TimeSeries p, TimeSeries q);

	// Regular ED between two time series
	static double euclidean_root(TimeSeries p, TimeSeries q);

	// The simple ED between two given observations/points
	static double euclidean(double a, double b);

};

#endif /* EUCLIDEAN_H_ */
