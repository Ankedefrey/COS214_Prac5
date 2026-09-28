#include "OperatorConsole.h"
#include <iostream>

void OperatorConsole::submit(Command* cmd) {
	cout << "[Console] Executing command (history size " << history.size() + 1 << ")" << endl;
	history.push_back(cmd);
	cmd->execute();
}

void OperatorConsole::cancelLast() {
	if(history.empty()){
		cout << "[Console] Nothing to cancel - no actions in history" << endl;
		return;
	}
	cout << "[Console] Undoing last command" << endl;
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
