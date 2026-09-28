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

	if (!incident->dispatchUnit()) {
		cout << "[Facilities] " << this->unitID << " dispatch REFUSED by incident state" << endl;
		return false;
	}
	
	//reporting to this incident
	this->available = false;
	return true;
}

string FacilityStaff::getType() {
	return "FacilityStaff";
}
