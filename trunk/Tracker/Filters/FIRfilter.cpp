/*
 * FIRfilter.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "FIRfilter.h"

FIRfilter::FIRfilter() {
	// TODO Auto-generated constructor stub

	previous_Xvalues = 0;
	previous_Yvalues = 0;

	active =0;


	k_factor = 1;//OJO: tiene que ser menor o igual a frameWindow

	frameWindow = 5; // ventana de analisis


	previousXValues = new float[frameWindow];
	previousYValues = new float[frameWindow];

	delta = 0.20;



}

FIRfilter::~FIRfilter() {
	// TODO Auto-generated destructor stub
}

void FIRfilter::runLowPassFilter(int Xin, int Yin, int & Xout, int & Yout)

{

	/*/
	 * tags: Low-pass filter, wikipedia
	 *
	 */

	Xout =  previous_Xvalues + delta * (Xin - previous_Xvalues );
	Yout =  previous_Yvalues + delta * (Yin - previous_Yvalues );


	previous_Xvalues = Xout;
	previous_Yvalues = Yout;




}

void shiftValues(float *values,int frameWindow){

	for ( int i = 0; i < frameWindow -1 ; i++)
		values[i] = values[i+1];

}


void FIRfilter::runAverageSmoothing(int Xin, int Yin, int & Xout, int & Yout)
{


	/*/
	 * tags: Exponential smoothing, wikipedia
	 *
	 */

	if ( active >= frameWindow){

	Xout = previousXValues[frameWindow-1] + ( (Xin -previousXValues[frameWindow-1 - k_factor])/ k_factor) ;
	Yout = previousYValues[frameWindow-1] + ( (Yin -previousYValues[frameWindow-1 - k_factor])/ k_factor) ;

    shiftValues(previousXValues,frameWindow);
    shiftValues(previousYValues,frameWindow);

    previousXValues[frameWindow-1] = Xout;
    previousYValues[frameWindow-1] = Yout;


	}
	else{

		previousXValues[active] = Xin;
		previousYValues[active] = Yin;

		active++;


	}



}







