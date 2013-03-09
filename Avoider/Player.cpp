#include "Player.h"

void Player::Init(int EnConts) {
	EnergyContainers = EnConts;
}
void Player::Waste() {
	EnergyContainers--;
}
int Player::Get() {
	return EnergyContainers;
}