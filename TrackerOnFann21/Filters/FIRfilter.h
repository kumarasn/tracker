/*
 * FIRfilter.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#ifndef FIRFILTER_H_
#define FIRFILTER_H_



class FIRfilter{
public:
	FIRfilter();
	virtual ~FIRfilter();

	void runFIRfilter(int Xin,int Yin,int &Xout,int &Yout);

	void runAverageSmoothing(int Xin,int Yin,int &Xout,int &Yout);


private:

	float previous_Xvalues;
	float previous_Yvalues;

	float delta;


	float *previousXValues;
	float *previousYValues;

	int active;

	int k_factor;



};

#endif /* FIRFILTER_H_ */
