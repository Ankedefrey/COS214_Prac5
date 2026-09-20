#include "ResolvedState.h"
#include "Incident.h"
#include <iostream>

// Resolved: every operation is invalid - print a clear message and return false

bool ResolvedState::dispatchUnit(Incident* incident) {
	throw "Not yet implemented";
}

bool ResolvedState::contain(Incident* incident) {
	throw "Not yet implemented";
}

bool ResolvedState::resolve(Incident* incident) {
	throw "Not yet implemented";
}

string ResolvedState::getName() {
	throw "Not yet implemented";
}
