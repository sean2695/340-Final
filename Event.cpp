#include "Event.h"


//constructor
Event::Event()
{
}

//functions for the different events that trigger in game
void Event::digOutGrave()
{
	std::cout << "The loose dirt gives way easily, unveiling an old wooden coffin with its lid rotted away. Inside lays an old forgotten skeleton clutching an iron key." << std::endl;
}

void Event::skeletonRises()
{
	std::cout << "A creak sounds from the pit in the earth, and slowly the musty bones rise up from the grave. The empty sockets fixate on you and the jaws clack as it speaks, 'I got a bone to pick with you! Thats my key!'" << std::endl;
}

void Event::headlessPriestDialouge()
{
	std::cout << "A spectre appears before you as try to reach the altar blocking your path. He wears the garb of a priest, but is missing his head. A disembodied voice sounds from the stump of its neck \n Give it back! Give it BACK." << std::endl;
}

void Event::headlessPriestDissapears()
{
	std::cout << "Oh my old friend, how I've missed you. Thank you for returning it to me, that is how you get a head in life." << std::endl;
}

void Event::hauntedArmorMoves()
{
	std::cout << "A hollow moan rings out from inside the armor, and it begins moving on its own. It steps off the pedestal and stands before you." << std::endl;
}

void Event::PoletergeistThrowsFood()
{
	std::cout << "A phantom cackle sounds from all around as the rotting fruit still resting on the table begins flinging itself at you. \n A poltergeist is in this room. And the door slams shut." << std::endl;
}

void Event::ZombieAttacksFromCloset()
{
	std::cout << "As you open the closet door, movement burts from within as a body stumbles out and you find yourself facing a zombie." << std::endl;	
}

void Event::BookshelfMoves()
{
	std::cout << "As you pull the book you hear a click, and the bookshelf slides away to reveal an open doorframe leading into another room to the east." << std::endl;
}

void Event::ghouls_surface()
{
	std::cout << "As you enter the cavern you see nothing but the glowing eyes of the shapeshifting ghouls that are hungry to rip you apart" << std::endl;
}

void Event::vampireFeeds()
{
	std::cout << "Vampieres feed on your dead body" << std::endl;
}


