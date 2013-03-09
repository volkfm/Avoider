#ifndef _SCRIPT_
#define _SCRIPT_
#include <stack>

class Script {
private:
	int res[2];
	std::stack<int> y;
	std::stack<int> d;
public:
	void Load(char* filename);
	int NextY();
	int NextD();
};

#endif