/*
 * ImageUtilities.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#ifndef IMAGEUTILITIES_H_
#define IMAGEUTILITIES_H_

#include "cv.h"

class ImageUtilities {
public:
	ImageUtilities();
	virtual ~ImageUtilities();

	IplImage* putMarker(IplImage*,int,int);
	IplImage* drawBox(IplImage*,int,int);

};

#endif /* IMAGEUTILITIES_H_ */
