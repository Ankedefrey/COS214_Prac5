#ifndef SIRENCONTROLADAPTER_H
#define SIRENCONTROLADAPTER_H

#include <map>
#include <string>
#include "NotificationService.h"

using namespace std;

class SirenControlUnit;

class SirenControlAdapter : public NotificationService {

private:
	SirenControlUnit* sirenUnit;
	map<string, int> zoneCodes;

public:
	SirenControlAdapter();

	void mapArea(string areaName, int zoneCode);

	virtual bool sendAlert(string message, string areaName, bool urgent);

	virtual void clearAlert(string areaName);

	virtual ~SirenControlAdapter();
};

#endif
