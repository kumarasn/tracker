/*
 * LightStabilizer.cpp
 *
 *  Created on: 07-feb-2009
 *      Author: Timpa
 */

#include "LightStabilizer.h"

#include <sstream>
#include <fstream>
#include <iomanip>

LightStabilizer::LightStabilizer(LogHandler* logger) {
	// TODO Auto-generated constructor stub

	this->logger = logger;

	componentName = "Light Stabilizer";

	threshold_delta = 0.20;
}

LightStabilizer::~LightStabilizer() {
	// TODO Auto-generated destructor stub
}

void LightStabilizer::runAmbientDiagnostic(CamHandler *cam,FilterHandler*filterHandler)
{
	/*/
	 * Capturamos una serie de frames y sacamos datos como la cantidad de pixeles
	 * similares al color de la piel y demas
	 */


/*	int totalSkinPixels = 0;

	int skinPixels;

	cvWaitKey(2000); //para estabilizar el lente

	for ( int i = 0; i < max_frames_to_analize; i++ ){

		IplImage *image = cvQueryFrame(cam->getCam());

		filterHandler->getSkinImage(image);

		skinPixels = filterHandler->getSkinCount();

		totalSkinPixels = totalSkinPixels + skinPixels;

	}

	averageSkinPixels = totalSkinPixels / max_frames_to_analize;
*/


	IplImage* image;

	averageSkinPixels = 0;


	cam->showFrame(cam->getFirstWindow(),cvLoadImage("Images\\showHandOpen.jpg",-1));

	cvWaitKey(-1);

	cam->retrieveFrame();

	image = cam->retrieveFrame();

	filterHandler->getSkinImage(image);

	int skinHandOpen = filterHandler->getSkinCount();


	cam->showFrame(cam->getSecondWindow(),image);


	cam->showFrame(cam->getFirstWindow(),cvLoadImage("Images\\showHandClose.jpg",-1));

	cvWaitKey(-1);


	image = cam->retrieveFrame();

	image = cam->retrieveFrame();

	filterHandler->getSkinImage(image);

	int skinHandClose = filterHandler->getSkinCount();



	float dif = skinHandOpen * 1.0 / skinHandClose * 1.0;

	if ( dif < 1.01 ){

		logger->addEntry(componentName,"Hand Analisis failed. Using proportional values");

		skinHandOpen = (skinHandOpen < skinHandClose )? skinHandClose : skinHandClose;

		skinHandClose = skinHandOpen * 0.75;

	}

	skinThreshold = ((skinHandOpen - skinHandClose)*threshold_delta) + skinHandClose -averageSkinPixels;


	std::string s;
	std::stringstream out;
	out << skinHandOpen;
	s = out.str();

	logger->addEntry(componentName,"Skin pixels in Open Hand: " + s);


	std::stringstream outt;
	outt << skinHandClose;
	s = outt.str();

	logger->addEntry(componentName,"Skin pixels in Close Hand: " + s);


	std::stringstream outtt;
	outtt << threshold_delta;
	s = outtt.str();

	logger->addEntry(componentName,"Threshold Delta " + s);


	std::stringstream outttt;
	outttt << skinThreshold;
	s = outttt.str();

	logger->addEntry(componentName,"Threshold " + s);


}

int LightStabilizer::getSkinThreshold()
{

	return skinThreshold;

}




