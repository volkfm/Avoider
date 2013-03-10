#include "Sprite.h"
#include <SDL.h>
#include <vector>
#include <string>

SDL_Surface* Sprite::Font = NULL;

Sprite::Sprite() {
	Font = Load("images\\font.bmp");
}

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

void Sprite::DrawEnConts(int EnConts, SDL_Surface* Dest) {
	char* buff;
	_itoa(EnConts, buff, 10);
	if (EnConts > 9) 
		exit(0); // WTF?
	else 
		DrawString(buff, 10, 10, Dest);
}

void Sprite::DrawString(std::string Str, int x, int y, SDL_Surface* Dest) {
	int offsMult = 1;

	for (unsigned int i = 0; i < Str.length(); i++) {
		Str[i] = toupper(Str.c_str()[i]);

		if (static_cast<int>(Str.c_str()[i]) < 91 &&
			static_cast<int>(Str.c_str()[i]) > 64) {
				int sym = static_cast<int>(Str.c_str()[i]) - 65;
				int yOffsMult = sym / 16;

				Draw(Dest, Font, x + offsMult * 25, y, sym % 16 * 25, yOffsMult*6*5 +1, 25, 25);

				offsMult++;
		} else if (static_cast<int>(Str.c_str()[i]) < 58 &&
			static_cast<int>(Str.c_str()[i]) > 47) {
				int sym = static_cast<int>(Str.c_str()[i]) - 48;

				if (sym < 6)
					Draw(Dest, Font, x + offsMult * 25, y, sym * 25 + 250, 6 * 5, 25, 25);
				else
					Draw(Dest, Font, x + offsMult * 25, y, (sym - 6) * 25, 12 * 5, 25, 25);
				offsMult++;
		}
	}
}