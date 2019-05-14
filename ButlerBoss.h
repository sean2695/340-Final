#pragma once
#include "Ghost.h"

class ButlerBoss : public Ghost
{
public:
	//constuctor for boss enemy
	ButlerBoss(std::string name);
	//Three attack functions for boss
	void strike();
	void stab();
	void curse();

	void lowerHp(int dmg);
};

