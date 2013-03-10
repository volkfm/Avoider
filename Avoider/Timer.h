#ifndef _CTIMER_
#define _CTIMER_

class CTimer{
private:
	int startTicks, pauseTicks;
	bool paused, started;

public:
	CTimer();

	void Start();
	void Stop();
	void Pause();
	void Unpause();

	int Get();

	bool IsStarted();
	bool IsPaused();
};

#endif
