#include "MagicBook.h"


//constructor
MagicBook::MagicBook()
{

}

//reads the spells you can use
void MagicBook::displaySpells()
{
	if (magicLevel == 0)
		std::cout << "Do I need to spell it out for you, you have no magic yet." << std::endl;
	else if (magicLevel == 1)
		std::cout << "The spells in this tome are make corporal." << std::endl;
	else if (magicLevel == 2)
		std::cout << "Spells are are make corporal and banish" << std::endl;
	else if (magicLevel == 3)
		std::cout << "The spells in this tome are make corporal, banish, and Charm." << std::endl;
	else if (magicLevel == 4)
		int a = 1;
}

void MagicBook::increaseMagicLevel()
{
	this->magicLevel++;
}

void MagicBook::expGain(std::string enemy)
{
	if (enemy == "Zombie")
		this->magicExp++;
	else if (enemy == "Skeleton" || enemy == "Snake" || enemy == "Library Spirit")
		this->magicExp = magicExp + 2;
	else if (enemy == "Wolf" || enemy == "Vampire")
		this->magicExp = magicExp + 4;
	else if (enemy == "Dining Room Spirit")
		this->magicExp = magicExp + 5;
	else if (enemy == "Haunted Armor" || enemy == "Ghoul" || enemy == "Wight")
		this->magicExp = magicExp + 6;
	else if (enemy == "Carson")
		this->magicExp = magicExp + 8;
	if (magicExp >= 8)
	{
		this->increaseMagicLevel();
		magicExp = magicExp - 8;
	}
}

bool MagicBook::getCanUseMagic()
{
	return this->canUseMagic;
}

//set if the players can use magic
void MagicBook::setCanUseMagic()
{
	this->canUseMagic = true;
}

int MagicBook::getMagicLevel()
{
	return this->magicLevel;
}