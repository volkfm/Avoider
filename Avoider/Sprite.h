#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL.h>
#include <vector>

class Sprite {
public:
	static SDL_Surface* Load(const char* File);
	static bool Draw(SDL_Surface* Dest, SDL_Surface* Src, int x, int y);
	static bool Draw(SDL_Surface* Dest, SDL_Surface* Src, int x, int y, int x2, int y2, int w, int h);
	static bool Transparent(SDL_Surface* Src, int r, int g, int b);
	static void DrawEnConts(int EnConts, SDL_Surface* Dest, SDL_Surface* Numbers);
	static void LoadNums(char* File, SDL_Surface* Numbers);

	Sprite();
};

#endif

