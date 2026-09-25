#include "IssueAlertOnCommand.h"
#include "NotificationService.h"
#include <iostream>

IssueAlertOnCommand::IssueAlertOnCommand(NotificationService* notifier, string message, string areaName):
 notifier(notifier), message(message), areaName(areaName) {
}

void IssueAlertOnCommand::execute() {
	notifier->sendAlert(message,areaName,true);
}

void IssueAlertOnCommand::undo() {
	notifier->clearAlert(areaName);
}
