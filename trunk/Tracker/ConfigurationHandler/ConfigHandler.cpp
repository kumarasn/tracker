/*
 * ConfigHandler.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "ConfigHandler.h"

ConfigHandler::ConfigHandler(LogHandler* logger) {
	// TODO Auto-generated constructor stub

	this->logger = logger;

	componenetName = "Configurator";

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

	std::string entry = "Config File: " + configFile + " loaded";

	logger->addEntry(componenetName,entry);

	return true;

}

float ConfigHandler::getGestureThreshold()
{
	return 50.0;

}


int ConfigHandler::getMax_frames_to_analize()
{

	return 20;

}

std::string ConfigHandler::getSkinMaskFile()
{

	return "Images\\skin.jpg";

}

float ConfigHandler::getLightStabilizerThresholdDelta()
{
	return 0.20; // es un valor para ver cuando paso de un estado de mano abierta a cerrada o viceversa

}

int ConfigHandler::getSkinDelta()
{

	int delta = 42;

	if ( delta == 0 ){
		logger->addEntry(componenetName,"El valor delta debe ser mayor a cero. Se uso el valor por defecto--> delta = 42");
		return 42;//es el valor del umbral para decidir si es piel o no
	}
	else
		return delta;

}














