#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include "Event.h"
#include <iostream>
#include "Zombie.h"
#include "Skeleton.h"
#include "Poltergeist.h"
#include "HeadlessPriest.h"
#include "HauntedArmor.h"
#include "ButlerBoss.h"
#include "Snake.h"
#include "Wolf.h"
#include "Lever.h"

class Room
{
public:
	//constructor
	Room(std::string description);
	//return description
	std::string getDescription();
	//connect rooms 
	void connectRooms(Room* north, Room* east, Room* west, Room* south);
	Room* getRoom(std::string direction);

	//setters to lock/unlock exits
	void setCanLeaveNorth(bool canLeave);
	void setCanLeaveEast(bool canLeave);
	void setCanLeaveSouth(bool canLeave);
	void setCanLeaveWest(bool canLeave);

	//getters to see if you can leave
	bool getCanleaveNorth();
	bool getCanLeaveEast();

	// return the vector of items in room
	std::vector<Item> getItemsInRoom();
	// add an item to the room's vector of items
	void addItem(Item item);
	// set if player is allowed to take item from room
	void setCanTakeItems();
	// if players can take items or not
	bool cantakeItems = false;
	//remove items from the room's vector
	void removeItems(std::string object);



	//enemy getters
	HeadlessPriest* getPriest();
	Zombie* getZombie();
	Skeleton* getSkeleton();
	HauntedArmor* getArmor();
	Poltergeist* getPoltergeist();
	ButlerBoss* getButler();

	Snake* getSnake();
	Wolf* getWolf();

	//enemy setters
	void setPriest(HeadlessPriest* priest);
	void setZombie(Zombie* zombie);
	void setSkeleton(Skeleton* skeleton);
	void setHauntedArmor(HauntedArmor* armor);
	void setPoltergeist(Poltergeist* poltergeist);
	void setButlerBoss(ButlerBoss* butler);

	void setSnake(Snake* snake);
	void setWolf(Wolf* wolf);
	// Event object to intiate certain game events
	Event eventInRoom = Event();

	Lever* getLever();


private:

	//Items
	std::vector <Item> roomItems;
	//Enemies
	Zombie* zombie;
	Skeleton* skeleton;
	HeadlessPriest* priest;
	Poltergeist* poltergeist;
	HauntedArmor* armor;
	ButlerBoss* butler;

	Snake* snake;
	Wolf* wolf;
	//description
	std::string description;

	//Connections to other rooms
	Room* northRoom;
	Room* eastRoom;
	Room* westRoom;
	Room* southRoom;

	//If the door is locked
	bool canLeaveNorth = true;
	bool canLeaveEast = true;
	bool canLeaveWest = true;
	bool canLeaveSouth = true;

	Lever* bossLever = new Lever();
};