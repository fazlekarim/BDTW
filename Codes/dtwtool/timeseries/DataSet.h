/*
 * DataSet.h
 *
 * This class define a dataset and some operations over it.
 * Basically, we considered a dataset as a vector of time series.
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */


#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include "TimeSeries.h"

#ifndef DATASET_H_
#define DATASET_H_

class DataSet {
private:
	std::vector<TimeSeries> data; /*! A vector of time series that describes each line of the dataset. */
	std::map<int,int> mapClassLabels; /* To map the labels to the range [0..n-1] */

	// Mounts the map that represent the indexes of class labels (to transform them to the interval [0..n-1])
	void mountClassIndex();

	// Adds (if it does not exist) a label in the map
	void newLabel(int label);

public:

	// This constructor initizalizes the dataset with 0 examples.
	DataSet();
	// This constructor initizalizes the dataset with a given vector of time series.
	DataSet(std::vector<TimeSeries> ds);

	virtual ~DataSet() {
		data = std::vector<TimeSeries>(0,0);
		mapClassLabels = std::map<int,int>();
	}

	// Changes the content of dataset to a given vector of time series.
	void setData(std::vector<TimeSeries> ds);
	// Returns the content of the dataset.
	std::vector<TimeSeries> getData();

	// Adds a time series after the last line of the dataset.
	void addExample(TimeSeries ts);
	// Adds a vector of time series after the last line of the dataset.
	void addExamples(std::vector<TimeSeries> ts);

	// Removes a time series in a given position of the dataset.
	void removeExampleAt(int pos);

	// Randomize the time series in the dataset
	void randShuffle();

	// Returns the time series stored in a given position of the dataset.
	TimeSeries getTimeSeriesAt(int index);
	// Returns the number of time series stored in the dataset.
	int getSize();

	// Returns the map that represents the indexes of class labels
	std::map<int, int> getMapClassLabels() {
		return mapClassLabels;
	}


	// Cleans the dataset, i. e., the dataset becomes empty.
	void clean();
	void clear();

};

#endif /* DATASET_H_ */
