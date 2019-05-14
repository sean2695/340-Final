#pragma once
#include "Creature.h"

class Wolf : public Creature
{
public:
	Wolf(std::string name);

	void wolfBite();
	void lowerHp(int dmg);
	bool getPack();
	void lowerPackCheck();
	void resetHp();

private:
	bool pack = false;
	bool isAlpha = true;
	int packCheck = 70;
};

