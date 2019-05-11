#pragma once
#include "Key.h"
#include "Player.h"
#include "Room.h"

class Door
{
public:
	// constructor
	Door(std::string keyNeeded);
	// check if player has necessary key to open door and make it unlocked if so
	void openDoor(Player player, Room* room);

private:
	// the name of the key needed to open the door
	std::string keyNeeded;
};
