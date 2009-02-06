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

class ConfigHandler {
public:
	ConfigHandler();
	virtual ~ConfigHandler();

	bool openConfigFile(std::string);

	std::string getTrackerNetFile();

	std::string getGestureNetFile();

	float getGestureThreshold();


};

#endif /* CONFIGHANDLER_H_ */
