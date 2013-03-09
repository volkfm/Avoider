#include "Game.h"
#include "Sprite.h"
#include "Script.h"
#include "Player.h"
#include <SDL.h>
#include <cmath>

Game::Game() {
	Screen = NULL;
	Numbers = NULL;
	Blink = NULL;
	
	Running = true;
}
int Game::Execute() {
	if (!Init()) return -1;

	SDL_Event ev;
	while (Running) {
		while (SDL_PollEvent(&ev))
			Event(&ev);
		Loop();
		Render();
	}
	Cleanup();
	return 0;
}
bool Game::Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
		return false;
	if ((Screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
		return false;

	Numbers = Sprite::Load("images\\nums.bmp");
	plr.Init(lvl.Load("level01.txt"));
	Blink = Sprite::Load("images\\blink.bmp");
	Sprite::Transparent(Blink, 255, 0, 255);

	return true;
}
void Game::Cleanup() {
	SDL_FreeSurface(Screen);

	SDL_Quit();
}
void Game::Loop() {
	
}
void Game::Render() {
	SDL_FillRect(Screen, &Screen->clip_rect, SDL_MapRGB(Screen->format, 0xFF, 0xFF, 0xFF));

	Sprite::DrawEnConts(plr.Get(), Screen, Numbers);

	for (int i = 0; i < lvl.Blinks.size(); i++)
		Sprite::Draw(Screen, Blink, lvl.Blinks.at(i).cx - 16, lvl.Blinks.at(i).cy - 16);

	SDL_Flip(Screen);
}
void Game::Exit() {
	Running = false;
}

int main(int argc, char *argv[]) {
	Game Game;
	return Game.Execute();
}

void Game::Event(SDL_Event* ev) {
	switch (ev ->type) {
	case SDL_QUIT:
		Exit();
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (ev ->button.button == SDL_BUTTON_LEFT) {
			int x = ev ->button.x;
			int y = ev ->button.y;

			for (int i = 0; i < lvl.Blinks.size(); i++) {
				if (sqrt((double) (abs(x + lvl.Blinks.at(i).cx) + abs(y + lvl.Blinks.at(i).cy))) < 100) {
					lvl.Blinks.at(i).NegativeLevel -= 100 - sqrt((double) (abs(x + lvl.Blinks.at(i).cx) + abs(y + lvl.Blinks.at(i).cy)));
					if (lvl.Blinks.at(i).NegativeLevel < 1) {
						lvl.Blinks.erase(lvl.Blinks.begin() + i);
					}
				}
			}
		}
	}
}