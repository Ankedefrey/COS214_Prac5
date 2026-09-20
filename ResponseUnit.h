#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

#include <string>
#include "UnitEvent.h"

using namespace std;

class IncidentMediator;
class Incident;

class ResponseUnit {

protected:
	IncidentMediator* mediator;
	string unitID;
	bool available;

public:
	ResponseUnit(string unitID);

	void setMediator(IncidentMediator* i);

	bool isAvailable();

	virtual string getType() = 0;

	virtual bool dispatch(Incident* incident) = 0;

	void recall();

	void reportStatus(UnitEvent event, Incident* incident);

	virtual ~ResponseUnit();
};

#endif
