#include "Sprite.h"
#include <SDL.h>
#include <vector>

Sprite::Sprite() {}

SDL_Surface* Sprite::Load(const char* File) {
	SDL_Surface* Temp = NULL;
	SDL_Surface* Result = NULL;

	if ((Temp = SDL_LoadBMP(File)) == NULL)
		return NULL;

	Result = SDL_DisplayFormat(Temp);
	SDL_FreeSurface(Temp);

	Transparent(Result, 255, 0, 255);

	return Result;
}

bool Sprite::Draw(SDL_Surface* Dest, SDL_Surface* Src, int x, int y) {
	if (Dest == NULL || Src == NULL)
		return false;

	SDL_Rect Area;
	Area.x = x;
	Area.y = y;

	SDL_BlitSurface(Src, NULL, Dest, &Area);

	return true;
}

bool Sprite::Draw(SDL_Surface* Dest, SDL_Surface* Src, int x, int y, int x2, int y2, int w, int h) {
	if (Dest == NULL || Src == NULL)
		return false;

	SDL_Rect DArea;
	DArea.x = x;
	DArea.y = y;

	SDL_Rect SArea;

	SArea.x = x2;
	SArea.y = y2;
	SArea.w = w;
	SArea.h = h;

	SDL_BlitSurface(Src, &SArea, Dest, &DArea);

	return true;
}

bool Sprite::Transparent(SDL_Surface* Src, int r, int g, int b) {
	if (Src == NULL)
		return false;

	SDL_SetColorKey(Src, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Src ->format, r, g, b));

	return true;
}

void Sprite::DrawEnConts(int EnConts, SDL_Surface* Dest, SDL_Surface* Numbers) {
	if (EnConts > 9) 
		exit(0); // WTF?
	else 
		Draw(Dest, Numbers, 10, 10, 25 * EnConts, 0, 25, 25);
}

void Sprite::LoadNums(char* File, SDL_Surface* Numbers) {
	Numbers = Load(File);
}