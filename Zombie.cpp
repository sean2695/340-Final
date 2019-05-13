#include "Zombie.h"


//constructor
Zombie::Zombie(std::string name) : Undead(name)
{

}

//attack for the zombie
void Zombie::bite()
{
	std::cout << "The zombie groans as its rotting fingers clutches you. The smell of death lingers on its breath as the few remaining teeth chomp on you." << std::endl;
	
}