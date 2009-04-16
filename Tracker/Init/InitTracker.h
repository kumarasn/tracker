
/*
 * InitTracker.h
 *
 *  Created on: 29/03/2009
 *      Author: Pablo
 */

#ifndef INITTRACKER_H_
#define INITTRACKER_H_

#include "../../CommonProject/src/CoordsSaver.h"
#include "../../CommonProject/src/SystemInfo.h"
#include "../../CommonProject/src/CoordsSaver.cpp"
#include "../../CommonProject/src/SystemInfo.cpp"
#include "../../CommonProject/InterfaceWorker/InitializerCreator.h"
#include "../../CommonProject/InterfaceWorker/InitializerCreator.cpp"
#include "../../CommonProject/src/Buffer_PC.h"
#include "../../CommonProject/src/Buffer_PC.cpp"

class InitTracker:public InitializerCreator {
public:
	InitTracker(CoordsSaver*,SystemInfo*);
	virtual ~InitTracker();
	int start();
private:
	CoordsSaver* coordSaver;
	SystemInfo* sysInfo;
};

#endif /* INITTRACKER_H_ */
