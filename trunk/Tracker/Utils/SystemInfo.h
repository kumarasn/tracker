/*
 * SystemInfo.h
 *
 *  Created on: 08-feb-2009
 *      Author: Timpa
 */

#ifndef SYSTEMINFO_H_
#define SYSTEMINFO_H_

#include "..\Logger\LogHandler.h"

#include <windows.h>

class SystemInfo {
public:
	SystemInfo(LogHandler*);
	virtual ~SystemInfo();

	void init();

	void getSystemResolution(int&,int&);

	void getSystemRatio(int&,int&);



private:

	LogHandler *logger;

	int width;

	int height;
};

#endif /* SYSTEMINFO_H_ */
