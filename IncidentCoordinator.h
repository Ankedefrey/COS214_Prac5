#ifndef INCIDENTCOORDINATOR_H
#define INCIDENTCOORDINATOR_H

#include <vector>
#include <string>
#include "IncidentMediator.h"

using namespace std;

class ResponseUnit;
class Incident;
class AreaComponent;
class NotificationService;

class IncidentCoordinator : public IncidentMediator {

private:
	vector<ResponseUnit*> units;
	vector<Incident*> incidents;
	AreaComponent* campus;
	NotificationService* notifier;

public:
	IncidentCoordinator(AreaComponent* campus, NotificationService* notifier);

	virtual void notify(ResponseUnit* sender, UnitEvent event, Incident* incident);

	void registerUnit(ResponseUnit* respUnit);

	Incident* createIncident(string type, string location);

	ResponseUnit* findAvailableUnit(string unitType);

	virtual ~IncidentCoordinator();
};

#endif
