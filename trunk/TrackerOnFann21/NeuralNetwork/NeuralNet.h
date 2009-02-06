/*
 * NeuralNet.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#ifndef NEURALNET_H_
#define NEURALNET_H_

#include "cv.h"


#include "..\Filters\NormalFilter.h"

#include "fann.h"

#include "iostream.h"

class NeuralNet {
public:
	NeuralNet();
	virtual ~NeuralNet();

	void run(IplImage*);
	int getXcoord();
	int getYcoord();
	bool startNet();
	void shutDown();

    std::string getnetFile() const{return netFile;}

    void setnetFile(std::string NetFile){this->netFile = NetFile;}

private:

	std::string netFile;

	struct fann *network;

	fann_type *output_values;

	fann_type *input_values;

	NormalFilter *normal_filter;

	int xCoord;

	int yCoord;

};

#endif /* NEURALNET_H_ */
