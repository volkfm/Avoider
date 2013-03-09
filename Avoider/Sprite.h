#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL.h>

class Sprite {
public:
	static SDL_Surface* Load(const char* File);
	static bool Draw(SDL_Surface* Dest, SDL_Surface* Src, int x, int y);
	static bool Draw(SDL_Surface* Dest, SDL_Surface* Src, int x, int y, int x2, int y2, int w, int h);
	static bool Transparent(SDL_Surface* Src, int r, int g, int b);
	static void DrawLevel(SDL_Surface* Dest, SDL_Surface* Surface, int level);
	static void DrawScore(SDL_Surface* Dest, SDL_Surface* Surface, int score);

	Sprite();
};

#endif

