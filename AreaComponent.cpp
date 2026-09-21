#include "AreaComponent.h"

AreaComponent::AreaComponent(string name) {
	this->name = name;
}

string AreaComponent::getName() {
	return this->name;
}

AreaComponent::~AreaComponent() {
}
