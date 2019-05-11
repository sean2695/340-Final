#include <vector>
#include <iostream>
#include "Combat.h"
#include "Door.h"
#include "RoomSetUp.h"


int main()
{
	//create the Room, vector for the dungeon, and player
	Room* currentRoom;
	std::vector<Room*> dungeon;
	std::string userInput;
	Player player = Player();
	//create the roomsetup object and call its functions to create the dungeon
	RoomSetUp setUp = RoomSetUp();
	dungeon = setUp.MapMaker(dungeon);
	dungeon = setUp.setItems(dungeon);
	dungeon = setUp.setEnemies(dungeon);


	//set locked doors
	dungeon[0]->setCanLeaveNorth(false);
	Door frontDoor = Door("HouseKey");
	dungeon[4]->setCanLeaveEast(false);
	Door basementDoor = Door("BasementKey");
	dungeon[6]->setCanLeaveNorth(false);
	Door LibraryDoor = Door("LibraryKey");
	dungeon[8]->setCanLeaveEast(false);


	//set currentRoom equal to the first
	currentRoom = dungeon[0];
	
	//print openeing dialouge
	std::cout << "You enter through a rusty gate to find yourself in a run down courtyard. The building you have come to explore lays before you, but as you step into the grounds an ghostly aparition of a butler appears." << std::endl;
	std::cout << currentRoom->getDescription() << std::endl;
	//while loop to read player commands
	while (userInput != "QUIT")
	{
		// if player is in the final room start the boss fight
		if (currentRoom == dungeon[10])
		{
			player.combatLoop(currentRoom, dungeon, player);
		}
		//read the user input
		std::cout << "Enter Command: " << std::endl;
		std::getline(std::cin, userInput);
		//parse the string to get action and object
		std::size_t space = userInput.find(" ");
		std::string action = userInput.substr(0, space);
		std::string object = userInput.substr(space + 1, userInput.size() - 1);

		//determine which action is typed and do the apprioriate if statement
		if (action == "Move" || action == "move" || action == "MOVE")
		{
			if (object == "NORTH" || object == "EAST" || object == "SOUTH" || object == "WEST")
			{
				currentRoom = currentRoom->getRoom(object);
			}
			else
			{ 
				std::cout << "Not a valid direction." << std::endl;
			}
		}
		else if (action == "search" || action == "Search" || action == "SEARCH")
		{  
			currentRoom = player.search(dungeon, currentRoom, object);
			if (object == "THE SHINING" )
				currentRoom->setCanLeaveEast(true);
		}
		else if (action == "take" || action == "Take" || action == "TAKE")
		{
			if (currentRoom->cantakeItems)
			{
				int index = 0;
				for (Item e : currentRoom->getItemsInRoom())
				{
					if (object == "key" || object == "Key" || object == "KEY")
					{
						if (currentRoom == dungeon[2])
						{
							object = "HouseKey";
							currentRoom->eventInRoom.skeletonRises();
							player = player.combatLoop(currentRoom, dungeon, player);
						}
						if (currentRoom == dungeon[4])
						{
							object = "LibraryKey";
						}
						if (currentRoom == dungeon[8])
						{
							object = "BasementKey";
						}
					}
					if (object == "SHOVEL")
					{
						std::cout << "A groan sounds as you reach for the shovel and a zombie stunbles toward you to protect it." << std::endl;
						player = player.combatLoop(currentRoom, dungeon, player);
					}
					if (e.getName() == object)
					{
						player.take(e);
						currentRoom->removeItems(object);
						std::cout << object + " taken" << std::endl;
						break;
					}	
					if (index == currentRoom->getItemsInRoom().size() -1)
					{
						std::cout << "No items can be found." << std::endl;
					}
					index++;
				}
				
			}
			
			
		}
		else if (action == "open" || action == "Open" || action ==  "OPEN")
		{
			if (currentRoom == dungeon[0])
				frontDoor.openDoor(player, currentRoom);
			else if (currentRoom == dungeon[4])
				basementDoor.openDoor(player, currentRoom);
			else if (currentRoom == dungeon[6])
				LibraryDoor.openDoor(player, currentRoom);
			else
				std::cout << "You need to open your mind and think of a better option." << std::endl;
		}
		else if (action == "look" || action == "Look" || action == "LOOK")
		{
			std::cout << currentRoom->getDescription() << std::endl;
		}
		else if (action == "inventory" || action == "Inventory" || action == "INVENTORY")
		{
			player.displayInventory();
		}
		else if (action == "use" || action == "Use" || action == "USE")
		{
			player.use(object, currentRoom);
		}
		else if (action == "HELP")
		{
			std::cout << "For best results keep CAPS LOCK on. Options are \nmove/Move/MOVE (NORTH, EAST, SOUTH, WEST) \ntake/Take/TAKE (item to take) \ninventory/Inventory/INVENTORY to display your items \nlook/Look/LOOK to get the current room's description \nopen/Open/OPEN to unlock any locked doors \nsearch/Search/SEARCH to investigate certain objects around a room \nuse (item) to use an item (only works in certain scenarios) " << std::endl;
		}
	}

}