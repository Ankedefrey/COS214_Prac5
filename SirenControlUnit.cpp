#include "SirenControlUnit.h"
#include <iostream>
using namespace std;
//Adaptee - old legacy hardware

//print raw call
int SirenControlUnit::activateSiren(int zoneCode, int intensity) {
	cout<<"[SirenUnit] ACTIVATE zone="<<zoneCode<<" intensity="<<intensity<<endl;
	return 0;
}

int SirenControlUnit::deactivateSiren(int zoneCode) {
	cout<<"[SirenUnit] DEACTIVATE zone="<<zoneCode<<endl;
	return 0;
}
