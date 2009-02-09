/*
 * SystemInfo.cpp
 *
 *  Created on: 08-feb-2009
 *      Author: Timpa
 */

#include "SystemInfo.h"

#include <sstream>
#include <fstream>
#include <iomanip>

SystemInfo::SystemInfo(LogHandler * logger) {
	// TODO Auto-generated constructor stub

	this->logger = logger;

}

SystemInfo::~SystemInfo() {
	// TODO Auto-generated destructor stub
}

void SystemInfo::init()
{
	 width = GetSystemMetrics(SM_CXSCREEN);

	 height = GetSystemMetrics(SM_CYSCREEN);

	 std::string s;
	 std::stringstream out;
	 out << width;
	 s = out.str();

	 std::string ss;
	 std::stringstream outt;
	 outt <<height;
	 ss = outt.str();

	 logger->addEntry("System Info", "System Resolution: " + s + " x " + ss );

}

void SystemInfo::getSystemResolution(int & x, int & y)
{

	 x = width ;

	 y = height ;


}

void SystemInfo::getSystemRatio(int &x ,int &y )
{

	x = width / 80 ;

	y = height / 60 ;

}






