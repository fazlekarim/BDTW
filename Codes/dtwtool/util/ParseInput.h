/*
 * ParseInput.h
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include <fstream>
#include <vector>

#include "../timeseries/DataSet.h"
#include "../timeseries/TimeSeries.h"

#ifndef PARSEINPUT_H_
#define PARSEINPUT_H_

class ParseInput {
private:
	int classIndex;
	std::ifstream fin;

public:

	ParseInput();
	ParseInput(int classInd);

	virtual ~ParseInput() {
		classIndex = 0;
	}

	void setClassIndex(int index);
	int getClassIndex();

	// Parse the file considering no label in the data
	static bool doParse(DataSet &ds, char* fileToRead);

	// Parse the file considering the label in the column classInd (first column, classInd = 0)
	static bool doParse(DataSet &ds, char* fileToRead, int classInd);

};

#endif /* PARSEINPUT_H_ */
