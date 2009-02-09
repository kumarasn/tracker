/*
 * NormalFilter.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#ifndef NORMALFILTER_H_
#define NORMALFILTER_H_


#include "fann.h"

#include "cv.h"

class NormalFilter {
public:
	NormalFilter();
	virtual ~NormalFilter();

	fann_type* applyFilter(IplImage*);

};

#endif /* NORMALFILTER_H_ */
