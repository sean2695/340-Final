#include "Poltergeist.h"



Poltergeist::Poltergeist(std::string name) : Ghost(name)
{
}

//the attack for the poltergeist
void Poltergeist::haunt()
{
	std::cout << "The poltergeist fling objects in the room at you, bludgeoning you with the force." << std::endl;
}
