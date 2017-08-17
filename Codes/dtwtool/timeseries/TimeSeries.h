/*
 * TimeSeries.h
 *
 *  Created on: Jan 21, 2015
 *      AAuthor: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include <algorithm>
#include <cstdio>
#include <vector>

#ifndef TIMESERIES_H_
#define TIMESERIES_H_

class TimeSeries {
private:
	std::vector<double> seriesValues;	/*! Values of temporal measurements. */
	int label;								/*! Class label, if necessary. */

public:

	// This constructor initizalizes the time series with 0 observations and class label = -1.
	TimeSeries();
	// This constructor initizalizes the time series with n observations and class label = -1.
	TimeSeries(int n);
	// This constructor initizalizes the time series with 0 observations and a given class label.
	TimeSeries(int n, int Y);
	// This constructor initizalizes the time series with a pre-determined observations' values and class label = -1.
	TimeSeries(std::vector<double> values);
	// This constructor initizalizes the time series with a pre-determined observations' values and a given class label.
	TimeSeries(std::vector<double> values, int Y);

	virtual ~TimeSeries() {
		seriesValues.clear();
	}

	// Sets the time series to a vector of given observations' values and a given class label.
	void setTimeSeries(std::vector<double> values, int Y);

	// Returns the observations' values of the time series.
	std::vector<double> getSeriesValues();
	// Returns the class label of the time series.
	int getLabel();

	// Returns the value of a given position/observation of the time series.
	double getValueAt(int ind);
	// Returns the length of the time series.
	int getLength();

	// Prints time series values
	void toString();

};

#endif /* TIMESERIES_H_ */
