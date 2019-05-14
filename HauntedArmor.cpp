#include "HauntedArmor.h"

//constructor
HauntedArmor::HauntedArmor(std::string name) : Ghost(name)
{

}

//the attack for the haunted armor
void HauntedArmor::attack()
{
	std::cout << "The armor moves to attack you. You try to avoid the approaching gauntlet as it speeds toward you, but it smashes into your shoulder." << std::endl;
}


void HauntedArmor::lowerHp(int dmg) {
	if (dmg == 0)
	{
		std::cout << "You feel a finger break as your fist strikes the armor." << std::endl;
	}
	if (dmg == 2)
	{
		std::cout << "The sword bounces off the hard steel" << std::endl;
		this->hp = hp - dmg;
	}
	if (dmg == 50)
	{
		std::cout << "Mist pours from the hollow part of the armor as a scream rings out." << std::endl;
		this->hp = hp - dmg;
	}
	if (dmg == 100)
	{
		std::cout << "The armor crashes the ground in pieces, the spirit holding it together banished." << std::endl;
		this->hp = hp - dmg;
	}
	if (dmg == 98)
	{
		std::cout << "A phantom takes form in the armor, presenting a body to strike." << std::endl;
		this->hp = 2;
		this->isCorporal = true;
	}
}

