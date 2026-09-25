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

//return true returns regardless of state->dispatchUnit(this) so added fix
bool Incident::dispatchUnit() {
	return state->dispatchUnit(this);
}

bool Incident::contain() {
	return state->contain(this);
}

bool Incident::resolve() {
	return state->resolve(this);
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

int Incident::getIncidentID() {
	return incidentID;
}

Incident::~Incident() {
	delete state;
	state = nullptr;
}
