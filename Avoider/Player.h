#ifndef _PLAYER_
#define _PLAYER_
#include "Particle.h"
#include <SDL.h>

class Player {
public:
	void Init(int EnConts);
	void Waste();
	int Get();
	Particle* Particles[100];

private:
	int EnergyContainers;
};

#endif