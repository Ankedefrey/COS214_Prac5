#include "Zone.h"
#include <iostream>

using namespace std;

Zone::Zone(string name) : AreaComponent(name) {

}

void Zone::add(AreaComponent* child) {
	this->children.push_back(child);
}

void Zone::lock() {
	cout << "[Zone] Locking " << this->name << endl;

	vector<AreaComponent*>::iterator it;
	for (it = this->children.begin(); it != this->children.end(); ++it) {
		(*it)->lock();
	}
}

void Zone::unlock() {
	cout << "[Zone] Unlocking " << this->name<< endl;

	vector<AreaComponent*>::iterator it;
	for (it = this->children.begin(); it != this->children.end(); ++it) {
		(*it)->unlock();
	}

}

void Zone::restrict() {
	cout << "[Zone] Restricting " << this->name << endl;
	vector<AreaComponent*>::iterator it;
	for (it = this->children.begin(); it != this->children.end(); ++it) {
		(*it)->restrict();
	}
}

AreaComponent* Zone::find(string name) {
	// gdb 1 fix
	if (this->name == name) {
		return this;
	}
	
	vector<AreaComponent*>::iterator it;
	for (it = this->children.begin(); it != this->children.end(); ++it) {
		AreaComponent* result = (*it)->find(name);
		if (result != nullptr) {
			return result;
		}
	}
	return nullptr;
}

Zone::~Zone() {
	vector<AreaComponent*>::iterator it;
	for (it = this->children.begin(); it != this->children.end(); ++it) {
		delete (*it);
	}
}
