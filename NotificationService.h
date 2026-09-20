#ifndef NOTIFICATIONSERVICE_H
#define NOTIFICATIONSERVICE_H

#include <string>

using namespace std;

class NotificationService {

public:
	virtual bool sendAlert(string message, string areaName, bool urgent) = 0;

	virtual void clearAlert(string areaName) = 0;

	virtual ~NotificationService();
};

#endif
