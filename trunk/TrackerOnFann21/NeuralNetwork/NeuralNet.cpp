/*
 * NeuralNet.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "NeuralNet.h"

NeuralNet::NeuralNet() {
	// TODO Auto-generated constructor stub

}

NeuralNet::~NeuralNet() {
	// TODO Auto-generated destructor stub

	fann_destroy(network);//check this!!

}


void NeuralNet::run(IplImage *scr)
{

	//Podemos tener varias redes y trabajar de manera conjunta, tipo voting-system

	if ( scr != NULL){

		input_values = normal_filter->applyFilter(scr);//Normalizo la Imagen


		output_values = fann_run(network,input_values);


		xCoord = output_values[0];
		yCoord = output_values[1];

	}

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
	//grabamos en el log el tiempo promedio de proceso, y demas

	fann_destroy(network);

}

bool NeuralNet::startNet()
{
	//si no podemos grabamos en el log

	if ( netFile == "" )//log
		return false;

	network = fann_create_from_file(netFile.c_str());

	normal_filter = new NormalFilter();

	input_values  = new fann_type[4800];

	output_values = new fann_type[2];

	xCoord = 0;
	yCoord = 0;

	return true;
}








