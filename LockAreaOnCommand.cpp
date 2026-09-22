#include "LockAreaOnCommand.h"
#include "AreaComponent.h"
#include <iostream>

LockAreaOnCommand::LockAreaOnCommand(AreaComponent* area): area(area) {
}

void LockAreaOnCommand::execute() {
	area->lock();
}

void LockAreaOnCommand::undo() {
	area->unlock();
}
