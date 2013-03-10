#ifndef _GAME_H_
#define _GAME_H_
#include <SDL.h>
#include "Script.h"
#include "Player.h"
#include "Level.h"
#include "Timer.h"

enum GameState {
	InGame, Paused, MainMenu
};
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
	SDL_Surface* Sign;
	SDL_Surface* Blink;
	Script scr;

	Level Lvl;
	Player Plr;
	GameState State;
	CTimer ExitOnWin;
	CTimer FPSTimer;
};

#endif