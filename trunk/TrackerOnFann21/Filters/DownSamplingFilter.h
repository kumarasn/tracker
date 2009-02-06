/*
 * DownSamplingFilter.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#ifndef DOWNSAMPLINGFILTER_H_
#define DOWNSAMPLINGFILTER_H_

#include "ImageFilter.h"

class DownSamplingFilter: public ImageFilter {
public:
	DownSamplingFilter();
	virtual ~DownSamplingFilter();

	IplImage* applyFilter(IplImage*);
};

#endif /* DOWNSAMPLINGFILTER_H_ */
