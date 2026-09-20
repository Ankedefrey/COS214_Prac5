#include "EmergencyFacade.h"
#include "OperatorConsole.h"
#include "IncidentCoordinator.h"
#include "AreaComponent.h"
#include "NotificationService.h"
#include "Incident.h"
#include "DispatchUnitOnCommand.h"
#include "LockAreaOnCommand.h"
#include "IssueAlertOnCommand.h"
#include <iostream>

EmergencyFacade::EmergencyFacade(OperatorConsole* console, IncidentCoordinator* coordinator, AreaComponent* campus, NotificationService* notifier) {
	throw "Not yet implemented";
}

Incident* EmergencyFacade::triggerLockdownProtocol(string building) {
	throw "Not yet implemented";
}

Incident* EmergencyFacade::initiateEvacuationProtocol(string building, string hazard) {
	throw "Not yet implemented";
}
