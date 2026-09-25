#include "OperatorConsole.h"
#include <iostream>

void OperatorConsole::submit(Command* cmd) {
	history.push_back(cmd);
	cmd->execute();
}

void OperatorConsole::cancelLast() {
	if(!history.empty()){
		Command* cmd = history.back();
		cmd->undo();
	}
	
}

OperatorConsole::~OperatorConsole() {
	while(!history.empty()){
		delete history.back();
		history.pop_back();
	}
}
