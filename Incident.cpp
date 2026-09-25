#include "Incident.h"
#include "IncidentState.h"
#include "ReportedState.h"
#include "ResolvedState.h"
#include "ActiveState.h"
#include "ContainedState.h"

#include <iostream>

Incident::Incident(int id, string type, string location) {
	this->incidentID = id;
	this->type = type;
	this->location = location;
	this->state = new ReportedState();
}

bool Incident::dispatchUnit() {
	state->dispatchUnit(this);
	return true;
}

bool Incident::contain() {
	state->contain(this);
	return true;
}

bool Incident::resolve() {
	state->resolve(this);
	return true;
}

void Incident::setState(IncidentState* s) {
	// NOTE: the old state object must be deleted here, which is why
	// setState() must be the LAST statement in a state's method.
	if(state){ delete state;}
	this->state = s;
}

string Incident::getStatus() {
	return state->getName();
}

string Incident::getLocation() {
	return this->location;
}

Incident::~Incident() {
	delete state;
	state = nullptr;
}
