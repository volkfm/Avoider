#ifndef _GAME_H_
#define _GAME_H_
#include <SDL.h>
#include "Script.h"
#include "Player.h"
#include "Level.h"

class Game{
public:
	Game();

	int Execute();
	bool Init();
	void Render();
	void Loop();
	void Cleanup();
	void Event(SDL_Event* ev);
	void Exit();
private:
	bool Running;

	SDL_Surface* Screen;
	SDL_Surface* Numbers;
	SDL_Surface* Blink;
	Script scr;

	Level lvl;
	Player plr;
};

#endif