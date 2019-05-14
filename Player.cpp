#include "Player.h"


//constructor
Player::Player()
{
	this->hp = 8;
}

//function to search the rooms for certain key words
Room* Player::search(std::vector<Room*> dungeon, Room* room, std::string searching)
{
	// create an event object to call when event is triggered
	Event eventInRoom = Event();
	// cycle through every room in the dungeon to see which the current room matches too
	int searchRoom = -1;
	for (int i = 0; i < dungeon.size();i++)
	{
		if (room == dungeon[i])
			searchRoom = i;
	}
	// call a switch case based on which room you are currently in
	switch (searchRoom)
	{
		// if case is 0 then search in dungeon[0] for key words
	case 0:
		if (searching.find("SWORD") != std::string::npos || searching.find("KNIGHT") != std::string::npos || searching.find("SHIELD") != std::string::npos)
		{
			std::cout << "The gallant knight stands watch of the courtyard, raising his shield firm in his grip as if to ward off attacks, but you notice his sword looks loose in his other hand." << std::endl;
		}
		std::cout << "There is nothing of interest in that object" << std::endl;
		break;
	case 1:
		// if case is 1 then search in dungeon[1] for key words
		std::cout << "There is nothing of interest here" << std::endl;
		break;
	case 2:
		// if case is 1 then search in dungeon[1] for key words
		if (searching.find("GRAVE") != std::string::npos || (searching.find("SHOVEL") != std::string::npos && this->inventoryContains(searching)))
		{
			//check to see if grave was already dug out
			if (room->cantakeItems)
			{
				bool takenKey = true;
				for (Item e : room->getItemsInRoom())
				{
					if (e.getName() == "HouseKey")
					{
						takenKey = false;
						break;
					}
				}
				if (takenKey)
					std::cout << "Its an empty grave." << std::endl;
				else
					std::cout << "Its a grave dug out with a skeleton clutching a key." << std::endl;
				break;
			}
			//if grave wasn't dug out check if player has shovel and dig it out
			if (this->inventoryContains("SHOVEL"))
			{
				eventInRoom.digOutGrave();
				room->setCanTakeItems();
			}
			else
				std::cout << "You've made a grave mistake, I'd like to see you dig your way out of this one." << std::endl;
		}
		//if the player typed something else than print
		else
			std::cout << "There is nothing of interest in that object" << std::endl;
		break;
	case 3:
		// if case is 3 then search in dungeon[3] for key words
		if (searching.find("BASIN") != std::string::npos)
		{
			std::cout << "The basin bubbles with Holy Water, said to injure evil spirits." << std::endl;
		}
		else if (searching.find("ALTAR") != std::string::npos)
		{
			//check to see if the priest is defeated
			if (room->getPriest()->getisDefeated() == false)
			{
				//if not check to see if player inventory contains head
				if (!(this->inventoryContains("HEAD")))
					eventInRoom.headlessPriestDialouge();
				else
				{
					// call event let player use magic and remove head from inventory
					eventInRoom.headlessPriestDissapears();
					room->getPriest()->setDefeated();
					std::cout << "The book on the altar contains magic meant to fight wicked spectres. You have learned two of the spells conatined within." << std::endl;
					this->getMagicBook()->setCanUseMagic();
					int index = 0;
					for (Item e : inventory)
					{
						if (e.getName() == "HEAD")
							this->inventory.erase(this->inventory.begin() + index);
						index++;
					}
				}
			}
			else
			{
				std::cout << "Its an altar containing the book on magic. The remaining spells are too complex for you to learn." << std::endl;
			}
		}
		else
			std::cout << "There is nothing of interest in that object" << std::endl;
		break;
	case 4:
		// if case is 0 then search in dungeon[0] for key words
		if (searching.find("PAINTING") != std::string::npos)
		{
			std::cout << "The eyes of all the previous Masters follow you as you stride towards them. However the previous master's painting stares off to a suit of armor on the wall." << std::endl;
		}
		//if they search armor than the armor attacks them
		else if (searching.find("ARMOR") != std::string::npos)
		{
			eventInRoom.hauntedArmorMoves();
			*this = this->combatLoop(room, dungeon, *this);
			std::cout << "The pieces of armor clatter to the ground, and inside the chestpiece you can see a key." << std::endl;
			room->setCanTakeItems();
		}
		else
			std::cout << "There is nothing of interest in that object" << std::endl;
		break;
	case 5:
		//// if case is 5 then search in dungeon[5] for key words
		if (searching.find("PLATE") != std::string::npos)
		{
			//if they searched plate then poltergeist fights them
			if (room->cantakeItems == false)
			{
				eventInRoom.PoletergeistThrowsFood();
				*this = this->combatLoop(room, dungeon, *this);
				room->setCanTakeItems();
			}
		}
		else
			std::cout << "There is nothing of interest in that object" << std::endl;
		break;
	case 6:
		// if case is 6 then search in dungeon[6] for key words
		std::cout << "There is nothing of interest here" << std::endl;
		break;
	case 7:
		// if they search closet than zombie fights them
		if (searching.find("CLOSET") != std::string::npos)
		{
			if (room->getZombie()->getisDefeated() == false)
			{
			eventInRoom.ZombieAttacksFromCloset();
			*this = combatLoop(room, dungeon, *this);
			}
			else
			{
			std::cout << "An empty closet, clutter with the remains of the slain zombie." << std::endl;
			}
		}
		if (searching.find("WINDOW") != std::string::npos)
		{
			bool journalTaken = true;
			for (Item e : room->getItemsInRoom())
			{
				if (e.getName() == "JOURNAL")
				{
					std::cout << "The piece of paper seems to be a letter." << std::endl;
					journalTaken = false;
				}
			}
			if (journalTaken)
				std::cout << "Its a desk with nothing on it." << std::endl;
			std::cout << "On the window seat you notice a leather bound journal." << std::endl;
		}
		else
			std::cout << "There is nothing of interest in that object" << std::endl;
		break;
	case 8:
		// if case is 8 then search in dungeon[8] for key words
		if (searching.find("BOOKCASE") != std::string::npos)
		{
			// if they search bookcase then poltergeist attacks them
			std::cout << "A sparce few books line the shelves you can see the titles: And Then There Was None, To Kill A MockingBird, The Shining, and Lord of The Flies." << std::endl;
			if (room->getPoltergeist()->getisDefeated() == false)
			{
				std::cout << "You hear a voice whisper from behind you, stay away there!" << std::endl;
				*this = combatLoop(room, dungeon, *this);\
			}
		}
		// if they search the shining the bookcase opens
		else if (searching.find("THE SHINING") != std::string::npos && room->getCanLeaveEast() == false)
		{
			eventInRoom.BookshelfMoves();
			room->setCanLeaveEast(true);
		}
		else if (searching.find("DESK") != std::string::npos)
		{
			std::cout << "You search the drawers of the desk, and in the top drawer you see a small key under some papers." << std::endl;
			room->setCanTakeItems();
		}
		else
			std::cout << "There is nothing of interest in that object" << std::endl;
		break;
	case 9:
		// if case is 9 then search in dungeon[9] for key words
		if (searching.find("BACKPACK") != std::string::npos || searching.find("mannequin") != std::string::npos)
		{

			std::cout << "The backpack beeps faintly as led lights flash blue and green. There is a small sticked on one side that reads \n'The Who Yah Gonna Call V 2.0 \nNow with 5x times the suction! \nJust point it at a ghost, turn it on, and watch it suck harder than Monica Lewinsky'" << std::endl;
		}
		else if (searching.find("DESK") != std::string::npos || searching.find("paper") != std::string::npos)
		{
			bool letterTaken = true;
			for (Item e : room->getItemsInRoom())
			{
				if (e.getName() == "LETTER")
				{
					std::cout << "The piece of paper seems to be a letter." << std::endl;
					letterTaken = false;
				}
			}
			if (letterTaken)
				std::cout << "Its a desk with nothing on it." << std::endl;

		}
		else
			std::cout << "There is nothing of interest in that object" << std::endl;
		break;
	case 10:
		break;
	case 11:
		break;
	case 12:
		if (searching.find("COFFIN") != std::string::npos)
		{
			std::cout << "You pry off the lid to the coffin and see the eyes of a vampire staring back at you. 'Who wakes me from my slumber' " << std::endl;
		}
		else
			std::cout << "There is nothing of interest in that object" << std::endl;
		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		if (searching.find("ROCK") != std::string::npos)
		{
			std::cout << "You lift the rock up to notice a dug hole beneath it with a lever hidden there." << std::endl;
		}
		else if (searching.find("LEVER") != std::string::npos)
		{
			std::cout << "You hear a soft click as you pull the lever." << std::endl;
			dungeon[15]->getLever()->setIsPulled();
		}
		else
			std::cout << "There is nothing of interest in that object" << std::endl;
		break;
	case 16:
		if (searching.find("LAKE") != std::string::npos)
		{
			std::cout << "You look into the cold waters of the lake, and notice the glow to belong to a sword shich blades shines as if by magic." << std::endl;
		}
		else
			std::cout << "There is nothing of interest in that object" << std::endl;
		break;
	case 17:
		if (searching.find("IVY") != std::string::npos)
		{
			std::cout << "You push aside the ivy and see a lever behind it." << std::endl;
		}
		else if (searching.find("LEVER") != std::string::npos)
		{
			std::cout << "You hear a soft click as you pull the lever." << std::endl;
			dungeon[17]->getLever()->setIsPulled();
		}
		else
			std::cout << "There is nothing of interest in that object" << std::endl;
		break;
	case 18:
		if (searching.find("DOOR") != std::string::npos || searching.find("EXIT") != std::string::npos)
		{
			if (dungeon[15]->getLever() || dungeon[17]->getLever())
			{
				std::cout << "The giant door opens and an ominous hallway lies beyond it." << std::endl;
				dungeon[18]->setCanLeaveNorth(true);
			}
			else
				std::cout << "The door is locked with no keyhole in sight." << std::endl;
		}
		break;
	case 19:
		break;
	}
	return room;
}

