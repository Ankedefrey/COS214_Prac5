#ifndef INCIDENTMEDIATOR_H
#define INCIDENTMEDIATOR_H

#include "UnitEvent.h"

class ResponseUnit;
class Incident;

class IncidentMediator {

public:
	virtual void notify(ResponseUnit* sender, UnitEvent event, Incident* incident) = 0;

	virtual ~IncidentMediator();
};

#endif
