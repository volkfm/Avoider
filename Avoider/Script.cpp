#include "Script.h"
#include <fstream>
#include <string>
	
void Script::Load(char* scriptFilename) {
	std::ifstream in(scriptFilename);

	while (!in.eof()) {
		std::string str1 = "", str2 = "";
		std::getline(in, str1, ' ');
		std::getline(in, str2);

		res[0] = atoi(str1.c_str());
		res[1] = atoi(str2.c_str());

		y.push(res[0]);
		d.push(res[1]);
	}
}
int Script::NextY() {
	int res = y.top();
	y.pop();
	return res;
}
int Script::NextD() {
	int res = d.top();
	d.pop();
	return res;
}