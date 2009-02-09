/*
 * tracker.cpp
 *
 *  Created on: 04-feb-2009
 *      Author: Timpa
 */


#define _WIN32_WINNT 0x0501

#include "..\Camera\CamHandler.h"

//#include "..\NeuralNetwork\GestureNeuralNet.h"

#include "..\NeuralNetwork\NeuralNet.h"

#include "..\Filters\FilterHandler.h"

#include "..\Utils\ImageUtilities.h"

#include "..\Utils\SystemInfo.h"

#include "..\ConfigurationHandler\ConfigHandler.h"

#include "..\stabilizers\LightStabilizer.h"

#include "..\Logger\LogHandler.h"

#include "iostream.h"

#include "cv.h"

#include <windows.h>

//#include "CoordBuffer.h"

int main() {


	LogHandler               *logger = new LogHandler();

	ConfigHandler            *config = new ConfigHandler(logger);
	CamHandler                  *cam = new CamHandler(logger);
	NeuralNet                   *net = new NeuralNet(logger);
	LightStabilizer *lightStabilizer = new LightStabilizer(logger);
	FilterHandler     *filterHandler = new FilterHandler(logger);
	ImageUtilities             *util = new ImageUtilities();
	SystemInfo              *sysInfo = new SystemInfo(logger);

	logger->initLogger();


	/*/
	 * INIT
	 */

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


	sysInfo->init();


	/*/
	 * this parameter is set in case we want to run a diagose in order to get
	 * light conditions, skin pixels, etc.
	 */
	//lightStabilizer->setMax_frames_to_analize(config->getMax_frames_to_analize());



	filterHandler->setSkinMaskFile(config->getSkinMaskFile());

	filterHandler->setSkinDelta(config->getSkinDelta());

	filterHandler->init();



	//Hand Diagnostic

	lightStabilizer->setThreshold_delta(config->getLightStabilizerThresholdDelta());

	lightStabilizer->runAmbientDiagnostic(cam,filterHandler);

	//End Hand Diagnostic



	filterHandler->setSkinThreshold(lightStabilizer->getSkinThreshold());


	std::string MainWindow = cam->getFirstWindow();

	int Xcoord,Ycoord,XcoordFIR,YcoordFIR;


	IplImage* Close = cvLoadImage("Images\\hand_close.jpg");
	IplImage* Open = cvLoadImage("Images\\hand_open.jpg");


	 int x_val, y_val,cx,cy;

	 sysInfo->getSystemRatio(x_val,y_val);

	 sysInfo->getSystemResolution(cx,cy);

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

		SetCursorPos(XcoordFIR * x_val ,(cy - YcoordFIR * y_val) );

	//	cam->showFrame(MainWindow,currentFrame);

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

		/*/
		 * The currentFrame can not be released, because it is in the
		 * capture buffer, and we can not release the entire buffer.
		 * Only the capture can be release, when the program ends.
		 */

	}


	cam->stopCamDevice();

	net->shutDown();

	logger->closeLogger();

	return 0;
}
