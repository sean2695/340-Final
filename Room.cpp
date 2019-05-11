#include "Room.h"


//constructor
Room::Room(std::string description)
{
	this->description = description;
}

//return room description
std::string Room::getDescription()
{
	return this->description;
}

//connect the rooms to another room
void Room::connectRooms(Room* north, Room* east, Room* south, Room* west)
{
	this->northRoom = north;
	this->eastRoom = east;
	this->southRoom = south;
	this->westRoom = west;
}

//move in the direction indicated
Room* Room::getRoom(std::string direction)
{
	// check what direction, if it isnt null, and if it isnt a locked door then print out the description and return it)
	if (direction == "NORTH" && this->northRoom != nullptr && this->canLeaveNorth == true)
	{
		std::cout << northRoom->getDescription() << std::endl;
		return this->northRoom;
	}
	if (direction == "EAST" && this->eastRoom != nullptr && this->canLeaveEast == true)
	{
		std::cout << eastRoom->getDescription() << std::endl;
		return this->eastRoom;
	}
	if (direction == "SOUTH" && this->southRoom != nullptr && this->canLeaveSouth == true)
	{
		std::cout << southRoom->getDescription() << std::endl;
		return this->southRoom;
	}
	if (direction == "WEST" && this->westRoom != nullptr && this->canLeaveWest == true)
	{
		std::cout << westRoom->getDescription() << std::endl;
		return this->westRoom;
	}
	//otherwise return the same room
	else
	{
		if (canLeaveNorth == false && (direction != "SOUTH" && direction != "WEST"))
		{
			std::cout << "The door is locked." << std::endl;
		}
		std::cout << this->getDescription() << std::endl;
		return this;
	}

}

//setters for can leave in specific directions
void Room::setCanLeaveNorth(bool canLeave)
{
	this->canLeaveNorth = canLeave;
}

void Room::setCanLeaveEast(bool canLeave)
{
	this->canLeaveEast = canLeave;
}

void Room::setCanLeaveSouth(bool canLeave) 
{
	this->canLeaveSouth = canLeave;
}

void Room::setCanLeaveWest(bool canLeave)
{
	this->canLeaveWest = canLeave;
}

//getters for if you can leave in any direction
bool Room::getCanleaveNorth()
{
	return this->canLeaveNorth;
}

bool Room::getCanLeaveEast()
{
	return this->canLeaveEast;
}

//return the vector of items in the room
std::vector<Item> Room::getItemsInRoom()
{
	return this->roomItems;
}

//add an item to the vector in the room
void Room::addItem(Item item)
{
	this->roomItems.push_back(item);
}

//set if the room allows the player to take items
void Room::setCanTakeItems()
{
	this->cantakeItems = true;
}

//get enemies from room

HeadlessPriest* Room::getPriest()
{
	return this->priest;
}

Zombie* Room::getZombie()
{
	return this->zombie;
}

Skeleton* Room::getSkeleton()
{
	return this->skeleton;
}

Poltergeist* Room::getPoltergeist()
{
	return this->poltergeist;
}

HauntedArmor* Room::getArmor()
{
	return this->armor;
}

ButlerBoss* Room::getButler()
{
	return this->butler;
}

// setters for enemies

void Room::setZombie(Zombie* zombie)
{
	this->zombie = zombie;
}


void Room::setPriest(HeadlessPriest* priest)
{
	this->priest = priest;
}

void Room::setSkeleton(Skeleton* skeleton)
{
	this->skeleton = skeleton;
}


void Room::setHauntedArmor(HauntedArmor* armor)
{
	this->armor = armor;
}


void Room::setPoltergeist(Poltergeist* poltergeist)
{
	this->poltergeist = poltergeist;
}

void Room::setButlerBoss(ButlerBoss* butler)
{
	this->butler = butler;
}

//remove items from room after they have been taken
void Room::removeItems(std::string object)
{
	int index = 0;
	for (Item e : this->roomItems)
	{
		if (e.getName() == object)
			this->roomItems.erase(this->roomItems.begin() + index);
		index++;
	}
}
