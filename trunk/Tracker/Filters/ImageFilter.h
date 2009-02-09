/*
 * ImageFilter.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#ifndef IMAGEFILTER_H_
#define IMAGEFILTER_H_

#include "cv.h"
#include "highgui.h"

class ImageFilter {
public:
	ImageFilter();
	virtual ~ImageFilter();

	IplImage* applyFilter(IplImage*);
};

#endif /* IMAGEFILTER_H_ */
