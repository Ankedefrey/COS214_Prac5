CXX = g++
FLAGS = -std=c++11 -Wall -Wextra -g
EXE = campusguard

SRCS  = main.cpp \
        AreaComponent.cpp Zone.cpp Room.cpp \
        NotificationService.cpp SirenControlAdapter.cpp SirenControlUnit.cpp

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