#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include <string>
#include "ResponseUnit.h"

using namespace std;

class Incident;

class SecurityTeam : public ResponseUnit {

public:
	SecurityTeam(string unitID);

	virtual bool dispatch(Incident* incident);

	virtual string getType();
};

#endif
