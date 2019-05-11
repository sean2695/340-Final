#pragma once
#include <vector>
#include <string>
#include "Item.h"
#include "Room.h"
#include "Sword.h"
#include "Letter.h"
#include "GhostVacuum.h"
#include "Journal.h"
#include "Key.h"
#include "HolyWater.h"
#include "Shovel.h"
#include "Head.h"

class RoomSetUp
{
public:
	//constructor
	RoomSetUp();
	//set all the items in the rooms
	std::vector<Room*> setItems(std::vector<Room*> dungeon);
	//set all the enemies in the rooms
	std::vector<Room*> setEnemies(std::vector<Room*> dungeon);
	//construct the rooms and vector of rooms, and establish the connections
	std::vector<Room*> MapMaker(std::vector<Room*> dungeon);

};

