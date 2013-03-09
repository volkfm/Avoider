#include "Sprite.h"
#include <SDL.h>

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

void Sprite::DrawLevel(SDL_Surface* Dest, SDL_Surface* Surface, int level) {
	Draw(Dest, Surface, 400, 20, 0, 0, 21 * 10, 5 * 10);
	if (level >= 10) {
		Draw(Dest, Surface, 450 + 21 * 10, 20, 21 * 10 + 50, 0, 5 * 10, 5 * 10);
		Draw(Dest, Surface, 450 + 21 * 10 + 5 * 10, 20, 210 + level % 10 * 5 * 10, 0, 5 * 10, 5 * 10);
	} else {
		Draw(Dest, Surface, 450 + 21 * 10, 20, 210 + level * 50, 0, 5 * 10, 5 * 10);
	}
}

void Sprite::DrawScore(SDL_Surface* Dest, SDL_Surface* Surface, int score) {
	int c[5];

	c[0] = score / 10000;
	c[1] = score % 10000 / 1000;
	c[2] = score % 1000 / 100;
	c[3] = score % 100 / 10;
	c[4] = score % 10;

	Draw(Dest, Surface, 400 + 1 * 50, 530, 210 + c[0] * 50, 0, 5 * 10, 5 * 10);
	Draw(Dest, Surface, 400 + 2 * 50, 530, 210 + c[1] * 50, 0, 5 * 10, 5 * 10);
	Draw(Dest, Surface, 400 + 3 * 50, 530, 210 + c[2] * 50, 0, 5 * 10, 5 * 10);
	Draw(Dest, Surface, 400 + 4 * 50, 530, 210 + c[3] * 50, 0, 5 * 10, 5 * 10);
	Draw(Dest, Surface, 400 + 5 * 50, 530, 210 + c[4] * 50, 0, 5 * 10, 5 * 10);
}

bool Sprite::Transparent(SDL_Surface* Src, int r, int g, int b) {
	if (Src == NULL)
		return false;

	SDL_SetColorKey(Src, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Src ->format, r, g, b));

	return true;
}