/*
 * DataSet.cpp
 *
 * This class define a dataset and some operations over it.
 * Basically, we considered a dataset as a vector of time series.
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include "DataSet.h"

/*
 * Mounts the map that represent the indexes of class labels (to transform them t the interval [0..n-1])
 */
void DataSet::mountClassIndex() {

	// For each element in the dataset try to put it on map
	for (int i = 0; i < (int)data.size(); i++) {
		newLabel(data[i].getLabel());
	}

}

/*
 * Adds (if it does not exist) a label in the map
 */
void DataSet::newLabel(int label) {

	if (mapClassLabels.find(label) == mapClassLabels.end()) {
		mapClassLabels[label] = mapClassLabels.size()-1;
	}

}

/*
 * This constructor initizalizes the dataset with 0 examples
 */
DataSet::DataSet() {
	this->data = std::vector<TimeSeries>(0,0);
	this->mapClassLabels = std::map<int, int>();
}

/*
 * This constructor initizalizes the dataset with a given vector of time series.
 */
DataSet::DataSet(std::vector<TimeSeries> ds) {
	this->data = ds;
	mountClassIndex();
}

/*
 * Changes the content of dataset to a given vector of time series.
 */
void DataSet::setData(std::vector<TimeSeries> ds) {
	this->data = ds;
	this->mapClassLabels = std::map<int, int>();
	mountClassIndex();
}

/*
 * Returns the content of the dataset.
 */
std::vector<TimeSeries> DataSet::getData() {
	return data;
}

/*
 * Adds a time series after the last line of the dataset.
 */
void DataSet::addExample(TimeSeries ts) {
	data.push_back(ts);
	newLabel(ts.getLabel());
}

/*
 * Adds a vector of time series after the last line of the dataset.
 */
void DataSet::addExamples(std::vector<TimeSeries> examples) {

	data.insert(DataSet::data.end(),examples.begin(),examples.end());

	for (uint i = 0; i < examples.size(); i++)
		newLabel(examples[i].getLabel());

}

/*
 * Removes a time series in a given position of the dataset.
 */
void DataSet::removeExampleAt(int pos) {
	data.erase(DataSet::data.begin()+pos);
}

/*
 * Randomize the time series in the dataset
 */
void DataSet::randShuffle() {
	std::random_shuffle(data.begin(), data.end());
}

/*
 * Returns the time series stored in a given position of the dataset.
 */
TimeSeries DataSet::getTimeSeriesAt(int index) {
	return data[index];
}

/*
 * Returns the number of time series stored in the dataset.
 */
int DataSet::getSize() {
	return data.size();
}

/*
 * Cleans the dataset, i. e., the dataset becomes empty.
 */
void DataSet::clean() {
	data.clear();
}

/*
 * Cleans the dataset, i. e., the dataset becomes empty.
 */
void DataSet::clear() {
	DataSet::data.clear();
}
