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


