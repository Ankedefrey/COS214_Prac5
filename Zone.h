#ifndef ZONE_H
#define ZONE_H

#include <vector>
#include <string>
#include "AreaComponent.h"

using namespace std;

class Zone : public AreaComponent {

private:
	vector<AreaComponent*> children;

public:
	Zone(string name);

	void add(AreaComponent* child);

	virtual void lock();

	virtual void unlock();

	virtual void restrict();

	virtual AreaComponent* find(string name);

	virtual ~Zone();
};

#endif
