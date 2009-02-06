/*
 * ConfigHandler.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "ConfigHandler.h"

ConfigHandler::ConfigHandler() {
	// TODO Auto-generated constructor stub

}

ConfigHandler::~ConfigHandler() {
	// TODO Auto-generated destructor stub
}

std::string ConfigHandler::getTrackerNetFile()
{

	return "NetDesktopSkin.net";

	//return "NetDesktopskin_23125.net"; //anda bien!

}



std::string ConfigHandler::getGestureNetFile()
{

	return "Net_Desktop_skin_Gesture_2096.net";


}

bool ConfigHandler::openConfigFile(std::string configFile)
{

	return true;

}

float ConfigHandler::getGestureThreshold()
{
	return 50.0;

}




