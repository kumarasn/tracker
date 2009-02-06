/*
 * CamHandler.h
 *
 *  Created on: 04-feb-2009
 *      Author: Timpa
 */

#ifndef CAMHANDLER_H_
#define CAMHANDLER_H_

#include "cv.h"
#include "highgui.h"

#include "stdio.h"
#include "iostream.h"


class CamHandler {
public:
	CamHandler();
	virtual ~CamHandler();

	bool initCamDevice();

	bool stillTracking();

	void stopCamDevice();

	void showFrame(std::string,IplImage*);

	IplImage* retrieveFrame();


    std::string getFirstWindow() const{return firstWindow;}

    void setFirstWindow(std::string firstWindow){this->firstWindow = firstWindow;}

    std::string getSecondWindow() const{return secondWindow;}

    void setSecondWindow(std::string secondWindow){this->secondWindow = secondWindow;}

private:

	CvCapture* capture;

	bool still_tracking;

	std::string firstWindow;

	std::string secondWindow;


};

#endif /* CAMHANDLER_H_ */
