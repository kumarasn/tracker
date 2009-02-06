/*
 * GestureNeuralNet.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "GestureNeuralNet.h"

GestureNeuralNet::GestureNeuralNet() {
	// TODO Auto-generated constructor stub

}

GestureNeuralNet::~GestureNeuralNet() {
	// TODO Auto-generated destructor stub

	fann_destroy(network);//check this!!

}


void GestureNeuralNet::run(IplImage *scr)
{

	//Podemos tener varias redes y trabajar de manera conjunta, tipo voting-system

	if ( scr != NULL){

		input_values = normal_filter->applyFilter(scr);//Normalizo la Imagen


		output_values = fann_run(network,input_values);


		float res = output_values[0];

		if ( res > threshold)
			handGesture = 1;
		else
			handGesture = 0;


	}

}


void GestureNeuralNet::shutDown()
{
	//grabamos en el log el tiempo promedio de proceso, y demas

	fann_destroy(network);

}

bool GestureNeuralNet::startNet()
{
	//si no podemos grabamos en el log

	if ( netFile == "" )//log
		return false;

	network = fann_create_from_file(netFile.c_str());

	normal_filter = new NormalFilter();

	input_values  = new fann_type[4800];

	output_values = new fann_type[1];

	return true;
}

int GestureNeuralNet::getHandGesture()
{
	return handGesture;

}




