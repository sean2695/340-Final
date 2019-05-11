#include "Journal.h"



Journal::Journal(std::string name) : Item (name)
{
	
}

//print out the text that the player can read off the journal
void Journal::read()
{
	std::cout << "The worn pages of the journals leaves little to be read. One page however is still legible. 'Today was an eventful one, after an incident with Carson blew up into a falling out, I had to let him go. I always find solace however reading my favorite book, The Shining. Oh that Stephen King knows how to spin a yarn.' " << std::endl;
}