#include "Vampire.h"



//constructor

Vampire::Vampire(std::string name) : Monster(name)

{



}



// the attack for the skeleton

void Vampire::attack()
{
	std::cout << "The blood sucking vampire lunges your way looking to end your life and feast on you, sinking his fangs into your neck." << std::endl;
}


void Vampire::lowerHp(int dmg)
{
	if (dmg == 0)
	{
		std::cout << "You try and punch, but the vampire is too quick and catches your wrist grinning at you." << std::endl;
		this->hp - dmg;
	}
	else if (dmg == 40)
	{
		std::cout << "You thrust your blade, piercing the vampire and wounding it." << std::endl;
		this->hp = hp - dmg;
	}
	else if (dmg == 50)
	{
		std::cout << "The vampire's skin sizzles as the water touches his skin." << std::endl;
		this->hp = hp - dmg;
	}
	else if (dmg == 100)
	{
		std::cout << "You launch the stone imbued with holy powers." << std::endl;
		this->hp = hp - 100;
	}
	else if (dmg == 150)
	{
		std::cout << "'Where did you find that sword? It is mine!' Your blade glows with divine power as you stab the vampire through its heart." << std::endl;
		this->hp = hp - dmg;
	}
}