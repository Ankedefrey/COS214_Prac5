#include "Zone.h"
#include "Room.h"
#include "SirenControlAdapter.h"

#include <iostream>

using namespace std;

Zone* buildCampus() {
	Zone* campus = new Zone("Campus");

	Zone* it = new Zone("IT Building");

	Zone* itF2 = new Zone("IT Floor 2");
	itF2->add(new Room("IT 2-23"));
	itF2->add(new Room("IT 2-26"));

	Zone* itF4 = new Zone("IT Floor 4");
	itF4->add(new Room("Server Room"));

	it->add(itF2);
	it->add(itF4);

	Zone* chem = new Zone("Chemistry Building");
	Zone* chemF1 = new Zone("Chemistry Floor 1");
	chemF1->add(new Room("Lab C1-10"));
	Zone* chemF2 = new Zone("Chemistry Floor 2");
	chemF2->add(new Room("Lab C2-14"));
	chemF2->add(new Room("Office C2-20"));
	chem->add(chemF1);
	chem->add(chemF2);

	campus->add(it);
	campus->add(chem);
	return campus;
}

SirenControlAdapter* buildSirens() {
	SirenControlAdapter* sirens = new SirenControlAdapter();
	sirens->mapArea("IT Building", 12);
	sirens->mapArea("Chemistry Building", 20);
	sirens->mapArea("Chemistry Floor 2", 22);
	sirens->mapArea("Server Room", 99);   // broken siren: hardware fault
	return sirens;
}

int main() {
    cout << "=== CampusGuard: Emergency Response Coordination ===" <<endl;

    Zone* campus = buildCampus();
	SirenControlAdapter* sirens = buildSirens();
	NotificationService* notifier = sirens;

    delete notifier; // virtual destructor -> ~SirenControlAdapter
	delete campus; // recursively deletes every zone and room

    return 0;
}