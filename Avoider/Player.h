#ifndef _PLAYER_
#define _PLAYER_

class Player {
public:
	void Init(int EnConts);
	void Waste();
	int Get();

private:
	int EnergyContainers;

};

#endif