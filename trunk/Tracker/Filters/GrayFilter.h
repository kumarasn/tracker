/*
 * GrayFilter.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#ifndef GRAYFILTER_H_
#define GRAYFILTER_H_

#include "ImageFilter.h"

class GrayFilter: public ImageFilter {
public:
	GrayFilter();
	virtual ~GrayFilter();

	IplImage* applyFilter(IplImage*);

};

#endif /* GRAYFILTER_H_ */
