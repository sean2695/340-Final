#include "Skeleton.h"

//constructor
Skeleton::Skeleton(std::string name) : Undead(name)
{

}

// the attack for the skeleton
void Skeleton::attack()
{
	std::cout << "The skeletal arm falshes in your direction, striking you switfly in the gut." << std::endl;
}
