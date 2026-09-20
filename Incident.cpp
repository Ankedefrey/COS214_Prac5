#include "Incident.h"
#include "IncidentState.h"
#include "ReportedState.h"
#include <iostream>

Incident::Incident(int id, string type, string location) {
	throw "Not yet implemented";
}

bool Incident::dispatchUnit() {
	throw "Not yet implemented";
}

bool Incident::contain() {
	throw "Not yet implemented";
}

bool Incident::resolve() {
	throw "Not yet implemented";
}

void Incident::setState(IncidentState* s) {
	// NOTE: the old state object must be deleted here, which is why
	// setState() must be the LAST statement in a state's method.
	this->state = s;
}

string Incident::getStatus() {
	throw "Not yet implemented";
}

string Incident::getLocation() {
	return this->location;
}

Incident::~Incident() {
}