//add item to players inventory
void Player::take(Item item)
{
	this->inventory.push_back(item);
}

//get the room description
void Player::look(Room* room)
{
	std::cout << room->getDescription() << std::endl;
}

//show all items in the player inventory
void Player::displayInventory()
{
	for (Item e : this->inventory)
	{
		std::cout << e.getName() << std::endl;
	}
}

//lower the players hp and print it
void Player::lowerHP()
{
	this->hp--;
	std::cout << "The player's HP is now: " << this->hp << std::endl;
}

//check if the players inventory has a specific item
bool Player::inventoryContains(std::string item)
{
	for (Item e : this->inventory)
	{
		if (e.getName() == item)
		{
			return true;
		}
	}
	return false;
}

//have the player use specific items
Room* Player::use(std::string object, Room* room)
{

	if (object == "LETTER")
	{
		Letter letter = Letter("LETTER");
		letter.read();
	}
	else if (object == "JOURNAL")
	{
		Journal journal = Journal("JOURNAL");
		journal.read();
	}

	return room;
}

//return the players inventory
std::vector<Item> Player::getInventory()
{
	return this->inventory;
}

//return the players hp
int Player::getHp()
{
	return this->hp;
}

//return the player magicbook
MagicBook* Player::getMagicBook()
{
	return this->magic;
}


