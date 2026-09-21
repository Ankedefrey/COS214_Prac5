#include "Zone.h"
#include "Room.h"
#include "SirenControlAdapter.h"
#include <iostream>

int main() {
	Zone* campus = new Zone("Campus");
	Zone* it = new Zone("IT Building");
	Zone* floor2 = new Zone("IT Floor 2");
	floor2->add(new Room("IT 2-05"));
	it->add(new Room("IT 1-01"));
	it->add(floor2);
	campus->add(it);

	campus->find("IT Building")->lock();
	campus->find("IT Building")->unlock();
	cout << (campus->find("Nowhere") == NULL ? "find: missing OK" : "find: BROKEN") << endl;

	SirenControlAdapter* sirens = new SirenControlAdapter();
	sirens->mapArea("IT Building", 12);
	sirens->mapArea("Server Room", 99);
	sirens->sendAlert("Shelter in place", "IT Building", true);
	sirens->sendAlert("Shelter in place", "Server Room", true);
	sirens->sendAlert("Test", "Nowhere", false);
	sirens->clearAlert("IT Building");

	delete sirens;
	delete campus;
	return 0;
}