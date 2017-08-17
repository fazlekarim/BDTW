/*
 * ParseInput.cpp
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include "ParseInput.h"

ParseInput::ParseInput() {
	classIndex = 0;
}

ParseInput::ParseInput(int classInd) {
	classIndex = classInd;
}

void ParseInput::setClassIndex(int index) {
	ParseInput::classIndex = index;
}

int ParseInput::getClassIndex() {
	return ParseInput::classIndex;
}

/*
 * Parse the file considering no label in the data
 */
bool ParseInput::doParse(DataSet &ds, char* fileToRead) {
	return doParse(ds, fileToRead, -1);
}

/*
 * Parse the file considering the label in the column classInd (first column, classInd = 0)
 */
bool ParseInput::doParse(DataSet &ds, char* fileToRead, int classInd) {

	int auxLabel = -1;
	char* auxLine;
	double auxVal;
	std::vector<double> auxTS;
	std::ifstream fin (fileToRead);
	int offset;
	std::string line;

	ds.clean();

	if (fin.is_open()) {

		while ( getline(fin, line, '\n') ) {

			auxLine = (char *)line.c_str();
			auxTS.clear();

			int i = 0;
			while(sscanf(auxLine, " %lf%n ", &auxVal, &offset) == 1) {

				if (i != classInd)
					auxTS.push_back(auxVal);
				else
					auxLabel = auxVal;

				auxLine += offset;
				i++;

			}

			// insert this example in the dataset
			ds.addExample(TimeSeries(auxTS, auxLabel));

		}

		fin.close();

	} else {

		printf("Error opening file.\n");
		return false;

	}


	return true;

}


