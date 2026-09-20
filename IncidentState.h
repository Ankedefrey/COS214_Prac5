#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

#include <string>

using namespace std;

class Incident;

class IncidentState {

public:
	virtual bool dispatchUnit(Incident* incident) = 0;

	virtual bool contain(Incident* incident) = 0;

	virtual bool resolve(Incident* incident) = 0;

	virtual string getName() = 0;

	virtual ~IncidentState();
};

#endif
