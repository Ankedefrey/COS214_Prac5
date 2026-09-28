#include "SecurityTeam.h"
#include "Incident.h"
#include <iostream>

SecurityTeam::SecurityTeam(string unitID) : ResponseUnit(unitID) {
	
}

bool SecurityTeam::dispatch(Incident* incident) {
	if (!this->available) {
		cout << "[Security] " << this->unitID << " is not available" << endl;
		return false;
	}

	//the incident's current state decides whether a dispatch is allowed
	if (!incident->dispatchUnit()) {
		cout << "[Security] " << this->unitID << " dispatch REFUSED by incident state" << endl;
		return false;
	}
	
	this->available = false;
	cout << "[Security] " << this->unitID << " dispatched to " << incident->getLocation() << endl;
	return true;
}


string SecurityTeam::getType() {
	return "SecurityTeam";
}
