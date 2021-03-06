#pragma once
#include <vector>
#include "Room.h"
#include "HolyWater.h"
#include "GhostVacuum.h"
#include "Letter.h"
#include "Journal.h"
#include "Potion.h"
#include "SuperPotion.h"
#include "BlessedRock.h"
#include "MagicBook.h"
#include <stdlib.h>
#include <ctype.h>		//toupper()
#include <algorithm>    // std::transform
#include <list>
#include <time.h>       /* time */

class Player
{
public:

	//constructor for player
	Player();

	//player commands
	Room* search(std::vector <Room*> dungeon, Room* currentRoom, std::string searching);
	void take(Item item);
	void look(Room* room);
	void displayInventory();
	void lowerHP();
	bool inventoryContains(std::string item);
	Room* use(std::string object, Room* room);
	//makes strings all upper
	std::string Sanitize(std::string word);
	// getter for the player inventory
	std::vector <Item> getInventory();
	//getter for the player Hp
	int getHp();

	void setMagic();

	MagicBook* getMagicBook();

	//method to run to intiate combat
	Player combatLoop(Room* room, std::vector<Room*> dungeon, Player player);

private:
	//player hp
	int hp;
	//player inventory
	std::vector <Item> inventory;
	//boolean to express if player can use magic

	MagicBook* magic = new MagicBook();
};

