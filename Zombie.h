#pragma once
#include "Undead.h"


class Zombie : public Undead
{
public:
	//constuctor 
	Zombie(std::string name);
	//function to call to attack
	void bite();

	void lowerHp(int dmg);

};
