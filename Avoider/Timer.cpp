#include "Timer.h"
#include <SDL.h>

CTimer::CTimer() {
	startTicks = 0;
	pauseTicks = 0;
	started = false;
	paused = false;
}
void CTimer::Start() {
	if (started) return;
	started = true;
	paused = false;
	startTicks = SDL_GetTicks();
}
void CTimer::Stop() {
	started = false;
	paused = false;
}
void CTimer::Pause() {
	if(started && paused){
        paused = true;
        pauseTicks = SDL_GetTicks() - startTicks;
    }
}
void CTimer::Unpause() {
	if(paused) {
        paused = false;
        startTicks = SDL_GetTicks() - pauseTicks;
        pauseTicks = 0;
    }
}
int CTimer::Get() {
	if (started) {
		if (paused) 
			return pauseTicks;
		else
			return SDL_GetTicks() - startTicks;
	}
	return 0;
}
bool CTimer::IsStarted() {
	return started;
}
bool CTimer::IsPaused() {
	return paused;
}