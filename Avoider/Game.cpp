#include "Game.h"
#include "Sprite.h"
#include "Script.h"
#include <SDL.h>

Game::Game() {
	Screen = NULL;
	
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

	scr.Load("scr.txt");

	return true;
}
void Game::Cleanup() {
	SDL_FreeSurface(Screen);

	SDL_Quit();
}
void Game::Event(SDL_Event* ev) {
	if (ev ->type == SDL_QUIT) 
		Exit();
}
void Game::Loop() {
	
}
void Game::Render() {
	SDL_FillRect(Screen, &Screen->clip_rect, SDL_MapRGB(Screen->format, 0, 0, 0));

	SDL_Flip(Screen);
}
void Game::Exit() {
	Running = false;
}

int main(int argc, char *argv[]) {
	Game Game;
	return Game.Execute();
}