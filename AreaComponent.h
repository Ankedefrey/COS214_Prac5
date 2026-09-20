#ifndef AREACOMPONENT_H
#define AREACOMPONENT_H

#include <string>

using namespace std;

class AreaComponent {

protected:
	string name;

public:
	AreaComponent(string name);

	string getName();

	virtual void lock() = 0;

	virtual void unlock() = 0;

	virtual void restrict() = 0;

	virtual AreaComponent* find(string name) = 0;

	virtual ~AreaComponent();
};

#endif
