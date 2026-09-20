#include "ContainedState.h"
#include "Incident.h"
#include <iostream>

// Contained: resolve -> ResolvedState; dispatchUnit and contain are invalid

bool ContainedState::dispatchUnit(Incident* incident) {
	throw "Not yet implemented";
}

bool ContainedState::contain(Incident* incident) {
	throw "Not yet implemented";
}

bool ContainedState::resolve(Incident* incident) {
	throw "Not yet implemented";
}

string ContainedState::getName() {
	throw "Not yet implemented";
}
