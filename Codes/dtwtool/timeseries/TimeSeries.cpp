/*
 * TimeSeries.cpp
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include "TimeSeries.h"

/*
 * This constructor initizalizes the time series with 0 observations and class label = -1.
 */
TimeSeries::TimeSeries() {
	setTimeSeries(std::vector<double>(0,0),-1.0);
}

/*
 * This constructor initizalizes the time series with n observations and class label = -1.
 */
TimeSeries::TimeSeries(int n) {
	setTimeSeries(std::vector<double>(n,0),-1.0);
}

/*
 * This constructor initizalizes the time series with 0 observations and a given class label.
 */
TimeSeries::TimeSeries(int n, int Y) {
	setTimeSeries(std::vector<double>(n,0),Y);
}

/*
 * This constructor initizalizes the time series with a pre-determined observations' values and class label = -1.
 */
TimeSeries::TimeSeries(std::vector<double> values) {
	setTimeSeries(values,-1.0);
}

/*
 * This constructor initizalizes the time series with a pre-determined observations' values and a given class label.
 */
TimeSeries::TimeSeries(std::vector<double> values, int Y) {
	setTimeSeries(values,Y);
}

/*
 * Sets the time series to a vector of given observations' values and a given class label.
 */
void TimeSeries::setTimeSeries(std::vector<double> values, int Y) {
	TimeSeries::seriesValues = values;
	TimeSeries::label = Y;
}

/*
 * Returns the observations' values of the time series.
 */
std::vector<double> TimeSeries::getSeriesValues() {
	return TimeSeries::seriesValues;
}

/*
 * Returns the class label of the time series.
 */
int TimeSeries::getLabel(){
	return TimeSeries::label;
}

/*
 * Returns the value of a given position/observation of the time series.
 */
double TimeSeries::getValueAt(int ind) {
	return TimeSeries::seriesValues[ind];
}

/*
 * Returns the length of the time series.
 */
int TimeSeries::getLength() {
	return TimeSeries::seriesValues.size();
}

/*
 * Prints time series values
 */
void TimeSeries::toString() {

	printf("TS values:\n");

	for (int i = 0; i < getLength(); i++) {

		if (i > 0) printf(" ");
		printf("%f", getValueAt(i));

	}

	printf("\n");

}
