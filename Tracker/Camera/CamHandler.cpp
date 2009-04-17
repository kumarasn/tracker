/*
 * CamHandler.cpp
 *
 *  Created on: 04-feb-2009
 *      Author: Timpa
 */

#include "CamHandler.h"
#include "iostream.h"


CamHandler::CamHandler(LogHandler* logger) {
	// TODO Auto-generated constructor stub

	firstWindow =  "Tracker Window";

	secondWindow = "Static Gesture Recognition";

	thirdWindow = "Net Input";

	still_tracking = false;


	this->logger = logger;

}

CamHandler::~CamHandler() {
	// TODO Auto-generated destructor stub

	stopCamDevice(); //check this!!

}

bool CamHandler::initCamDevice()
{

	componentName = "CamHandler";

	capture = cvCaptureFromCAM( CV_CAP_ANY );



	 if( !capture ) {

		 logger->addEntry(componentName,"There is not any available camera on your system");

		 return false;
	   }


	 //Para que la captura se realice a 320*240, estos valores tiene que definirse asi
	 double w = 288;
	 double h = 352;

     cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, w);

     cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, h);

     //Parece que no funciona
     cvSetCaptureProperty( capture, CV_CAP_PROP_POS_FRAMES, 25);


     cvNamedWindow( firstWindow.c_str(), CV_WINDOW_AUTOSIZE );
     cvNamedWindow( secondWindow.c_str(), CV_WINDOW_AUTOSIZE );

   //  if ( thirdWindow != 0)
    	 cvNamedWindow( thirdWindow.c_str(), CV_WINDOW_AUTOSIZE );

     logger->addEntry(componentName,"Camera started succefully");


	 return true;
}

bool CamHandler::stillTracking()
{

	 if( (cvWaitKey(10) & 255) == 27 )
		 return false;

	 return true;


}

void CamHandler::stopCamDevice()
{

	cvReleaseCapture( &capture );
	cvDestroyWindow( firstWindow.c_str() );
	cvDestroyWindow( secondWindow.c_str() );


}

void CamHandler::showFrame(std::string window,IplImage *frame)
{

	 cvShowImage( window.c_str(), frame );
}

IplImage *CamHandler::retrieveFrame()
{

	return cvQueryFrame( capture );

}






