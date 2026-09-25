#include "Zone.h"
#include "Room.h"
#include "SirenControlAdapter.h"
#include "IncidentCoordinator.h"
#include "OperatorConsole.h"
#include "EmergencyFacade.h"
#include "Incident.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilityStaff.h"
#include "DispatchUnitOnCommand.h"
#include "IssueAlertOnCommand.h"

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

void banner(string title) {
	cout << endl << "==================================================" << endl;
	cout << " " << title << endl;
	cout << "==================================================" << endl;
}

int main() {
    cout << "=== CampusGuard: Emergency Response Coordination ===" <<endl;

    Zone* campus = buildCampus();
	SirenControlAdapter* sirens = buildSirens();
	NotificationService* notifier = sirens;

    IncidentCoordinator* coordinator = new IncidentCoordinator(campus, notifier);

	ResponseUnit* security = new SecurityTeam("SEC-01");
	ResponseUnit* medical = new MedicalTeam("MED-01");
	ResponseUnit* facilities = new FacilityStaff("FAC-01");
	coordinator->registerUnit(security);
	coordinator->registerUnit(medical);
	coordinator->registerUnit(facilities);

    OperatorConsole* console = new OperatorConsole();
	EmergencyFacade* facade = new EmergencyFacade(console, coordinator, campus, notifier);


	banner("SCENARIO 1: Chemical spill on Chemistry Floor 2");

	Incident* spill = facade->initiateEvacuationProtocol("Chemistry Floor 2", "Chemical spill");
	cout << "[Main] Incident status: " << spill->getStatus() << endl;

	// Security arrives on scene -> Mediator moves the incident to Active
	security->reportStatus(ON_SCENE, spill);
	cout << "[Main] Incident status: " << spill->getStatus() << endl;

	// Facilities handle the hazard and report it contained
	facilities->dispatch(spill);
	facilities->reportStatus(HAZARD_CONTAINED, spill);
	cout << "[Main] Incident status: " << spill->getStatus() << endl;

    // demonstrates resolve() is safe to call again on an already-resolved incident
	spill->resolve();
	cout << "[Main] Incident status: " << spill->getStatus() << endl;

	// ---------- Scenario 2: Threat reported in the IT Building ----------
	// Facade -> Composite lockdown, Adapter, Command + undo, Mediator coordination,
	// State refusal, and the legacy siren failure.
	banner("SCENARIO 2: Threat reported in the IT Building");

	Incident* threat = facade->triggerLockdownProtocol("IT Building");

	ResponseUnit* sec = coordinator->findAvailableUnit("SecurityTeam");
	console->submit(new DispatchUnitOnCommand(security, threat));
	cout << "[Main] Incident status: " << threat->getStatus() << endl;

	// Security confirms the threat -> the Mediator brings in Medical
	sec->reportStatus(THREAT_CONFIRMED, threat);

	// FAILURE CASE 1: the Server Room siren panel is offline (legacy error 17)
	banner("FAILURE CASE: legacy siren panel offline");
	console->submit(new IssueAlertOnCommand(notifier, "Shelter in place", "Server Room"));

	// FAILURE CASE 2: an unmapped area has no siren zone at all
	console->submit(new IssueAlertOnCommand(notifier, "Test alert", "Sports Centre"));

	// It turns out to be a false alarm: undo the last action, then stand down
	banner("FALSE ALARM: cancelling the last action");
	console->cancelLast();
	sec->reportStatus(FALSE_ALARM, threat);
	cout << "[Main] Incident status: " << threat->getStatus() << endl;

	// FAILURE CASE 3: State refuses a dispatch to a resolved incident
	banner("INVALID OPERATION: dispatch to a resolved incident");
	threat->dispatchUnit();

	// ---------- Clean up ----------
	banner("Shutting down");
	delete facade;        // owns nothing
	delete console;       // deletes its command history
	delete coordinator;   // deletes the incidents
	delete security;
	delete medical;
	delete facilities;
	delete notifier;      // virtual destructor -> ~SirenControlAdapter -> siren unit
	delete campus;        // recursively deletes every zone and room

	return 0;
}
