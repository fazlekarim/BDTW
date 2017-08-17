/*
 * Util.cpp
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include "Util.h"

Util::Util() {
	// TODO Auto-generated constructor stub

}

Util::~Util() {
	// TODO Auto-generated destructor stub
}

int Util::getWarpingRadius(TimeSeries ts, double warpingRate) {
	return ceil(ts.getLength() * warpingRate);
}

int Util::getWarpingRadius(int tsLen, double warpingRate) {
	return ceil(tsLen * warpingRate);
}
