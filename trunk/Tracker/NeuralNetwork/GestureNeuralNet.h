/*
 * GestureNeuralNet.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#ifndef GESTURENEURALNET_H_
#define GESTURENEURALNET_H_


#include "cv.h"


#include "..\Filters\NormalFilter.h"

#include "fann.h"

#include "iostream.h"

class GestureNeuralNet {
public:
	GestureNeuralNet();
	virtual ~GestureNeuralNet();

	void run(IplImage*);
	bool startNet();
	void shutDown();

	int getHandGesture();

    float getThreshold() const{return threshold;}

    void setThreshold(float threshold){this->threshold = threshold;}

    std::string getnetFile() const{return netFile;}

	void setnetFile(std::string NetFile){this->netFile = NetFile;}


private:

	std::string netFile;

	struct fann *network;

	fann_type *output_values;

	fann_type *input_values;

	NormalFilter *normal_filter;

	int handGesture;

	float threshold;

};

#endif /* GESTURENEURALNET_H_ */
