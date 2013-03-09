#ifndef _LEVEL_
#define _LEVEL_
#include "Blink.h"
#include <vector>

class Level {
public:
	int Load(const char* LevelName);

	std::vector<Blink> Blinks;
};

#endif