#include "MedicalTeam.h"
#include "Incident.h"
#include <iostream>

MedicalTeam::MedicalTeam(string unitID) : ResponseUnit(unitID) {
	
}

bool MedicalTeam::dispatch(Incident* incident) {
	//check if available
	if(!this->available){
		return false; //reporting to another incident
	}
	
	//reporting to this incident
	this->available = false;
	return true;
}

string MedicalTeam::getType() {
	return "MedicalTeam";
}
