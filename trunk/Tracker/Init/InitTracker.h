#include "../../CommonProject/InterfaceWorker/InitializerCreator.h"
#include "../../CommonProject/src/CoordsSaver.h"
#include "../../CommonProject/src/SystemInfo.h"



/*
 * InitTracker.h
 *
 *  Created on: 29/03/2009
 *      Author: Pablo
 */

#ifndef INITTRACKER_H_
#define INITTRACKER_H_

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
