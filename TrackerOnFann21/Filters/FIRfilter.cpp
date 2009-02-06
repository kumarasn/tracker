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

	k_factor = 9;


	previousXValues = new float[15];
	previousYValues = new float[15];

	delta = 0.20;

}

FIRfilter::~FIRfilter() {
	// TODO Auto-generated destructor stub
}

void FIRfilter::runFIRfilter(int Xin, int Yin, int & Xout, int & Yout)

{

	Xout =  previous_Xvalues + delta * (Xin - previous_Xvalues );
	Yout =  previous_Yvalues + delta * (Yin - previous_Yvalues );


	previous_Xvalues = Xout;
	previous_Yvalues = Yout;




}

void shiftValues(float *values){

	for ( int i = 0; i < 14 ; i++)
		values[i] = values[i+1];

}


void FIRfilter::runAverageSmoothing(int Xin, int Yin, int & Xout, int & Yout)
{

	if ( active >= 15){

	Xout = previousXValues[14] + ( (Xin -previousXValues[14- k_factor])/ k_factor) ;
	Yout = previousYValues[14] + ( (Yin -previousYValues[14- k_factor])/ k_factor) ;

    shiftValues(previousXValues);
    shiftValues(previousYValues);

    previousXValues[14] = Xout;
    previousYValues[14] = Yout;


	}
	else{

		previousXValues[active] = Xin;
		previousYValues[active] = Yin;

		active++;


	}



}







