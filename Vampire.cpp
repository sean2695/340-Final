#include "Vampire.h"



//constructor

Vampire::Vampire(std::string name) : Monster(name)

{



}



// the attack for the skeleton

void Vampire::attack()

{

	std::cout << "The blood sucking vampire lunges your way looking to end your life and feast on you" << std::endl;

}
