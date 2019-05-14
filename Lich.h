#pragma once
#include <iostream>
#include "Undead.h"

class Lich : public Undead
{
public:
	Lich(std::string name);
	//Three attack functions for boss
	void strike();
	void stab();
	void curse();

	void lowerHp(int dmg);

};
