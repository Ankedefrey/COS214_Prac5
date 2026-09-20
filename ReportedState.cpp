#include "ReportedState.h"
#include "Incident.h"
#include <iostream>

// Reported: dispatchUnit -> ActiveState; contain and resolve are invalid

bool ReportedState::dispatchUnit(Incident* incident) {
	throw "Not yet implemented";
}

bool ReportedState::contain(Incident* incident) {
	throw "Not yet implemented";
}

bool ReportedState::resolve(Incident* incident) {
	throw "Not yet implemented";
}

string ReportedState::getName() {
	throw "Not yet implemented";
}
