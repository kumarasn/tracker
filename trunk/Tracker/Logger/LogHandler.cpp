/*
 * LogHandler.cpp
 *
 *  Created on: 05-feb-2009
 *      Author: Timpa
 */

#include "LogHandler.h"

LogHandler::LogHandler() {
	// TODO Auto-generated constructor stub

}

LogHandler::~LogHandler() {
	// TODO Auto-generated destructor stub
}

void LogHandler::initLogger()
{

	log.open("log.txt",ios::out);

    char dateStr [9];
    char timeStr [9];
	_strdate( dateStr);
	_strtime( timeStr );

	log << "log created on " << dateStr << " "<< timeStr << "\n" << "\n";

}

void LogHandler::addEntry(std::string component, std::string newEntry)
{

	log << "\n";

	if ( component != lastComponent ){

		lastComponent = component;
		log << "\n" << "--- " << component << " ---" << "\n";
	}

	log << "- " << newEntry;

	log << "\n";
}

void LogHandler::closeLogger()
{

	char dateStr [9];
    char timeStr [9];
	_strdate( dateStr);
	_strtime( timeStr );

	log << "\n"<<"log close on " << dateStr << " "<< timeStr;

	log.close();

}


