#include "ActiveState.h"
#include "Incident.h"
#include "ContainedState.h"
#include <iostream>

// Active: dispatchUnit allowed (extra units); contain -> ContainedState; resolve is invalid

bool ActiveState::dispatchUnit(Incident* incident) {
	std::cout << "Unit dispatched" << std::endl;
	//Dispatch Unit
	incident->contain();
	throw "Not yet implemented";
}

bool ActiveState::contain(Incident* incident) {
	IncidentState* newState = new ContainedState();
	incident->setState(newState);
	incident->contain();
	return true;
}

bool ActiveState::resolve(Incident* incident) {
	std::cout << "Incident not resolved" << std::endl;
	return false;
}

string ActiveState::getName() {
	return "Active";
}
