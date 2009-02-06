/*
 * tracker.cpp
 *
 *  Created on: 04-feb-2009
 *      Author: Timpa
 */

#include "..\Camera\CamHandler.h"

#include "..\NeuralNetwork\GestureNeuralNet.h"

#include "..\NeuralNetwork\NeuralNet.h"

#include "..\Filters\FilterHandler.h"

#include "..\ImageUtils\ImageUtilities.h"

#include "..\ConfigurationHandler\ConfigHandler.h"

#include "iostream.h"

#include "cv.h"

int main() {


	ConfigHandler        *config = new ConfigHandler();
	CamHandler              *cam = new CamHandler();
	NeuralNet               *net = new NeuralNet();
	GestureNeuralNet *gestureNet = new GestureNeuralNet();
	FilterHandler *filterHandler = new FilterHandler();
	ImageUtilities *util         = new ImageUtilities();



	if ( !config->openConfigFile("config.data") )
		return -1;



	net->setnetFile(config->getTrackerNetFile());

	gestureNet->setnetFile(config->getGestureNetFile());

	gestureNet->setThreshold(config->getGestureThreshold());


	if ( !cam->initCamDevice() )
		return -1;


	if ( !net->startNet())
		return -1;

	if ( !gestureNet->startNet())
		return -1;




	std::string MainWindow = cam->getFirstWindow();

	int Xcoord,Ycoord,XcoordFIR,YcoordFIR;


	IplImage* Close = cvLoadImage("Images\\hand_close.jpg");
	IplImage* Open = cvLoadImage("Images\\hand_open.jpg");


	while ( cam->stillTracking() ){


		IplImage* currentFrame = cam->retrieveFrame();

		IplImage* filteredImage = filterHandler->runPreFilters(currentFrame);


		//Hand Tracker

		net->run(filteredImage);

		Xcoord = net->getXcoord();
		Ycoord = net->getYcoord();

		//filterHandler->runFIRfilter(Xcoord,Ycoord,XcoordFIR,YcoordFIR);

		filterHandler->runAverageSmoothing(Xcoord,Ycoord,XcoordFIR,YcoordFIR);

		util->putMarker(currentFrame,XcoordFIR*4,YcoordFIR*4);

		cam->showFrame(MainWindow,currentFrame);


		//Static Gesture Recognition

		gestureNet->run(filteredImage);

		if ( gestureNet->getHandGesture() == 1) // Mano cerrada
			cam->showFrame(cam->getSecondWindow(),Close);
		else
			cam->showFrame(cam->getSecondWindow(),Open);



	}


	cam->stopCamDevice();

	net->shutDown();



	return 0;
}
