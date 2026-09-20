#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

#include <string>
#include "ResponseUnit.h"

using namespace std;

class Incident;

class MedicalTeam : public ResponseUnit {

public:
	MedicalTeam(string unitID);

	virtual bool dispatch(Incident* incident);

	virtual string getType();
};

#endif