void Player::setMagic()
{
	this->magic = new MagicBook();
}



//run loops depending on the current room to fight agaisnt the appropriate enemy 
Player Player::combatLoop(Room* room, std::vector<Room*> dungeon, Player player)
{
	// weapon the player choose to use
	std::string weapon;
	int dmg = 0;
	//determine which room it is and select the correct enemy
	if ((room == dungeon[1] || room == dungeon[7]) && room->getZombie()->getisDefeated() == false)
	{
		Zombie* enemy = room->getZombie();
		std::cout << "The " + enemy->getName() + " attacks!" << std::endl;
		//continue running loop until player or enemy are dead
		while (player.getHp() > 0)
		{
			while (true)
			{
				//pick weapon and check if its valid
				std::cout << "Enter a weapon to use (fist or item) type inventory to see the items in your possession" << std::endl;
				std::getline(std::cin, weapon);
				if (weapon == "FIST" || (weapon == "SWORD" && this->inventoryContains("SWORD")) || (weapon == "SHOVEL" && this->inventoryContains("SHOVEL")))
				{
					break;
				}
				if (weapon == "INVENTORY")
				{
					player.displayInventory();
				}
				else
					std::cout << "You want to use " << weapon << " to attack?" << std::endl;
			}
			//depending on which weapon selected preform action
			if (weapon == "FIST")
				dmg = 1;
			if (weapon == "SHOVEL")
				dmg = 2;
			if (weapon == "SWORD")
				dmg = 3;
			enemy->lowerHp(dmg);
			// if enemy isn't dead it attacks
			if (enemy->getHp() > 0)
			{
				enemy->bite();
				player.lowerHP();
			}
			else
				break;
		}
		// if player hp is 0 then game over
		if (player.getHp() <= 0)
		{
			std::cout << "Your life bleeds from your body, but you feel your spirit remain trapped in the home, cursed to forever be a spirit haunting the grounds like so many others." << std::endl;
			exit(0);
		}
		//otherwise set the enemy to defeated
		std::cout << "The " + enemy->getName() + " falls to your attack" << std::endl;
		player.getMagicBook()->expGain(enemy->getName());
		room->getZombie()->setisDefeated();
	}
	//determine which room it is and select the correct enemy

	else if (room == dungeon[2] && room->getSkeleton()->getisDefeated() == false)
	{
		Skeleton* enemy = room->getSkeleton();
		std::cout << "The " + enemy->getName() + " attacks!" << std::endl;
		//continue running loop until player or enemy are dead
		while (player.getHp() > 0)
		{
			//pick weapon and check if its valid
			while (true)
			{
				std::cout << "Enter a weapon to use (fist or item) type inventory to see the items in your possession" << std::endl;
				std::getline(std::cin, weapon);
				if (weapon == "FIST" || (weapon == "SWORD" && this->inventoryContains("SWORD")) || (weapon == "SHOVEL" && this->inventoryContains("SHOVEL")))
				{
					break;
				}
				else if (weapon == "INVENTORY")
				{
					player.displayInventory();
				}
				else
					std::cout << "You want to use " << weapon << " to attack?" << std::endl;
			}
			//depending on which weapon selected preform action
			if (weapon == "FIST")
				dmg = 1;
			if (weapon == "SWORD")
				dmg = 2;
			if (weapon == "SHOVEL")
				dmg = 3;
			enemy->lowerHp(dmg);
			// if enemy isn't dead it attacks
			if (enemy->getHp() > 0)
			{
				enemy->attack();
				player.lowerHP();
			}
			else
				break;
		}
		// if player hp is 0 then game over
		if (player.getHp() <= 0)
		{
			std::cout << "Your life bleeds from your body, but you feel your spirit remain trapped in the home, cursed to forever be a spirit haunting the grounds like so many others." << std::endl;
			int a;
			std::cin >> a;
			exit(0);
		}
		//otherwise set the enemy to defeated
		player.getMagicBook()->expGain(enemy->getName());
		std::cout << "The " + enemy->getName() + " falls to your attack" << std::endl;
		enemy->setisDefeated();
	}
	//determine which room it is and select the correct enemy
	else if (room == dungeon[4] && room->getArmor()->getisDefeated() == false)
	{
		HauntedArmor* enemy = room->getArmor();
		std::cout << "The " + enemy->getName() + " attacks!" << std::endl;
		//continue running loop until player or enemy are dead
		while (player.getHp() > 0)
		{
			//pick weapon and check if its valid
			while (true)
			{
				std::cout << "Enter a weapon to use (fist or item) type inventory to see the items in your possession";
				if (player.getMagicBook()->getCanUseMagic())
				{
					std::cout << " or type spells to see a list of spells to use" << std::endl;
				}
				else
					std::cout << std::endl;
				std::getline(std::cin, weapon);
				if (weapon == "FIST" || (weapon == "SWORD" && this->inventoryContains("SWORD")) || (weapon == "HOLY WATER" && player.inventoryContains("HOLY WATER")) || (weapon == "BANISH" && player.getMagicBook()->getCanUseMagic() && player.getMagicBook()->getMagicLevel() >= 2) || (weapon == "MAKE CORPORAL" && player.getMagicBook()->getCanUseMagic()))
				{
					break;
				}
				else if (weapon == "INVENTORY")
				{
					player.displayInventory();
				}
				else if (weapon == "SPELLS")
				{
					magic->displaySpells();
				}
				else
					std::cout << "You want to use " << weapon << " to attack?" << std::endl;
			}
			//depending on which weapon selected preform action
			if (weapon == "FIST")
				dmg = 0;
			if (weapon == "SWORD")
				int dmg = 2;
			if (weapon == "HOLY WATER")
				int dmg = 50;
			if (weapon == "BANISH")
				int dmg = 100;
			if (weapon == "MAKE CORPORAL" && enemy->getisCorporal() == false)
				int dmg = 98;
			enemy->lowerHp(dmg);
			if (dmg == 0)
				player.lowerHP();
			// if enemy isn't dead it attacks
			if (enemy->getHp() > 0)
			{
				enemy->attack();
				player.lowerHP();
			}
			else
				break;
		}
		// if player hp is 0 then game over
		if (player.getHp() <= 0)
		{
			std::cout << "Your life bleeds from your body, but you feel your spirit remain trapped in the home, cursed to forever be a spirit haunting the grounds like so many others." << std::endl;
			int a;
			std::cin >> a;
			exit(0);
		}
		//otherwise set the enemy to defeated
		player.getMagicBook()->expGain(enemy->getName());
		std::cout << "The " + enemy->getName() + " falls to your attack" << std::endl;
		room->getArmor()->setDefeated();
	}
	//determine which room it is and select the correct enemy

	else if ((room == dungeon[5] && room->getPoltergeist()->getisDefeated() == false) || (room == dungeon[8] && room->getPoltergeist()->getisDefeated() == false))
	{
		Poltergeist* enemy = room->getPoltergeist();
		std::cout << "The " + enemy->getName() + " attacks!" << std::endl;
		//continue running loop until player or enemy are dead

		while (player.getHp() > 0)
		{
			MagicBook magic = MagicBook();
			//pick weapon and check if its valid

			while (true)
			{
				std::cout << "Enter a weapon to use (fist or item) type inventory to see the items in your possession";
				if (player.getMagicBook()->getCanUseMagic())
				{
					std::cout << " or type spells to see a list of spells to use" << std::endl;
				}
				else
					std::cout << std::endl;
				std::getline(std::cin, weapon);
				if (weapon == "FIST" || (weapon == "SWORD" && this->inventoryContains("SWORD")) || (weapon == "HOLY WATER" && player.inventoryContains("HOLY WATER")) || (weapon == "BANISH" && player.getMagicBook()->getCanUseMagic() & player.getMagicBook()->getMagicLevel() >= 2) || (weapon == "MAKE CORPORAL" && player.getMagicBook()->getCanUseMagic()) || (weapon == "BACKPACK" && player.inventoryContains("BACKPACK")))
				{
					break;
				}
				else if (weapon == "INVENTORY")
				{
					player.displayInventory();
				}
				else if (weapon == "SPELLS")
				{
					magic.displaySpells();
				}
				else
					std::cout << "You want to use " << weapon << " to attack?" << std::endl;
			}
			//depending on which weapon selected preform action

			if (weapon == "FIST")
			{
				if (!enemy->getisCorporal())
					dmg = -1;
				else
					int dmg = 1;
			}
			if (weapon == "SWORD")
			{
				if (!enemy->getisCorporal())
					int dmg = 0;
				else
					int dmg = 2;

			}
			if (weapon == "HOLY WATER")
				int dmg = 50;
			if (weapon == "BANISH")
				int dmg = 100;
			if (weapon == "MAKE CORPORAL" && enemy->getisCorporal() == false)
				int dmg = 98;
			if (weapon == "BACKPACK")
				int dmg = 101;
			enemy->lowerHp(dmg);
			// if enemy isn't dead it attacks
			if (enemy->getHp() > 0)
			{
				enemy->haunt();
				player.lowerHP();
			}
			else
				break;
		}
		// if player hp is 0 then game over
		if (player.getHp() <= 0)
		{
			std::cout << "Your life bleeds from your body, but you feel your spirit remain trapped in the home, cursed to forever be a spirit haunting the grounds like so many others." << std::endl;
			int a;
			std::cin >> a;
			exit(0);
		}
		//otherwise set the enemy to defeated
		player.getMagicBook()->expGain(enemy->getName());
		std::cout << "The " + enemy->getName() + " falls to your attack" << std::endl;
		room->getPoltergeist()->setDefeated();
	}
	//determine which room it is and select the correct enemy


	else if (room == dungeon[10])
	{
		ButlerBoss* enemy = room->getButler();
		int loopCount = 0;
		std::cout << "Your final enemy looms before you." << std::endl;
		//continue running loop until player or enemy are dead
		while (player.getHp() > 0)
		{
			MagicBook magic = MagicBook();
			bool isCorporal = false;
			//pick weapon and check if its valid

			while (true)
			{
				std::cout << "Enter a weapon to use (fist or item) type inventory to see the items in your possession";
				if (player.getMagicBook()->getCanUseMagic())
				{
					std::cout << " or type spells to see a list of spells to use" << std::endl;
				}
				else
					std::cout << std::endl;
				std::getline(std::cin, weapon);
				//depending on which weapon selected preform action

				if (weapon == "FIST" || (weapon == "SWORD" && this->inventoryContains("SWORD")) || (weapon == "HOLY WATER" && player.inventoryContains("HOLY WATER")) || (weapon == "BANISH" && player.getMagicBook()->getCanUseMagic() && player.getMagicBook()->getMagicLevel() >= 2) || (weapon == "MAKE CORPORAL" && player.getMagicBook()->getCanUseMagic()) || (weapon == "BACKPACK" && player.inventoryContains("BACKPACK")))
				{
					break;
				}
				else if (weapon == "INVENTORY")
				{
					player.displayInventory();
				}
				else if (weapon == "SPELLS")
				{
					magic.displaySpells();
				}
				else
					std::cout << "You want to use " << weapon << " to attack?" << std::endl;
			}

			if (weapon == "FIST")
			{
				if (enemy->getisCorporal() == false)
					dmg = -1;
				else
				{
					dmg = 1;
				}
			}
			if (weapon == "SWORD")
			{
				if (enemy->getisCorporal() == false)
					dmg = 0;
				else
				{
					dmg = 2;
				}
			}
			if (weapon == "HOLY WATER")
				int dmg = 25;
			if (weapon == "BANISH")
				dmg = -2;
			if (weapon == "MAKE CORPORAL" && enemy->getisCorporal() == false)
			{
				int dmg = 90;
			}
			if (weapon == "BACKPACK")
			{
				int dmg = 95;
				int index = 0;
				for (Item e : inventory)
				{
					if (e.getName() == "BACKPACK")
						this->inventory.erase(this->inventory.begin() + index);
					index++;
				}
			}
			enemy->lowerHp(dmg);
			// if enemy isn't dead it attacks

			if (enemy->getHp() > 0)
			{
				if (loopCount == 0)
				{
					enemy->strike();
					player.lowerHP();
					loopCount++;
				}
				else if (loopCount == 1)
				{
					enemy->stab();
					player.lowerHP();
					player.lowerHP();
					loopCount++;
				}
				else if (loopCount == 2)
				{
					enemy->curse();
					player.lowerHP();
					player.lowerHP();
					player.lowerHP();
				}
			}
			else
				break;
		}
		// if player hp is 0 then game over
		if (player.getHp() <= 0)
		{
			std::cout << "Your life bleeds from your body, but you feel your spirit remain trapped in the home, cursed to forever be a spirit haunting the grounds like so many others." << std::endl;
			int a;
			std::cin >> a;
			exit(0);
		}
		std::cout << "The Butler's final cries echo from around the room as he dissapates into nothing. You think you are safe for only a moment before the floor cracks and a chasm in the earth splits beneath your feet. You plummet down into its cold dark clutches." << std::endl;
	}
	else if (room == dungeon[17])
	{
		while (true)
		{
			Snake* enemy = room->getSnake();
			if (enemy->getSwarm())
				std::cout << "A swarm of snakes hisses around you, one of them sees you and slithers your way." << std::endl;
			else
				std::cout << "A lone snake slithers it way towards you." << std::endl;
			//continue running loop until player or enemy are dead
			while (player.getHp() > 0)
			{
				//pick weapon and check if its valid
				while (true)
				{
					std::cout << "Enter a weapon to use (fist or item) type inventory to see the items in your possession";
					if (player.getMagicBook()->getCanUseMagic())
					{
						std::cout << " or type spells to see a list of spells to use" << std::endl;
					}
					else
						std::cout << std::endl;
					std::getline(std::cin, weapon);
					//depending on which weapon selected preform action

					if (weapon == "FIST" || (weapon == "SWORD" && this->inventoryContains("SWORD")) || (weapon == "ENCHANTED SWORD" && this->inventoryContains("ENCHANTED SWORD")) || (weapon == "CHARM" && player.getMagicBook()->getCanUseMagic() && player.getMagicBook()->getMagicLevel() >= 3))
					{
						break;
					}
					else if (weapon == "INVENTORY")
					{
						player.displayInventory();
					}
					else if (weapon == "SPELLS")
					{
						player.getMagicBook()->displaySpells();
					}
					else
						std::cout << "You want to use " << weapon << " to attack?" << std::endl;
				}

				if (weapon == "FIST")
				{
					dmg = 0;
				}
				if (weapon == "SWORD")
				{
					dmg = 2;
				}
				if (weapon == "ENCHANTED SWORD")
				{
					dmg = 5;
				}
				if (weapon == "CHARM")
				{
					dmg = -1;
				}
				enemy->lowerHp(dmg);
				// if enemy isn't dead it attacks

				if (enemy->getHp() > 0)
				{
					enemy->snakeBite();
					player.lowerHP();
				}
				else
					break;
			}

			// if player hp is 0 then game over
			if (player.getHp() <= 0)
			{
				std::cout << "Your life bleeds from your body, and it becomes food for the creatures in the cave." << std::endl;
				int a;
				std::cin >> a;
				exit(0);
			}
			if (!enemy->getSwarm())
			{
				player.getMagicBook()->expGain(enemy->getName());
				std::cout << "The " + enemy->getName() + " falls to your attack" << std::endl;
				enemy->setIsDefeated();
				break;
			}
			enemy->lowerSwarmCheck();
			enemy->resetHp();
		}
	}
	else if (room == dungeon[13])
	{
		while (true)
		{
			Wolf* enemy = room->getWolf();
			if (enemy->getPack())
				std::cout << "A pack of wolves growl at you, and you find youself surrounded." << std::endl;
			else
				std::cout << "A single wolf glares at you with its fangs bared." << std::endl;
			//continue running loop until player or enemy are dead
			while (player.getHp() > 0)
			{
				//pick weapon and check if its valid
				while (true)
				{
					std::cout << "Enter a weapon to use (fist or item) type inventory to see the items in your possession";
					if (player.getMagicBook()->getCanUseMagic())
					{
						std::cout << " or type spells to see a list of spells to use" << std::endl;
					}
					else
						std::cout << std::endl;
					std::getline(std::cin, weapon);
					//depending on which weapon selected preform action

					if (weapon == "FIST" || (weapon == "SWORD" && this->inventoryContains("SWORD")) || (weapon == "TORCH" && this->inventoryContains("TORCH")) || (weapon == "CHARM" && player.getMagicBook()->getCanUseMagic() && player.getMagicBook()->getMagicLevel() >= 3))
					{
						break;
					}
					else if (weapon == "INVENTORY")
					{
						player.displayInventory();
					}
					else if (weapon == "SPELLS")
					{
						player.getMagicBook()->displaySpells();
					}
					else
						std::cout << "You want to use " << weapon << " to attack?" << std::endl;
				}

				if (weapon == "FIST")
				{
					dmg = 1;
				}
				if (weapon == "SWORD")
				{
					dmg = 2;
				}
				if (weapon == "CHARM")
				{
					dmg = -1;
				}
				if (weapon == "TORCH")
				{
					dmg = 3;
				}
				enemy->lowerHp(dmg);
				// if enemy isn't dead it attacks

				if (enemy->getHp() > 0)
				{
					enemy->wolfBite();
					player.lowerHP();
				}
				else
					break;
			}
			// if player hp is 0 then game over
			if (player.getHp() <= 0)
			{
				std::cout << "Your life bleeds from your body, and it becomes food for the creatures in the cave." << std::endl;
				int a;
				std::cin >> a;
				exit(0);
			}

			if (!enemy->getPack())
			{
				player.getMagicBook()->expGain(enemy->getName());
				std::cout << "The " + enemy->getName() + " falls to your attack" << std::endl;
				enemy->setIsDefeated();
				break;
			}
			enemy->lowerPackCheck();
			enemy->resetHp();
		}
	}

	//COMBAT LOOP ENDS HERE
	srand(time(NULL));

	int randomDrop = rand() % 50 + 1;

	if (randomDrop <= 10) {
		Potion drop("POTION");
		player.take(drop);
		std::cout << "You found a Potion on the ground." << std::endl;
	}
	else if (randomDrop > 10 && randomDrop <= 15) {
		SuperPotion drop("SUPER POTION");
		player.take(drop);
		std::cout << "You found a Super Potion on the ground." << std::endl;
	}
	else if (randomDrop > 15 && randomDrop <= 16) {
		BlessedRock drop("BLESSED ROCK");
		player.take(drop);
		std::cout << "You found a Blessed Rock on the ground." << std::endl;
	}
	else {
		std::cout << "You found nothing." << std::endl;
		//no drop
	}
	return player;
}

std::string Player::Sanitize(std::string word) {
	//sanitize input to remove case sensitivity
	std::transform(word.begin(), word.end(), word.begin(), ::toupper);
	return word;
}