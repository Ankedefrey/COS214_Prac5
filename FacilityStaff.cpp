#include "FacilityStaff.h"
#include "Incident.h"
#include <iostream>

FacilityStaff::FacilityStaff(string unitID) : ResponseUnit(unitID) {
	
}

bool FacilityStaff::dispatch(Incident* incident) {
	//check if available
	if(!this->available){
		return false; //reporting to another incident
	}
	
	//reporting to this incident
	this->available = false;
	return true;
}

string FacilityStaff::getType() {
	return "FacilityStaff";
}
