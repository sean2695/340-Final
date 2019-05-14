#include "Monster.h"



//constructor

Monster::Monster(std::string name)

{

	this->name = name;

	this->hp = 150;

}



//function to lower Monster hp

void Monster::lowerHp()

{

	this->hp--;

}



//return Monster hp

int Monster::getHp()

{

	return this->hp;

}



//return Monster name

std::string Monster::getName()

{

	return this->name;

}



//set if the enemy had been defeated

void Monster::setisDefeated()

{

	this->isDefeated = true;

}



//return if the enemy has been defeated

bool Monster::getisDefeated()

{

	return this->isDefeated;

}
