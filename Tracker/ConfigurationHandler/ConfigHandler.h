/*
 * ConfigHandler.h
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#ifndef CONFIGHANDLER_H_
#define CONFIGHANDLER_H_

#include "stdio.h"
#include "iostream.h"

#include "..\Logger\LogHandler.h"

class ConfigHandler {
public:
	ConfigHandler(LogHandler*);
	virtual ~ConfigHandler();

	bool openConfigFile(std::string);

	std::string getTrackerNetFile();

	std::string getGestureNetFile();

	float getGestureThreshold();

	int getMax_frames_to_analize();

	std::string getSkinMaskFile();

	float getLightStabilizerThresholdDelta();

	int getSkinDelta();


private:

	LogHandler* logger;

	std::string componenetName;

	int SkinDelta;
};

#endif /* CONFIGHANDLER_H_ */
