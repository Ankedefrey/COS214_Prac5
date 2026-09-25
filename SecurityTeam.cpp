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
	this->available = false;
	cout << "[Security] " << this->unitID << " dispatched to " << incident->getLocation() << endl;
	return true;
}


string SecurityTeam::getType() {
	return "SecurityTeam";
}
