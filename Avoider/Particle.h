#ifndef _PARTICLE_
#define _PARTICLE_
#include <SDL.h>

class Particle {
private:
	SDL_Surface* Img;
public:
	Particle(int x, int y);
	
	int frames;
	int x, y;

	bool Dead();

	SDL_Surface* GetImg();
};

#endif