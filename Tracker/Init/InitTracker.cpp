/*
 * InitTracker.cpp
 *
 *  Created on: 29/03/2009
 *      Author: Pablo
 */

#include "InitTracker.h"

#define _WIN32_WINNT 0x0501

#include "..\Camera\CamHandler.h"

#include "..\NeuralNetwork\NeuralNet.h"

#include "..\Filters\FilterHandler.h"

#include "..\Utils\ImageUtilities.h"

#include "..\ConfigurationHandler\ConfigHandler.h"

#include "..\stabilizers\LightStabilizer.h"

#include "..\Logger\LogHandler.h"

#include "iostream.h"

#include "cv.h"

#include <windows.h>


InitTracker::InitTracker(CoordsSaver* coordSaver, SystemInfo* sysInfo):InitializerCreator() {
	this->coordSaver = coordSaver;
	this->sysInfo = sysInfo;
}

InitTracker::~InitTracker() {
	;
}

int InitTracker::start()
{
	LogHandler               *logger = new LogHandler();

	ConfigHandler            *config = new ConfigHandler(logger);

	CamHandler                  *cam = new CamHandler(logger);

	NeuralNet                   *net = new NeuralNet(logger);

	LightStabilizer *lightStabilizer = new LightStabilizer(logger);

	FilterHandler     *filterHandler = new FilterHandler(logger);

	ImageUtilities             *util = new ImageUtilities();

	logger->initLogger();


	if ( !config->openConfigFile("config.data") ){

		logger->closeLogger();

		return -1;

	}

	if ( !cam->initCamDevice() ){

		logger->closeLogger();

		return -1;

	}


	net->setnetFile(config->getTrackerNetFile());

	if ( !net->startNet()){

		logger->closeLogger();

		return -1;

	}

	filterHandler->setSkinMaskFile(config->getSkinMaskFile());

	filterHandler->setSkinDelta(config->getSkinDelta());

	filterHandler->init();


	//Hand Diagnostic

	lightStabilizer->setThreshold_delta(config->getLightStabilizerThresholdDelta());

	lightStabilizer->runAmbientDiagnostic(cam,filterHandler);

	//End Hand Diagnostic


	filterHandler->setSkinThreshold(lightStabilizer->getSkinThreshold());

	std::string MainWindow = cam->getFirstWindow();

	std::string NetWindow = cam->getThirdWindow();

	int Xcoord,Ycoord,XcoordFIR,YcoordFIR;

	IplImage* Close = cvLoadImage("Images\\hand_close.jpg");

	IplImage* Open = cvLoadImage("Images\\hand_open.jpg");

	//int x_val, y_val,cx,cy;

	//sysInfo->getSystemRatio(x_val,y_val);

	//sysInfo->getSystemResolution(cx,cy);

	IplImage* currentFrame;

	IplImage* filteredImage;

	while ( cam->stillTracking() ){

		currentFrame = cam->retrieveFrame();

		filteredImage = filterHandler->runPreFilters(currentFrame);

		//Hand Tracker

		net->run(filteredImage);

		Xcoord = net->getXcoord();

		Ycoord = net->getYcoord();

		filterHandler->runLowPassFilter(Xcoord,Ycoord,XcoordFIR,YcoordFIR);

		util->putMarker(currentFrame,XcoordFIR*4,YcoordFIR*4);

		//SetCursorPos((cx - XcoordFIR * x_val) ,(cy - YcoordFIR * y_val) );
		coordSaver->saveCoords(XcoordFIR,YcoordFIR);

		cam->showFrame(NetWindow,filteredImage);

		cam->showFrame(MainWindow,currentFrame);

		//Static Gesture Recognition through skin pixel count

		if ( filterHandler->getSkinCount() > filterHandler->getSkinThreshold()){ // Mano Abierta: mas pixeles blancos

			cam->showFrame(cam->getSecondWindow(),Open);

			//mouse_event(MOUSEEVENTF_LEFTUP, XcoordFIR * x_val, cy - YcoordFIR * y_val, 0, 0);

		}

		else{

			//mouse_event(MOUSEEVENTF_LEFTDOWN, XcoordFIR * x_val, cy - YcoordFIR * y_val, 0, 0);

			cam->showFrame(cam->getSecondWindow(),Close);

		}


		cvReleaseImage( &filteredImage );

	}

	cam->stopCamDevice();

	net->shutDown();

	logger->closeLogger();

	return 0;

}


