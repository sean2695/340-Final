#include "Combat.h"



Combat::Combat()
{
}

void Combat::combatLoop(Room* room, std::vector<Room*> dungeon, Player player)
{
	std::string weapon;
	if ((room == dungeon[1] || room == dungeon[7]) && room->getZombie()->getisDefeated() == false)
	{
		Zombie* enemy = room->getZombie();
		std::cout << "The " + enemy->getName() + " attacks!" << std::endl;
		while (player.getHp() > 0)
		{	
			while (true)
			{
				std::cout << "Enter a weapon to use (fist or item) type inventory to see the items in your possession" << std::endl;
				std::getline(std::cin, weapon);
				if (weapon == "fist" || weapon == "sword" || weapon == "shovel")
				{
					break;
				}
				if (weapon == "inventory")
				{
					player.displayInventory();
				}
				else
					std::cout << "You want to use " << weapon << " to attack?" << std::endl;
			}

			if (weapon == "fist")
			{
				std::cout << "Your fist drives home into the zombies decayed face." << std::endl;
				enemy->lowerHp();
			}
			if (weapon == "shovel")
			{
				std::cout << "You bash your shovel agaisnt the zombies skull hearing a satisfying crunch." << std::endl;
				enemy->lowerHp();
				enemy->lowerHp();

			}
			if (weapon == "sword")
			{
				std::cout << "Your blade flies true, lopping off the zombies head with one stroke." << std::endl;
				enemy->lowerHp();
				enemy->lowerHp();
				enemy->lowerHp();
			}
			if (enemy->getHp() > 0)
			{
				enemy->bite();
				player.lowerHP();
			}
			else
				break;
		}
		std::cout << "The " + enemy->getName() + " falls to your attack" << std::endl;
		room->getZombie()->setisDefeated();
	}
	else if (room == dungeon[2] && room->getSkeleton()->getisDefeated() == false)
	{
		Skeleton* enemy = room->getSkeleton();
		std::cout << "The " + enemy->getName() + " attacks!" << std::endl;
		while (player.getHp() > 0)
		{
			
			
			while (true)
			{
				std::cout << "Enter a weapon to use (fist or item) type inventory to see the items in your possession" << std::endl;
				std::getline(std::cin, weapon);
				if (weapon == "fist" || weapon == "sword" || weapon == "shovel")
				{
					break;
				}
				else if (weapon == "inventory")
				{
					player.displayInventory();
				}
				else
					std::cout << "You want to use " << weapon << " to attack?" << std::endl;
			}

			if (weapon == "fist")
			{
				std::cout << "You throw a punch agaisnt the skeleton exposed ribcage." << std::endl;
				enemy->lowerHp();
			}
			if (weapon == "sword")
			{
				std::cout << "Your sword bounces of the skull of the creature, leaving a large dent." << std::endl;
				enemy->lowerHp();
				enemy->lowerHp();

			}
			if (weapon == "shovel")
			{
				std::cout << "You sweep your shovel under its legs knocking them away and crumbling the remaining bones into an oddly stacked pile." << std::endl;
				enemy->lowerHp();
				enemy->lowerHp();
				enemy->lowerHp();
			}
			if (enemy->getHp() > 0)
			{
				enemy->attack();
				player.lowerHP();
			}
			else
				break;
		}
		std::cout << "The " + enemy->getName() + " falls to your attack" << std::endl;
	}
	else if (room == dungeon[4] && room->getArmor()->getisDefeated() == false)
	{
		HauntedArmor* enemy = room->getArmor();
		std::cout << "The " + enemy->getName() + " attacks!" << std::endl;
		while (player.getHp() > 0)
		{	
			MagicBook magic = MagicBook();
			while (true)
			{
				std::cout << "Enter a weapon to use (fist or item) type inventory to see the items in your possession";
				if (player.getCanUseMagic())
				{
					std::cout << " or type spells to see a list of spells to use" << std::endl;
				}
				else
					std::cout << std::endl;
				std::getline(std::cin, weapon);
				if (weapon == "fist" || weapon == "sword" || weapon == "Holy Water" || weapon == "banish" || weapon == "make corporal")
				{
					break;
				}
				else if (weapon == "inventory")
				{
					player.displayInventory();
				}
				else if (weapon == "spells")
				{
					magic.displaySpells();
				}
				else
					std::cout << "You want to use " << weapon << " to attack?" << std::endl;
			}

			if (weapon == "fist")
			{
				std::cout << "You feel a finger break as your fist strikes the armor." << std::endl;
				player.lowerHP();
			}
			if (weapon == "sword")
			{
				int dmg = 2;
				std::cout << "The sword bounces off the hard steel" << std::endl;
				enemy->lowerHp(dmg);
			}
			if (weapon == "Holy Water")
			{
				int dmg = 50;
				std::cout << "Mist pours from the hollow part of the armor as a scream rings out." << std::endl;
				enemy->lowerHp(dmg);
			}
			if (weapon == "banish")
			{
				std::cout << "The armor crashes the ground in pieces, the spirit holding it together banished." << std::endl;
				enemy->setDefeated();
			}
			if (weapon == "make corporal")
			{
				int dmg = 98;
				std::cout << "A phantom takes form in the armor, presenting a body to strike." << std::endl;
				enemy->lowerHp(dmg);
			}


			if (enemy->getHp() > 0)
			{
				enemy->attack();
				player.lowerHP();
			}
			else
				break;
		}
		std::cout << "The " + enemy->getName() + " falls to your attack" << std::endl;
		room->getArmor()->setDefeated();
	}


}
