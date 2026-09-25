#include "ContainedState.h"
#include "ResolvedState.h"
#include "Incident.h"
#include <iostream>

// Contained: resolve -> ResolvedState; dispatchUnit and contain are invalid

bool ContainedState::dispatchUnit(Incident* incident) {
	std::cout << "Incident is contained, no need to dispatch unit" << std::endl;
	return false;
}

bool ContainedState::contain(Incident* incident) {
	std::cout << "Incident contained" << std::endl;
	incident->resolve();
	return true;
}

bool ContainedState::resolve(Incident* incident) {
	IncidentState* newState = new ResolvedState();
	incident->setState(newState);
	return true;
}

string ContainedState::getName() {
	return "Contained";
}
