#pragma once
#include "Player.h"
#include "MagicBook.h"

class Combat
{
public:
	Combat();

	void combatLoop(Room* room, std::vector<Room*> dungeon, Player player);

};


