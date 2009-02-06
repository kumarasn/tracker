/*
 * SkinFilter.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "SkinFilter.h"



SkinFilter::SkinFilter() {
	// TODO Auto-generated constructor stub


	skinMaskFile = "Images\\skin.jpg";

}

SkinFilter::~SkinFilter() {
	// TODO Auto-generated destructor stub
}

IplImage *SkinFilter::applyFilter(IplImage *img)
{


	IplImage* imgHSV = cvCreateImage(cvSize (img->width, img->height), IPL_DEPTH_8U, 3);

	IplImage* ret = cvCreateImage(cvSize (img->width, img->height), IPL_DEPTH_8U, 1);


	//Cambiamos de modelo de color
	cvCvtColor(img,imgHSV,CV_BGR2HSV);


	IplImage* hue = cvCreateImage(cvSize (imgHSV->width, imgHSV->height), IPL_DEPTH_8U, 1);
	IplImage* sat = cvCreateImage(cvSize (imgHSV->width, imgHSV->height), IPL_DEPTH_8U, 1);
	IplImage* inte = cvCreateImage(cvSize (imgHSV->width, imgHSV->height), IPL_DEPTH_8U, 1);

	cvSplit(imgHSV, hue, sat, inte, 0);

	uchar* hue_data = (uchar *)hue ->imageData;
	uchar* sat_data = (uchar *)sat ->imageData;

	uchar* ret_data = (uchar *)ret ->imageData;


	for (int i= 0; i < imgHSV->height ; i++)
	  for (int j= 0; j < imgHSV->width ; j++ ){


		  int h = (int) hue_data[i*hue->widthStep+j];

		  int s = (int) sat_data[i*sat->widthStep+j];

		  if ( (h >= h_value - delta) && (h <= h_value + delta) && (s >= s_value - delta) && (s <= s_value + delta) )
			  ret_data[i*ret->widthStep+j] = 255;
		  else
			  ret_data[i*ret->widthStep+j] = 0;

	  }

	return ret;
}


void SkinFilter::skinValuesGetter(){


	IplImage* skinMask = cvLoadImage(skinMaskFile.c_str());

	IplImage* skinMaskHSV = cvCreateImage(cvSize (skinMask->width, skinMask->height), IPL_DEPTH_8U, 3);

	cvCvtColor(skinMask,skinMaskHSV,CV_BGR2HSV);


		IplImage* hue = cvCreateImage(cvSize (skinMaskHSV->width, skinMaskHSV->height), IPL_DEPTH_8U, 1);
		IplImage* sat = cvCreateImage(cvSize (skinMaskHSV->width, skinMaskHSV->height), IPL_DEPTH_8U, 1);
		IplImage* inte = cvCreateImage(cvSize(skinMaskHSV->width, skinMaskHSV->height), IPL_DEPTH_8U, 1);

		cvSplit(skinMaskHSV, hue, sat, inte, 0);

		uchar* hue_data =  (uchar *)hue ->imageData;
		uchar* sat_data =  (uchar *)sat ->imageData;
		uchar* inte_data = (uchar *)inte ->imageData;

		float h,s,v;
		h =0.0;
		s =0.0;
		v =0.0;

		int total = skinMaskHSV->height * skinMaskHSV->width;

		for (int i= 0; i < skinMaskHSV->height ; i++)
		  for (int j= 0; j < skinMaskHSV->width ; j++ ){


			  h = h + hue_data[i*hue->widthStep+j];

			  s = s + sat_data[i*sat->widthStep+j];

			  v = v+ inte_data[i*inte->widthStep+j];
		  }

		h_value = h/total;

		s_value = s/total;

}


