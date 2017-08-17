/*
 * Util.h
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include "../timeseries/TimeSeries.h"
#include <cmath>

#ifndef UTIL_H_
#define UTIL_H_

class Util {

public:
	Util();
	virtual ~Util();

	static int getWarpingRadius(TimeSeries ts, double warpingRate);
	static int getWarpingRadius(int tsLen, double warpingRate);

};;

#endif /* UTIL_H_ */
