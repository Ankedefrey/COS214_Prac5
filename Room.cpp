#include "Room.h"
#include <iostream>

Room::Room(string name) : AreaComponent(name) {
	this->locked = false;
	this->restricted = false;
}

void Room::lock() {
	this->locked = true;
	cout << "[Zone] " << this->name << " locked" << endl;
}

void Room::unlock() {
	this->locked = false;
	this->restricted = false;
}

void Room::restrict() {
	this->restricted = true;
	cout << "[Zone] " << this->name << " restricted" << endl;
}

AreaComponent* Room::find(string name) {
	if(this->name == name){
		return this;
	}else{
		return nullptr;
	}
}
