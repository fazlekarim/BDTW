/*
 * PrunedDTW.h
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include <algorithm>
#include <cmath>
#include <cstdio>

#include "../timeseries/TimeSeries.h"
#include "../util/Util.h"
#include "Euclidean.h"
#include "BDTW.h"

#ifndef PrunedDTW_H_
#define PrunedDTW_H_

class PrunedDTW {
private:
	double warpingRate;

public:
	PrunedDTW();
	PrunedDTW(double warping);
	virtual ~PrunedDTW();

	static double prunedDTW(TimeSeries p, TimeSeries q);
	static double prunedDTW(TimeSeries p, TimeSeries q, double warping);

	static double prunedDTW(TimeSeries p, TimeSeries q,
			double warping, double ub);

	void setWarpingRate(double warping);
	double getWarpingRate();

};

#endif /* PRUNEDDTW_H_ */
