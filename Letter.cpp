#include "Letter.h"


//constructor
Letter::Letter(std::string name) : Item (name)
{
}

//print off the text the player can read off the letter
void Letter::read()
{
	std::cout << "Carson Williams, \nI regret to inform you that due to your innapropriate behavior involving the lady of the hosue, I will have to terminate your employement. Please be off the grounds by tommorow night. A new butler will be found. \nBest Wishes \nPaul Torgeist " << std::endl;
}