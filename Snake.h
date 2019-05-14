#pragma once
#include "Creature.h"


class Snake : public Creature
{
public:
	Snake(std::string name);
	
	void snakeBite();
	bool getIsCharmed();
	void setIsCharmed();
	void lowerHp(int dmg);
	bool getSwarm();
	void lowerSwarmCheck();
	void resetHp();

private:
	bool swarm = false;
	bool isCharmed = false;
	int swarmCheck = rand() % 100;
};

