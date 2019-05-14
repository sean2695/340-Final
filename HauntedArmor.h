#pragma once
#include "Ghost.h"

class HauntedArmor : public Ghost
{
public:
	//constuctor
	HauntedArmor(std::string name);
	// function to call attack
	void attack();

	void lowerHp(int dmg);

};

