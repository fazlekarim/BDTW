/*
 * Euclidean.cpp
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include "Euclidean.h"

Euclidean::Euclidean() {
	// TODO Auto-generated constructor stub

}

Euclidean::~Euclidean() {
	// TODO Auto-generated destructor stub
}

/**
 * The simple ED between two given observations/points
**/
double Euclidean::euclidean(double a, double b) {
  return (a-b)*(a-b);
}

/**
 * Squared ED between two time series
**/
double Euclidean::squared_euclidean(TimeSeries p, TimeSeries q) {

	double d = 0;

	if (p.getLength() != q.getLength()) {
		printf("ERROR: Both time series should have the same length in order to use Euclidean distance.\n");
		return -1.0;
	}

	for (int i = 0; i < (int) p.getLength(); i++)
		d += euclidean(p.getValueAt(i),q.getValueAt(i));

	return d;

}

/**
 * Regular ED between two time series
**/
double Euclidean::euclidean_root(TimeSeries p, TimeSeries q) {

	return sqrt(Euclidean::squared_euclidean(p, q));

}
