#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "AreaComponent.h"

using namespace std;

class Room : public AreaComponent {

private:
	bool locked;
	bool restricted;

public:
	Room(string name);

	virtual void lock();

	virtual void unlock();

	virtual void restrict();

	virtual AreaComponent* find(string name);
};

#endif
