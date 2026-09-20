#ifndef ISSUEALERTONCOMMAND_H
#define ISSUEALERTONCOMMAND_H

#include <string>
#include "Command.h"

using namespace std;

class NotificationService;

class IssueAlertOnCommand : public Command {

private:
	NotificationService* notifier;
	string message;
	string areaName;

public:
	IssueAlertOnCommand(NotificationService* notifier, string message, string areaName);

	virtual void execute();

	virtual void undo();
};

#endif
