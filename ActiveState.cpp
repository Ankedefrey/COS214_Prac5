#include "ActiveState.h"
#include "Incident.h"
#include <iostream>

// Active: dispatchUnit allowed (extra units); contain -> ContainedState; resolve is invalid

bool ActiveState::dispatchUnit(Incident* incident) {
	throw "Not yet implemented";
}

bool ActiveState::contain(Incident* incident) {
	throw "Not yet implemented";
}

bool ActiveState::resolve(Incident* incident) {
	throw "Not yet implemented";
}

string ActiveState::getName() {
	throw "Not yet implemented";
}
