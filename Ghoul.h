#pragma once

#include "Monster.h"



class Ghoul : public Monster

{

public:

	//constuctor

	Ghoul(std::string name);

	//function to call to attack

	void attack();

	//lower hp based on dmg
	void lowerHp(int dmg);
};

