#include "Player.h"
#include <SDL.h>

void Player::Init(int EnConts) {
	EnergyContainers = EnConts;

	for (int i = 0; i < TOTAL_PARTICLES; i++)
		Particles[i] = new Particle(0, 0);
}
void Player::Waste() {
	EnergyContainers--;
}
int Player::Get() {
	return EnergyContainers;
}