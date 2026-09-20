#ifndef EMERGENCYFACADE_H
#define EMERGENCYFACADE_H

#include <string>

using namespace std;

class OperatorConsole;
class IncidentCoordinator;
class AreaComponent;
class NotificationService;
class Incident;

class EmergencyFacade {

private:
	OperatorConsole* console;
	IncidentCoordinator* coordinator;
	AreaComponent* campus;
	NotificationService* notifier;

public:
	EmergencyFacade(OperatorConsole* console, IncidentCoordinator* coordinator, AreaComponent* campus, NotificationService* notifier);

	Incident* triggerLockdownProtocol(string building);

	Incident* initiateEvacuationProtocol(string building, string hazard);
};

#endif
