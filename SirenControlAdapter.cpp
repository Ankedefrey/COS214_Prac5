#include "SirenControlAdapter.h"
#include "SirenControlUnit.h"
#include <iostream>

SirenControlAdapter::SirenControlAdapter() {
	this->sirenUnit = new SirenControlUnit();
}

void SirenControlAdapter::mapArea(string areaName, int zoneCode) {
	this->zoneCodes[areaName] = zoneCode;
}

bool SirenControlAdapter::sendAlert(string message, string areaName, bool urgent) {
	//Translate the area name into the legacy zone code
	map<string, int>::iterator it = this->zoneCodes.find(areaName);
    if (it == this->zoneCodes.end()) {
		cout << "[Adapter] No siren zone mapped for " << areaName << " - alert NOT sent" << endl;
		return false;
	}
    int code = it->second;

	//Translate urgent into a siren intensity
	int intensity;
	if (urgent) {
		intensity = 3;
	} else {
		intensity = 1;
	}

	//Show the translation
	cout << "[Adapter] \"" <<message<< "\" for " <<areaName<< " -> activateSiren(" << code << ", " << intensity << ")" << endl;
	
	//Call the adaptee and translate its error code
	int result = this->sirenUnit->activateSiren(code, intensity);
	if (result != 0) {
		cout << "[Adapter] Siren FAILED for " << areaName << " (error " << result << ")" << endl;
		return false;
	}
	return true;
}

void SirenControlAdapter::clearAlert(string areaName) {
	//Translate the area name into the legacy zone code
	map<string, int>::iterator it = this->zoneCodes.find(areaName);
    if (it == this->zoneCodes.end()) {
		cout << "[Adapter] No siren zone mapped for " << areaName << " - alert NOT cleared" << endl;
		return;
	}
    int code = it->second;


	//Call the adaptee and translate its error code
	int result = this->sirenUnit->deactivateSiren(code);
	if (result != 0) {
		cout << "[Adapter] Siren clear FAILED for " << areaName << " (error " << result << ")" << endl;
	}
}

SirenControlAdapter::~SirenControlAdapter() {
	delete this->sirenUnit;
}
