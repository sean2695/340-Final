#include "RoomSetUp.h"



RoomSetUp::RoomSetUp()
{
	
}

std::vector<Room*> RoomSetUp::MapMaker(std::vector<Room*> dungeon)
{
	//0
	dungeon.push_back(new Room("This sir, is the Manor's courtyard. A cobbled path leads in three directions, in the center stands a tall monument of a Knight brandishing a sword and shield. You will notice a greenhouse to east, a cemetary to west, and of course Torgeist Manor, where the late master Paul resided."));
	//1
	dungeon.push_back(new Room("This sir, is the greenhouse used to be quite well kept. Now however it has fallen into quite the state of disrepair with shattered glass and dead plants. Inside are rows of overgrown ivy and plants black with death and disease. A reanimated corpse of the last gardener still wanders, guarding his old shovel."));
	//2
	dungeon.push_back(new Room("This sir, is the Torgeist family Cemetary, rows of gravestones line the land. The last masters grave is the closest there, with the dirt being freshly dug. To the west is the Chapel, and the east leads to the Courtyard."));
	//3
	dungeon.push_back(new Room("This sir, is the Chapel to the Forgotten Ones, said to be gods who granted worshippers power over spirits. As you can see, pews adorn each side of the Chapel, a basin filled with Holy Water sits off the side, and an altar resides at the end of the room with a leather bound book resting upon it"));
	//4
	dungeon.push_back(new Room("This sir, is the Main Hall. Suits of armor once belogning to actual knights line the room, and paintings of the masters of the Manor adorn the walls. Some have said the eyes follow one around the room, well except for the painting of the previous master Paul Torgeist. A grand staircase the north leads to the upstairs hallway. The dining room lies to the west. A door to the right leads down into the basement, though I caution agaisnt going down there, it is not safe."));
	//5
	dungeon.push_back(new Room("This sir, is the dining room. We used to hold lavish banquets here, the dinnerware still rests on the table and at the center of the table lies a silver serving dish with a silver plate cover."));
	//6
	dungeon.push_back(new Room("This sir, is the upstairs hallway, to the east is master bedroom, and the north is the library."));
	//7
	dungeon.push_back(new Room("This sir, is the master bedroom. A canopy bed lies in the center of the room. A large window with a ledge for sitting looks out over the grounds. A closet with a closed door hides in the corner."));
	//8
	dungeon.push_back(new Room("This sir, is the library. A writing desk rests in the corner of the room, and plush chairs pepper the carpet. To the east is a bookcase, most of the books look to be unreadable but a few still look in good condition."));
	//9
	dungeon.push_back(new Room("As you enter the room, you realize the ghostly spectre of the butler did not follow you in. The room consists of a small desk with a single piece of paper on it. A mannequin is in the center of the room with a strange device that looks like a backpack."));
	//10
	dungeon.push_back(new Room("Well, well sir. I never expected you to make it this far. This is the basement, and as you can see it is already occupied. The corpse in front of you is the last master Paul Torgeist, a devilsh man with little remorse for the working class. I thought by leaving him here I would be free, but alas I was doomed to serve here forever in the next life. Now that you have learned the secret, I'm afraid I can not let you leave. As he says this the basement door slams shut." ));


	// connect the rooms to each other (North East South West)
	dungeon[0]->connectRooms(dungeon[4], dungeon[1], nullptr, dungeon[2]);
	dungeon[1]->connectRooms(nullptr, nullptr, nullptr, dungeon[0]);
	dungeon[2]->connectRooms(nullptr, dungeon[0], nullptr, dungeon[3]);
	dungeon[3]->connectRooms(nullptr, dungeon[2], nullptr, nullptr);
	dungeon[4]->connectRooms(dungeon[6], dungeon[10], dungeon[0], dungeon[5]);
	dungeon[5]->connectRooms(nullptr, dungeon[4], nullptr, nullptr);
	dungeon[6]->connectRooms(dungeon[8], dungeon[7], dungeon[4], nullptr);
	dungeon[7]->connectRooms(nullptr, nullptr, nullptr, dungeon[6]);
	dungeon[8]->connectRooms(nullptr, dungeon[9], dungeon[6], nullptr);
	dungeon[9]->connectRooms(nullptr, nullptr, nullptr, dungeon[8]);
	dungeon[10]->connectRooms(nullptr, nullptr, nullptr, dungeon[4]);

	// set which rooms allow to take items from the start
	dungeon[0]->setCanTakeItems();
	dungeon[1]->setCanTakeItems();
	dungeon[3]->setCanTakeItems();
	dungeon[7]->setCanTakeItems();
	dungeon[9]->setCanTakeItems();



	return dungeon;
}

std::vector<Room*> RoomSetUp::setItems(std::vector<Room*> dungeon)
{
	//add every item in the rooms
	dungeon[0]->addItem(Sword("SWORD"));
	dungeon[1]->addItem(Shovel("SHOVEL"));
	dungeon[2]->addItem(Key("HouseKey"));
	dungeon[3]->addItem(HolyWater("HOLY WATER"));
	dungeon[4]->addItem(Key("LibraryKey"));
	dungeon[5]->addItem(Head("HEAD"));
	dungeon[8]->addItem(Key("BasementKey"));
	dungeon[7]->addItem(Journal("JOURNAL"));
	dungeon[9]->addItem(Letter("LETTER"));
	dungeon[9]->addItem(GhostVacuum("BACKPACK"));

	return dungeon;
}

std::vector<Room*> RoomSetUp::setEnemies(std::vector<Room*> dungeon)
{
	//add every item to the rooms
	dungeon[1]->setZombie(new Zombie("Zombie"));
	dungeon[2]->setSkeleton(new Skeleton("Skeleton"));
	dungeon[3]->setPriest(new HeadlessPriest("Headless Priest")); 
	dungeon[4]->setHauntedArmor(new HauntedArmor("Haunted Armor"));
	dungeon[5]->setPoltergeist(new Poltergeist("Dining Room Spirit"));
	dungeon[7]->setZombie(new Zombie("Zombie"));
	dungeon[8]->setPoltergeist(new Poltergeist("Library Spirit"));
	dungeon[10]->setButlerBoss(new ButlerBoss("Carson"));
	return dungeon;
}