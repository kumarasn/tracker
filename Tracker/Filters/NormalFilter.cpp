/*
 * NormalFilter.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "NormalFilter.h"

NormalFilter::NormalFilter() {
	// TODO Auto-generated constructor stub

}

NormalFilter::~NormalFilter() {
	// TODO Auto-generated destructor stub
}

fann_type* NormalFilter::applyFilter(IplImage *scr)
{


	int height = scr->height;
	int width  = scr->width;
    int step   = scr->widthStep;

    int i,j;

    uchar* data = (uchar *)scr ->imageData;

    fann_type input[4800];

	for (i= 0; i < height ; i++)
	   for (j= 0; j < width ; j++ )
		   input[i*width+j] = data[i*step+j]/255;



	return input;


}


