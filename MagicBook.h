#pragma once
#include "Ghost.h"

class MagicBook
{
public:
	//constructor
	MagicBook();
	// print out the spells you can use
	void displaySpells();
	//increase the magic level
	void increaseMagicLevel();
	void expGain(std::string enenmy);
	// getter for the boolean to allow magic
	bool getCanUseMagic();
	// setter to allow magic
	void setCanUseMagic();

	int getMagicLevel();

private:
	int magicExp = 0;
	int magicLevel = 0;
	bool canUseMagic = false;
};
