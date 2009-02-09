/*
 * FilterHandler.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "FilterHandler.h"

#include "ImageFilter.h"


#include <sstream>
#include <fstream>
#include <iomanip>


// TODO Auto-generated constructor stub

FilterHandler::FilterHandler(LogHandler* logger) {

	 this->logger = logger;

	 componentName = "FilterHandler";

}

void FilterHandler::init(){

		filters_count = 3;

		prefilters = new ImageFilter[filters_count];

		filteredImages = new IplImage[filters_count+1];


		 gf  = new GrayFilter();

		 dsf = new DownSamplingFilter();

		 sf  = new SkinFilter();



		 sf->setSkinMaskFile(SkinMaskFile);

		 sf->setDelta(SkinDelta);


		 if ( !sf->skinValuesGetter() ){

			 logger->addEntry(componentName,"Failed to load Skin Mask. Using Default Values");
			 logger->addEntry(componentName,"Default Values--> Hue:11 -- Sat:106 -- Delta:42");

			 sf->seHValue(11);
			 sf->setSValue(106);
			 sf->setDelta(42);

		 }
		 else
		 {

			 logger->addEntry(componentName,"Skin Mask loaded succesfully");

			 std::string s;
			 std::stringstream out;
			 out << sf->getHValue();
		     s = out.str();

			 logger->addEntry(componentName,"Hue Value "  +s);


			 std::stringstream outt;
			 outt << sf->getSValue();
			 s = outt.str();

			 logger->addEntry(componentName,"Sat Value "  +s);



			 std::stringstream outtt;
			 outtt << sf->getDelta();
			 s = outtt.str();

			 logger->addEntry(componentName,"Hue Value "  +s);

		 }

		 ff = new FIRfilter();



}

FilterHandler::~FilterHandler() {
	// TODO Auto-generated destructor stub



}

IplImage *FilterHandler::runPreFilters(IplImage *scr)
{

	  first_filter  = sf->applyFilter(scr,skinCount);

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




void FilterHandler::runLowPassFilter(int Xin, int Yin, int &Xout, int &Yout)
{

	ff->runLowPassFilter(Xin,Yin,Xout,Yout);

}

void FilterHandler::runAverageSmoothing(int Xin, int Yin, int & Xout, int & Yout)
{

	ff->runAverageSmoothing(Xin,Yin,Xout,Yout);

}

IplImage *FilterHandler::getSkinImage(IplImage *scr)
{

	return sf->applyFilter(scr,skinCount);
}








