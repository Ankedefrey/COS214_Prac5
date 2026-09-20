#ifndef REPORTEDSTATE_H
#define REPORTEDSTATE_H

#include <string>
#include "IncidentState.h"

using namespace std;

class Incident;

class ReportedState : public IncidentState {

public:
	virtual bool dispatchUnit(Incident* incident);

	virtual bool contain(Incident* incident);

	virtual bool resolve(Incident* incident);

	virtual string getName();
};

#endif
