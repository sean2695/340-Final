#include "Snake.h"



Snake::Snake(std::string name) : Creature(name)
{
	this->hp = 3;
	int swarmCheck = rand() % 100;
	std::cout << swarmCheck << std::endl;
	if (swarmCheck > 50)
	{
		this->swarm = true;
	}
}

void Snake::snakeBite()
{
	std::cout << "The snake hisses and strikes, it fangs sinking into your skin." << std::endl;
}

bool Snake::getIsCharmed()
{
	return this->isCharmed;
}

void Snake::setIsCharmed()
{
	this->isCharmed = true;
}

void Snake::lowerHp(int dmg)
{
	if (dmg == 0)
	{
		std::cout << "You try and throw a fist agaisnt the flailing serpent, but to no avail." << std::endl;
		this->hp - dmg;
	}
	if (dmg == 2)
	{
		std::cout << "Your blade grazes the scales of the creature, leaving a gash in the snake." << std::endl;
		this->hp = hp - dmg;

	}
	if (dmg == -1)
	{
		std::cout << "Your magic soothes the beasts and the no longer trouble you." << std::endl;
		this->hp = 0;
		this->swarm = false;
	}
	if (dmg == 5)
	{
		std::cout << "The magical blade slices the beast in half." << std::endl;
		this->hp = hp - dmg;
	}
}

bool Snake::getSwarm()
{
	return this->swarm;
}

void Snake::lowerSwarmCheck()
{
	this->swarmCheck = swarmCheck - 30;
	if (swarmCheck < 50)
	{
		this->swarm = false;
	}
}

void Snake::resetHp()
{
	this->hp = 3;
}