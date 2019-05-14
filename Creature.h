#pragma once
#include <string>
#include <iostream>
#include <random>
#include <time.h>
#include <cstdlib>

class Creature
{
public:
	Creature(std::string name);

	bool getIsDefeated();
	void setIsDefeated();
	std::string getName();
	int getHp();


protected:
	std::string name;
	int hp;
	bool isDefeated = false;
};