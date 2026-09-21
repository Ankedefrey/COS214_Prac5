#include "ResolvedState.h"
#include "Incident.h"
#include <iostream>

// Resolved: every operation is invalid - print a clear message and return false

bool ResolvedState::dispatchUnit(Incident* incident) {
	std::cout << "Incident is resolved, no need to dispatch unit" << std::endl;
	return false;
}



bool ResolvedState::resolve(Incident* incident) {
	std::cout << "Incident is resolved" << std::endl;
	return true;
}

string ResolvedState::getName() {
	return "Resolved";
}
