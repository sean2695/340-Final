#include "Undead.h"

//constructor
Undead::Undead(std::string name)
{
	this->name = name;
	this->hp = 3;
}

//function to lower Undead's hp
void Undead::lowerHp()
{
	this->hp--;
}

//return undead's hp
int Undead::getHp()
{
	return this->hp;
}

//return undead's name
std::string Undead::getName()
{
	return this->name;
}

//set if the enemy had been defeated
void Undead::setisDefeated()
{
	this->isDefeated = true;
}

//return if the enemy has been defeated
bool Undead::getisDefeated()
{
	return this->isDefeated;
}