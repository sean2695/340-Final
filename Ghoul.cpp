#include "Ghoul.h"

//constructor



Ghoul::Ghoul(std::string name) : Monster(name)
{

}



// the attack for the Ghoul

void Ghoul::attack()
{
	std::cout << "The shapeshifting ghoul approaches looking to cause serious harm" << std::endl;
}


void Ghoul::lowerHp(int dmg)
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
	}
	else if (dmg == 3)
	{
		std::cout << "The fire lights its fur a flame and it rolls along the ground to put it out, leaving behind a large burn." << std::endl;
		this->hp = hp - 3;
	}
}