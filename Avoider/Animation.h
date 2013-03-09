#ifndef _ANIM_
#define _ANIM_
#include <vector>

class Animation {
public:
	int w, h;
	int frames;
	int current;
	int velo;

	SDL_Surface* Anim;

	Animation(int w, int h, int frames, int velo)æ
}

#endif