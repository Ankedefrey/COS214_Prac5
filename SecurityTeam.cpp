#include "SecurityTeam.h"
#include "Incident.h"
#include <iostream>

SecurityTeam::SecurityTeam(string unitID) : ResponseUnit(unitID) {
	
}

bool SecurityTeam::dispatch(Incident* incident) {
	//check if available
	if(!this->available){
		return false; //reporting to another incident
	}
	
	//reporting to this incident
	this->available = false;
	return true;
}

string SecurityTeam::getType() {
	return "SecurityTeam";
}
