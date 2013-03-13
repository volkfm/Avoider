#include "Game.h"
#include "Sprite.h"
#include "Script.h"
#include "Player.h"
#include <SDL.h>

#define MAX_FPS 60

Game::Game() {
	Screen = NULL;
	Blink = NULL;
	State = InGame;
	
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

	Sprite::Sprite();
	Sign = Sprite::Load("images\\sign.bmp");
	Plr.Init(Lvl.Load("level01.txt"));
	Blink = Sprite::Load("images\\blink.bmp");
	Sprite::Transparent(Blink, 255, 0, 255);

	srand(SDL_GetTicks());

	return true;
}
void Game::Cleanup() {
	SDL_FreeSurface(Screen);

	SDL_Quit();
}
void Game::Loop() {
	if (Lvl.Blinks.size() == 0 ||
		Plr.Get() <= 0) {
			ExitOnWin.Start();
			State = Paused;
	}

	if (ExitOnWin.Get() > 3000) 
		Exit();

	for (int i = 0; i < 100; i++) {
		if (Plr.Particles[i] ->Dead()) {
			delete Plr.Particles[i];
			Plr.Particles[i] = new Particle(0,0);
		} else
			Plr.Particles[i] ->frames++;
	}
}
void Game::Render() {
	FPSTimer.Start();

	if (FPSTimer.Get() < 1000 / MAX_FPS) {
		return;
	} else {
		FPSTimer.Stop();
		FPSTimer.Start();
	}

	SDL_FillRect(Screen, &Screen->clip_rect, SDL_MapRGB(Screen->format, 0xFF, 0xFF, 0xFF));

	Sprite::DrawString(std::to_string((long long) Plr.Get()), 10, 10, Screen);

	for (unsigned int i = 0; i < Lvl.Blinks.size(); i++) {
		Sprite::Draw(Screen, Blink, Lvl.Blinks.at(i).cx - 16, Lvl.Blinks.at(i).cy - 16);
		Sprite::DrawString(std::to_string((long long) Lvl.Blinks.at(i).NegativeLevel), Lvl.Blinks.at(i).cx - 16, Lvl.Blinks.at(i).cy - 32, Screen);
	}
	if (Lvl.Blinks.size() == 0 &&
		Plr.Get() >= 0) {
			Sprite::DrawString("WIN", 300, 200, Screen);
	} else if (Plr.Get() <= 0 &&
		Lvl.Blinks.size() > 0) {
			Sprite::DrawString("LOSE", 300, 200, Screen);
	}

	

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
		if (ev ->button.button == SDL_BUTTON_LEFT&&
			State == InGame) {
			int x = ev ->button.x;
			int y = ev ->button.y;

			for (unsigned int i = 0; i < Lvl.Blinks.size(); i++) {
				if (abs(x - Lvl.Blinks.at(i).cx) + abs(y - Lvl.Blinks.at(i).cy) < 100) {
					Lvl.Blinks.at(i).NegativeLevel -= 100 - (abs(x - Lvl.Blinks.at(i).cx) + abs(y - Lvl.Blinks.at(i).cy));
					if (Lvl.Blinks.at(i).NegativeLevel < 1) {
						Lvl.Blinks.erase(Lvl.Blinks.begin() + i);
						i--;
					}
				}
			}

			Plr.Waste();
		}
	}
}