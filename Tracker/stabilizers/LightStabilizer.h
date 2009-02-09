/*
 * LightStabilizer.h
 *
 *  Created on: 07-feb-2009
 *      Author: Timpa
 */

#ifndef LIGHTSTABILIZER_H_
#define LIGHTSTABILIZER_H_

#include "cv.h"
#include "highgui.h"

#include "..\Filters\filterHandler.h"

#include "..\Camera\CamHandler.h"

#include "..\Logger\LogHandler.h"


class LightStabilizer {
public:
	LightStabilizer(LogHandler*);
	virtual ~LightStabilizer();

	void runAmbientDiagnostic(CamHandler*,FilterHandler*);

    int getMax_frames_to_analize() const{return max_frames_to_analize;}

    void setMax_frames_to_analize(int max_frames_to_analize){this->max_frames_to_analize = max_frames_to_analize;}

    int getAverageSkinPixels() const{return averageSkinPixels;}

    int getSkinThreshold();
    float getThreshold_delta() const{return threshold_delta;}

    void setThreshold_delta(float threshold_delta){this->threshold_delta = threshold_delta;}

private:

	int max_frames_to_analize;

	int averageSkinPixels;

	int skinThreshold;

	float threshold_delta;

	std::string componentName;

	LogHandler* logger;
};

#endif /* LIGHTSTABILIZER_H_ */
