#pragma once
#include "Ghost.h"

class Poltergeist : public Ghost
{
public:
	//contructor
	Poltergeist(std::string name);
	// function call attack for enemy
	void haunt();

};

