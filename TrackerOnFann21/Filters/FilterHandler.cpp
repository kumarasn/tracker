/*
 * FilterHandler.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "FilterHandler.h"

#include "ImageFilter.h"




FilterHandler::FilterHandler() {
	// TODO Auto-generated constructor stub


	filters_count = 3;

	prefilters = new ImageFilter[filters_count];

	filteredImages = new IplImage[filters_count+1];


	 gf  = new GrayFilter();

	 dsf = new DownSamplingFilter();

	 sf  = new SkinFilter();

	 sf->seHValue(11);
	 sf->setSValue(106);
	 sf->setDelta(42);

	 ff = new FIRfilter();


}

FilterHandler::~FilterHandler() {
	// TODO Auto-generated destructor stub
}

IplImage *FilterHandler::runPreFilters(IplImage *scr)
{

	  first_filter  = sf->applyFilter(scr);

	  second_filter = dsf->applyFilter(first_filter);



	return second_filter;



	/*
	filteredImages[0] = *scr;

	for ( int i = 0 ; i < filters_count; i ++){



			IplImage *img    = &filteredImages[i];

			IplImage *imgret = prefilters[i].applyFilter(img);

			filteredImages[i+1] = *imgret;

	}

	return &filteredImages[filters_count+1];*/

}

void FilterHandler::runFIRfilter(int Xin, int Yin, int &Xout, int &Yout)
{

	ff->runFIRfilter(Xin,Yin,Xout,Yout);

}

void FilterHandler::runAverageSmoothing(int Xin, int Yin, int & Xout, int & Yout)
{

	ff->runAverageSmoothing(Xin,Yin,Xout,Yout);

}






