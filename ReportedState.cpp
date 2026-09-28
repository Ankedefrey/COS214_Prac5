#include "ReportedState.h"
#include "Incident.h"
#include "ActiveState.h"
#include <iostream>

using namespace std;


// Reported: dispatchUnit -> ActiveState; contain and resolve are invalid

bool ReportedState::dispatchUnit(Incident* incident) {
	cout << "[Incident #" << incident->getIncidentID() << "] Reported -> Active" << endl;
	incident->setState(new ActiveState());
	return true;
}

bool ReportedState::contain(Incident* incident) {
	std::cout << "[Incident #" << incident->getIncidentID() << "] Incident cannot be contained yet" << std::endl;
	return false;
}

bool ReportedState::resolve(Incident* incident) {
	std::cout << "[Incident #" << incident->getIncidentID() << "] Incident is not resolved yet" << std::endl;
	return false;
}

string ReportedState::getName() {
	return "Reported";
}
