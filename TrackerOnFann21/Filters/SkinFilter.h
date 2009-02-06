/*
 * SkinFilter.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#ifndef SKINFILTER_H_
#define SKINFILTER_H_

#include "ImageFilter.h"
#include "cv.h"

#include "iostream"

class SkinFilter: public ImageFilter {
public:
	SkinFilter();
	virtual ~SkinFilter();

	IplImage* applyFilter(IplImage*);

    int getDelta() const{return delta;}

    void setDelta(int delta){this->delta = delta;}

    int getHValue() const{return h_value;}

    void seHValue(int h_value){this->h_value = h_value;}

    int getSValue() const{return s_value;}

    void setSValue(int s_value){this->s_value = s_value;}

    void skinValuesGetter();

    std::string getSkinMaskFile() const{return skinMaskFile;}

    void setSkinMaskFile(std::string skinMaskFile){this->skinMaskFile = skinMaskFile;}

private:

	int delta;

	int h_value;
	int s_value;

	std::string skinMaskFile;




};

#endif /* SKINFILTER_H_ */
