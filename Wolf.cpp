#include "Wolf.h"



Wolf::Wolf(std::string name) : Creature (name)
{
	if (this->isAlpha)
	{
		this->hp = 5;
		this->isAlpha = false;
	}
	else
		this->hp = 5;
	if (packCheck >= 50)
		this->pack = true;
}


void Wolf::wolfBite()
{
	std::cout << "The beast's angry maw closes around your flesh tearing a chunk off." << std::endl;
}

void Wolf::lowerHp(int dmg)
{
	if (dmg == 1)
	{
		std::cout << "Your fist pounds the mangled fur of the beast as its snarls its fangs agaisnt you." << std::endl;
		this->hp - dmg;
	}
	else if (dmg == 2)
	{
		std::cout << "Your blade slices through the animal's flesh and it yelps in suprise and pain." << std::endl;
		this->hp = hp - dmg;
	}
	else if (dmg == -1)
	{
		std::cout << "Your magic soothes the beasts and they no longer trouble you." << std::endl;
		this->hp = 0;
		this->pack = false;
	}
	else if (dmg == 3)
	{
		std::cout << "The fire lights its fur a flame and it rolls along the ground to put it out, leaving behind a large burn." << std::endl;
		this->hp = hp - 3;
	}
}


bool Wolf::getPack()
{
	return this->pack;
}

void Wolf::lowerPackCheck()
{
	this->packCheck = packCheck - 20;
	if (packCheck < 50)
	{
		this->pack = false;
	}
}

void Wolf::resetHp()
{
	this->hp = 5;
}