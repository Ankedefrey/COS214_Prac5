#ifndef LOCKAREAONCOMMAND_H
#define LOCKAREAONCOMMAND_H

#include "Command.h"

class AreaComponent;

class LockAreaOnCommand : public Command {

private:
	AreaComponent* area;

public:
	LockAreaOnCommand(AreaComponent* area);

	virtual void execute();

	virtual void undo();
};

#endif
