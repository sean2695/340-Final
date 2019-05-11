#include "Door.h"


//constructor
Door::Door(std::string keyNeeded)
{
	this->keyNeeded = keyNeeded;
}

//function to check if player can open a door
void Door::openDoor(Player player, Room* room)
{
	// if the door is locked
	if (!room->getCanleaveNorth() || !room->getCanLeaveEast())
	{
		//if the player had the correct key
		if (player.inventoryContains(keyNeeded))
		{
			// set the locked exit to unlocked
			room->setCanLeaveNorth(true);
			room->setCanLeaveEast(true);
			std::cout << "The key turns in the rust lock and the way is now open." << std::endl;
		}
		// otherwise tell the player they dont have the key
		else
		{
			std::cout << "The key to success is having the correct item." << std::endl;
		}
	}
}

