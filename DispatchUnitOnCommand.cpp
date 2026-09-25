#include "DispatchUnitOnCommand.h"
#include "ResponseUnit.h"
#include "Incident.h"
#include <iostream>

DispatchUnitOnCommand::DispatchUnitOnCommand(ResponseUnit* unit, Incident* incident): unit(unit), incident(incident) {
}

void DispatchUnitOnCommand::execute() {
	unit->dispatch(incident);
}

void DispatchUnitOnCommand::undo() {
	unit->recall();
}
