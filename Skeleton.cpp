#include "Skeleton.h"

//constructor
Skeleton::Skeleton(std::string name) : Undead(name)
{

}

// the attack for the skeleton
void Skeleton::attack()
{
	std::cout << "The skeletal arm falshes in your direction, striking you switfly in the gut." << std::endl;\
		void lowerHp();
}


void Skeleton::lowerHp(int dmg)
{
	if (dmg = 1)
	{
		std::cout << "You throw a punch agaisnt the skeleton exposed ribcage." << std::endl;
		this->hp - dmg;
	}
	if (dmg = 2)
	{
		std::cout << "Your sword bounces of the skull of the creature, leaving a large dent." << std::endl;
		this->hp = hp - dmg;

	}
	if (dmg = 3)
	{
		std::cout << "You sweep your shovel under its legs knocking them away and crumbling the remaining bones into an oddly stacked pile." << std::endl;
		this->hp = hp - dmg;
	}
}
