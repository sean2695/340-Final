#pragma once
#include "Monster.h"

class Vampire : public Monster
{
public:
	//constuctor
	Vampire(std::string name);
	//function to call to attack
	void attack();

	void lowerHp(int dmg);
};

