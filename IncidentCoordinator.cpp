#include "IncidentCoordinator.h"
#include "ResponseUnit.h"
#include "Incident.h"
#include "AreaComponent.h"
#include "NotificationService.h"
#include <iostream>

IncidentCoordinator::IncidentCoordinator(AreaComponent* campus, NotificationService* notifier) {
	this->campus = campus;
	this->notifier = notifier;
}

//unit calls this whenever something happens to it and forwards event and lets coordinator sort it out
void IncidentCoordinator::notify(ResponseUnit* sender, UnitEvent event, Incident* incident) {
    switch (event) {
        case ON_SCENE:
			// Unit has physically arrived -> incident moves Reported -> Active.
            incident->dispatchUnit();
            break;
        case THREAT_CONFIRMED: {
			// Sender confirms real emergency and we add Medical team as additional
			//backup. Not an operator-issued command but mediator driven dispatch
			//not wrapped in a DispatchUnitOnCommand or added in OPERATORconsole history
            ResponseUnit* backup = findAvailableUnit("MedicalTeam");
            if (backup != nullptr) {
                backup->dispatch(incident);
                incident->dispatchUnit();  // "extra units" case from ActiveState
            }
            break;
        }
		//unit on scene is qualified to call that job is done here
        case HAZARD_CONTAINED:
            incident->contain();
			sender->recall();
            break;
        case FALSE_ALARM:
			//unit on reports FALSE_ALARM after being ON_SCENE
			//run the normal transition (Active -> Contained -> Resolved)
            incident->contain();
            incident->resolve();
            sender->recall();
            break;
    }
}

//units must be registered before being dispatched
void IncidentCoordinator::registerUnit(ResponseUnit* respUnit) {
	//ReponseUnit becomes Colleague once registered with coordinator
	respUnit->setMediator(this);
	// add to unit collection so coordinator knows about them
	units.push_back(respUnit);
}

Incident* IncidentCoordinator::createIncident(string type, string location) {
	Incident* incident = new Incident(incidents.size(), type, location);
	incidents.push_back(incident);
	return incident;
}

ResponseUnit* IncidentCoordinator::findAvailableUnit(string unitType) {
	for (ResponseUnit* unit : units) {
        if (unit->getType() == unitType && unit->isAvailable()) {
            return unit;
        }
    }
    return nullptr;
}

IncidentCoordinator::~IncidentCoordinator() {
	//created incidents collection inside class, thus clean up incidents
	vector<Incident*>::iterator it;
	for (it = this->incidents.begin(); it != this->incidents.end(); ++it) {
		delete (*it);
	}

	//doesnt own units (vector<ResponseUnit*>) since already constructed
	//in registerUnit(ResponseUnit* respUnit)
}
