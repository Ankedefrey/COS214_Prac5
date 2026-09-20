#ifndef CONTAINEDSTATE_H
#define CONTAINEDSTATE_H

#include <string>
#include "IncidentState.h"

using namespace std;

class Incident;

class ContainedState : public IncidentState {

public:
	virtual bool dispatchUnit(Incident* incident);

	virtual bool contain(Incident* incident);

	virtual bool resolve(Incident* incident);

	virtual string getName();
};

#endif
