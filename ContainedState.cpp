#include "ContainedState.h"
#include "ResolvedState.h"
#include "Incident.h"
#include <iostream>

// Contained: resolve -> ResolvedState; dispatchUnit and contain are invalid

bool ContainedState::dispatchUnit(Incident* incident) {
	std::cout << "[Incident #" << incident->getIncidentID() << "] Incident is contained, no need to dispatch unit" << std::endl;
	return false;
}

bool ContainedState::contain(Incident* incident) {
	cout << "[Incident #" << incident->getIncidentID() << "] Incident is already contained" << endl;
	return false;
}

bool ContainedState::resolve(Incident* incident) {
	cout << "[Incident #" << incident->getIncidentID() << "] Contained -> Resolved" << endl;
	incident->setState(new ResolvedState());
	return true;
}

string ContainedState::getName() {
	return "Contained";
}
