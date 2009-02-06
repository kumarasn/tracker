/*
 * FilterHandler.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#ifndef FILTERHANDLER_H_
#define FILTERHANDLER_H_

#include "cv.h"

#include "ImageFilter.h"

#include "GrayFilter.h"
#include "DownSamplingFilter.h"
#include "SkinFilter.h"
#include "FIRfilter.h"

class FilterHandler {
public:
	FilterHandler();
	virtual ~FilterHandler();

	IplImage* runPreFilters(IplImage*);

	void runFIRfilter(int Xin,int Yin,int &Xout,int &Yout);

	void runAverageSmoothing (int Xin,int Yin,int &Xout,int &Yout);

private:

	ImageFilter *prefilters;

	IplImage* filteredImages;

	int filters_count;

	GrayFilter *gf;
	DownSamplingFilter *dsf;
	SkinFilter *sf;
	FIRfilter *ff;

	IplImage* first_filter;
	IplImage* second_filter;
	IplImage* third_filter;


};

#endif /* FILTERHANDLER_H_ */
