#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

using namespace std;

class IncidentState;

class Incident {

private:
	int incidentID;
	string type;
	string location;
	IncidentState* state;

public:
	Incident(int id, string type, string location);

	bool dispatchUnit();

	bool contain();

	bool resolve();

	void setState(IncidentState* s);

	string getStatus();

	string getLocation();

	int getIncidentID() { return incidentID; }

	~Incident();
};

#endif
