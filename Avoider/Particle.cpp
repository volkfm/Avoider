#include "Particle.h"

Particle::Particle(int x, int y){
	this ->x = x + rand() % 25;
	this ->y = y + rand() % 25;

	this ->frames = rand() % 5;
}

bool Particle::Dead() {
	if (frames > 15)
		return true;
	return false;
}

SDL_Surface* Particle::GetImg() {
	return Img;
}
