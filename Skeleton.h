#pragma once
#include "Undead.h"

class Skeleton : public Undead
{
public:
	//constuctor
	Skeleton(std::string name);
	//function to call to attack
	void attack();
	void lowerHp(int dmg);

};
