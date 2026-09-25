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
	this->console = console;
	this->coordinator = coordinator;
	this->campus = campus;
	this->notifier = notifier;
}

Incident* EmergencyFacade::triggerLockdownProtocol(string building) {
	//go through the zones to find the building
	AreaComponent* zone = campus->find(building);

	if(zone == nullptr){
		//building not found on campus
		return nullptr;
	}

	Incident* incident = coordinator->createIncident("Lockdown", building);

	Command* lockdownCmd = new LockAreaOnCommand(zone);
	console->submit(lockdownCmd); //add to history

	Command* alertCmd = new IssueAlertOnCommand(notifier, "LOCKDOWN: " + building + " is now locked down.", building);
	console->submit(alertCmd); //add to history

	return incident;
}

Incident* EmergencyFacade::initiateEvacuationProtocol(string building, string hazard) {
	AreaComponent* zone = campus->find(building);

	if(zone == nullptr){
		//building not found on campus
		return nullptr;
	}

	Incident* incident = coordinator->createIncident(hazard, building);

	Command* alertCmd = new IssueAlertOnCommand(notifier, "EVACUATE: " + hazard + " reported at " + building, building);
	console->submit(alertCmd); //add to history

	//Emergency evacuation so added Security for initial response to coordinate evacuations/crowd movements
	ResponseUnit* unit = coordinator->findAvailableUnit("SecurityTeam");
	if (unit != nullptr) {
        Command* dispatchCmd = new DispatchUnitOnCommand(unit, incident);
        console->submit(dispatchCmd);
    }

	return incident;
}
