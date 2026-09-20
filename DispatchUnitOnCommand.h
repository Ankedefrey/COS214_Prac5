#ifndef DISPATCHUNITONCOMMAND_H
#define DISPATCHUNITONCOMMAND_H

#include "Command.h"

class ResponseUnit;
class Incident;

class DispatchUnitOnCommand : public Command {

private:
	ResponseUnit* unit;
	Incident* incident;

public:
	DispatchUnitOnCommand(ResponseUnit* unit, Incident* incident);

	virtual void execute();

	virtual void undo();
};

#endif
