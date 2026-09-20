#ifndef SIRENCONTROLUNIT_H
#define SIRENCONTROLUNIT_H

/**
 * Legacy campus siren hardware (Adaptee).
 * Knows nothing about CampusGuard: int zone codes in, int error codes out.
 */
class SirenControlUnit {

public:
	int activateSiren(int zoneCode, int intensity);

	int deactivateSiren(int zoneCode);
};

#endif
