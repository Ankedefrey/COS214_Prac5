CXX = g++
FLAGS = -std=c++11 -Wall -Wextra -g
EXE = campusguard

SRCS  = main.cpp \
        AreaComponent.cpp Zone.cpp Room.cpp \
        NotificationService.cpp SirenControlAdapter.cpp SirenControlUnit.cpp \
        Command.cpp OperatorConsole.cpp \
        DispatchUnitOnCommand.cpp LockAreaOnCommand.cpp IssueAlertOnCommand.cpp \
        Incident.cpp IncidentState.cpp \
        ReportedState.cpp ActiveState.cpp ContainedState.cpp ResolvedState.cpp \
        IncidentMediator.cpp IncidentCoordinator.cpp \
        ResponseUnit.cpp SecurityTeam.cpp MedicalTeam.cpp FacilityStaff.cpp \
        EmergencyFacade.cpp
all:
	$(CXX) $(CFLAGS) $(SRCS) -o $(EXE)

run: all
	./$(EXE)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./$(EXE)

gdb: all
	gdb ./$(EXE)

clean:
	rm -f $(EXE)