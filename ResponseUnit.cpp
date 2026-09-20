#include "ResponseUnit.h"
#include "IncidentMediator.h"
#include "Incident.h"
#include <iostream>

ResponseUnit::ResponseUnit(string unitID) {
	throw "Not yet implemented";
}

void ResponseUnit::setMediator(IncidentMediator* i) {
	this->mediator = i;
}

bool ResponseUnit::isAvailable() {
	return this->available;
}

void ResponseUnit::recall() {
	throw "Not yet implemented";
}

void ResponseUnit::reportStatus(UnitEvent event, Incident* incident) {
	throw "Not yet implemented";
}

ResponseUnit::~ResponseUnit() {
}
