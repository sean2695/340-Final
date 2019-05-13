#include "Ghost.h"



Ghost::Ghost(std::string name)
{
	this->name = name;
}

//set if ghost is corporal
void Ghost::setCorporal()
{
	this->isCorporal = true;
}

//set if ghost is defeated
void Ghost::setDefeated()
{
	this->isDefeated = true;
}

//return if ghost is corporal
bool Ghost::getisCorporal()
{
	return this->isCorporal;
}

//return if the ghost is corporal
bool Ghost::getisDefeated()
{
	return this->isDefeated;
}
//return the ghost's hp
int Ghost::getHp()
{
	return this->hp;
}
//return the enemy name
std::string Ghost::getName()
{
	return this->name;
}
