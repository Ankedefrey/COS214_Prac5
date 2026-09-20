#include "IncidentCoordinator.h"
#include "ResponseUnit.h"
#include "Incident.h"
#include "AreaComponent.h"
#include "NotificationService.h"
#include <iostream>

IncidentCoordinator::IncidentCoordinator(AreaComponent* campus, NotificationService* notifier) {
	throw "Not yet implemented";
}

void IncidentCoordinator::notify(ResponseUnit* sender, UnitEvent event, Incident* incident) {
	throw "Not yet implemented";
}

void IncidentCoordinator::registerUnit(ResponseUnit* respUnit) {
	throw "Not yet implemented";
}

Incident* IncidentCoordinator::createIncident(string type, string location) {
	throw "Not yet implemented";
}

ResponseUnit* IncidentCoordinator::findAvailableUnit(string unitType) {
	throw "Not yet implemented";
}

IncidentCoordinator::~IncidentCoordinator() {
}
