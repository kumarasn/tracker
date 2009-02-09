/*
 * DownSamplingFilter.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "DownSamplingFilter.h"

DownSamplingFilter::DownSamplingFilter() {
	// TODO Auto-generated constructor stub

}

DownSamplingFilter::~DownSamplingFilter() {
	// TODO Auto-generated destructor stub
}

IplImage *DownSamplingFilter::applyFilter(IplImage* scr)
{

	IplImage* dsImg = cvCreateImage (cvSize (cvRound (scr->width/2),cvRound (scr->height/2)),8, 1);

	cvPyrDown( scr, dsImg,CV_GAUSSIAN_5x5 );

	IplImage* ret = cvCreateImage (cvSize (cvRound (dsImg->width/2),cvRound (dsImg->height/2)),8, 1);

	cvPyrDown( dsImg, ret,CV_GAUSSIAN_5x5 );

	cvReleaseImage( &dsImg );

	return ret;


}


