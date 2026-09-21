#include "Zone.h"
#include <iostream>

Zone::Zone(string name) : AreaComponent(name) {

}

void Zone::add(AreaComponent* child) {
	this->children.push_back(child);
}

void Zone::lock() {
	cout << "[Zone] locking" <<endl;

	vector<AreaComponent*>::iterator it;
	for (it = this->children.begin(); it != this->children.end(); ++it) {
		(*it)->lock();
	}
}

void Zone::unlock() {
	cout << "[Zone] unlocked" << endl;

	vector<AreaComponent*>::iterator it;
	for (it = this->children.begin(); it != this->children.end(); ++it) {
		(*it)->unlock();
	}

}

void Zone::restrict() {
	cout << "[Zone] restricted" << endl;
	vector<AreaComponent*>::iterator it;
	for (it = this->children.begin(); it != this->children.end(); ++it) {
		(*it)->restrict();
	}
}

AreaComponent* Zone::find(string name) {
	if(this->name == name){
		return this;
	}else{
		return nullptr;
	}
}

Zone::~Zone() {
	vector<AreaComponent*>::iterator it;
	for (it = this->children.begin(); it != this->children.end(); ++it) {
		delete (*it);
	}
}
