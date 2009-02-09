/*
 * NeuralNet.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "NeuralNet.h"

#include <sstream>
#include <fstream>
#include <iomanip>

NeuralNet::NeuralNet(LogHandler* logger) {
	// TODO Auto-generated constructor stub

	this->logger = logger;

	componentName = "NetHandler";

	totalFrames  = 0;

	totalTime = 0;
}

NeuralNet::~NeuralNet() {
	// TODO Auto-generated destructor stub

	fann_destroy(network);//check this!!

}


void NeuralNet::run(IplImage *scr)
{

	//Podemos tener varias redes y trabajar de manera conjunta, tipo voting-system

	timeperFrame = clock();

	if ( scr != NULL){

		input_values = normal_filter->applyFilter(scr);//Normalizo la Imagen


		output_values = fann_run(network,input_values);


		xCoord = output_values[0];
		yCoord = output_values[1];

	}

	totalTime = totalTime + ( clock() - timeperFrame);

	totalFrames++;

}

int NeuralNet::getYcoord()
{
	return yCoord;
}

int NeuralNet::getXcoord()
{
	return xCoord;
}


void NeuralNet::shutDown()
{

	std::string s;
	std::stringstream out;
	out << totalTime * 1.0 / totalFrames * 1.0;
	s = out.str();

	logger->addEntry(componentName,"Average time per Frame: " + s);

	fann_destroy(network);

}

bool NeuralNet::startNet()
{


	if ( netFile == "" ){

		logger->addEntry(componentName,"The Network file is not specified in the config file");

		return false;
	}


	network = fann_create_from_file(netFile.c_str());

	if ( network == NULL){

		logger->addEntry(componentName,"The Network file does not exist");
		return false;

	}


	normal_filter = new NormalFilter();

	input_values  = new fann_type[4800];

	output_values = new fann_type[2];

	xCoord = 0;
	yCoord = 0;

	logger->addEntry(componentName,"The Network was succesfully created from " + netFile);

	return true;
}








