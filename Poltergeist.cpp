#include "Poltergeist.h"



Poltergeist::Poltergeist(std::string name) : Ghost(name)
{
}

//the attack for the poltergeist
void Poltergeist::haunt()
{
	std::cout << "The poltergeist fling objects in the room at you, bludgeoning you with the force." << std::endl;
}


void Poltergeist::lowerHp(int dmg)
{
	if (dmg == -1)
	{
		std::cout << "Your hand swings at nothing but air, and you feel foolish as laugh echoes around the room from the spirit." << std::endl;
		this->hp = hp - dmg;
	}
	if (dmg == 1)
	{
		std::cout << "You strike at the now embodied spirit with your fists, your punch striking it in the gut." << std::endl;
		this->hp = hp - dmg;
	}
	if (dmg == 0)
	{
		this->hp = hp - dmg;
		std::cout << "You feel a presence behind you and you turn cleaving the empty space with a downward slash but strike nothing." << std::endl;
	}
	if (dmg == 2)
	{
		std::cout << "Your sword slices the now solid spectre, cuasing it to ooze ectoplasm as if it were bleeding." << std::endl;
		this->hp = hp - dmg;
	}
	if (dmg == 50)
	{
		std::cout << "You spray the corners of the room with holy water, and a hiss bleeds from the walls" << std::endl;
		this->hp = hp - dmg;
	}
	if (dmg == 100)
	{
		std::cout << "The ghost lets loose a blood curdling scream and you feel the evil presence fade from the room." << std::endl;
		this->hp = hp - dmg;
	}
	if (dmg == 98)
	{
		std::cout << "A phantom takes form room, presenting a body to strike." << std::endl;
		this->isCorporal = true;
		this->hp = 2;
	}
	if (dmg == 101)
	{
		std::cout << "The vacuum humms as the spirit is pulled into and trapped." << std::endl;
		this->hp = hp - dmg;
	}
}