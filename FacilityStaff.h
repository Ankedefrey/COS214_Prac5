#ifndef FACILITYSTAFF_H
#define FACILITYSTAFF_H

#include <string>
#include "ResponseUnit.h"

using namespace std;

class Incident;

class FacilityStaff : public ResponseUnit {

public:
	FacilityStaff(string unitID);

	virtual bool dispatch(Incident* incident);

	virtual string getType();
};

#endif
