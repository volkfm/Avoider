#include "Level.h"
#include <fstream>
#include <string>

int Level::Load(const char* Name) {
	std::ifstream in(Name);

	std::string str;
	std::getline(in, str);
	int enc = atoi(str.c_str());

	while (!in.eof()) {
		std::string str1 = "", str2 = "", str3 = "";
		std::getline(in, str1, ' ');
		std::getline(in, str2, ' ');
		std::getline(in, str3);
		int res[3];

		res[0] = atoi(str1.c_str());
		res[1] = atoi(str2.c_str());
		res[2] = atoi(str3.c_str());

		Blinks.push_back(Blink(res[0], res[1], res[2]));
	}
	return enc;
}