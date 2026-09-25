#include "OperatorConsole.h"
#include <iostream>

void OperatorConsole::submit(Command* cmd) {
	history.push_back(cmd);
	cmd->execute();
}

void OperatorConsole::cancelLast() {
	if(history.empty()){
		cout << "[Console] Nothing to cancel - no actions in history" << endl;
		return;
	}
	Command* cmd = history.back();
	history.pop_back();
	cmd->undo();
	delete cmd;
	
}

OperatorConsole::~OperatorConsole() {
	while(!history.empty()){
		delete history.back();
		history.pop_back();
	}
}
