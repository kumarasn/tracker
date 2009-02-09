/*
 * ImageUtilities.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "ImageUtilities.h"

ImageUtilities::ImageUtilities() {
	// TODO Auto-generated constructor stub

}

ImageUtilities::~ImageUtilities() {
	// TODO Auto-generated destructor stub
}

IplImage *ImageUtilities::putMarker(IplImage *scr, int x, int y)
{

	cvLine(scr, cvPoint(x-10,y), cvPoint(x+10,y), cvScalar(0,255,0), 1);
	cvLine(scr, cvPoint(x,y-10), cvPoint(x,y+10), cvScalar(0,255,0), 1);

}


IplImage* ImageUtilities::drawBox(IplImage* frame,int x, int y){

		for ( int i = 0 ; i < 21 ; i++)

				cvLine(frame, cvPoint(x,y+i), cvPoint(x+20,y+i), cvScalar(0,255,0), 1);


		return frame;



	}
