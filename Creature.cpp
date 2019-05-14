#include "Creature.h"



Creature::Creature(std::string name)
{
	this->name = name;
}

bool Creature::getIsDefeated()
{
	return this->isDefeated;
}

void Creature::setIsDefeated()
{
	this->isDefeated = true;
}

int Creature::getHp()
{
	return this->hp;
}

std::string Creature::getName()
{
	return this->name;
}