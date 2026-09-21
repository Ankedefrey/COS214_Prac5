#include "SirenControlUnit.h"
#include <iostream>
using namespace std;
//Adaptee - old legacy hardware

//print raw call
int SirenControlUnit::activateSiren(int zoneCode, int intensity) {
	//broken siren
	// adapter->mapArea("Server Room", 99);
	if (zoneCode == 99) {
		cout << "[SirenUnit] ACTIVATE zone="<<zoneCode<< " -> ERROR 17 (panel offline)"<< endl;
		return 17;
	}
	cout<<"[SirenUnit] ACTIVATE zone="<<zoneCode<<" intensity="<<intensity<<endl;
	return 0;
}

int SirenControlUnit::deactivateSiren(int zoneCode) {
	if (zoneCode == 99) {
		cout << "[SirenUnit] DEACTIVATE zone="<<zoneCode<< " -> ERROR 17 (panel offline)"<< endl;
		return 17;
	}
	cout<<"[SirenUnit] DEACTIVATE zone="<<zoneCode<<endl;
	return 0;
}
