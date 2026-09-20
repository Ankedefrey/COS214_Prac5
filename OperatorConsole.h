#ifndef OPERATORCONSOLE_H
#define OPERATORCONSOLE_H

#include <vector>
#include "Command.h"

using namespace std;

class OperatorConsole {

private:
	vector<Command*> history;

public:
	void submit(Command* cmd);

	void cancelLast();

	~OperatorConsole();
};

#endif
