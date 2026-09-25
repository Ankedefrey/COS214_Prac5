#include "ResponseUnit.h"
#include "IncidentMediator.h"
#include "Incident.h"
#include <iostream>

ResponseUnit::ResponseUnit(string unitID) {
	this->unitID = unitID;
	this->available = true; //units all free until dispatched
	this->mediator = nullptr; //not yet registered with coordinator
}

void ResponseUnit::setMediator(IncidentMediator* i) {
	this->mediator = i;
}

bool ResponseUnit::isAvailable() {
	return this->available;
}

void ResponseUnit::recall() {
	//dispatch unit done with current incident
	this->available = true;
}

void ResponseUnit::reportStatus(UnitEvent event, Incident* incident) {
	//current unit reports to Mediator, and the coordinator (concreteMediator) 
	//decides what happens next.
	if (this->mediator != nullptr) {
        this->mediator->notify(this, event, incident);
    }
}

ResponseUnit::~ResponseUnit() {
}
