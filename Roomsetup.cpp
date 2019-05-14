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
	dungeon.push_back(new Room("Well, well sir. I never expected you to make it this far. This is the basement, and as you can see it is already occupied. The corpse in front of you is the last master Paul Torgeist, a devilsh man with little remorse for the working class. I thought by leaving him here I would be free, but alas I was doomed to serve here forever in the next life. Now that you have learned the secret, I'm afraid I can not let you leave. As he says this the basement door slams shut."));

	// Second level

	//11 
	dungeon.push_back(new Room("You find yourself in a desolate cavern. The walls are covered in glowing plants. The room is bare, and to the east is a small opening, and to the west is a passage."));
	//12
	dungeon.push_back(new Room("You crawl through to a torch lit chamber cut off from the rock. On one end standing up right is a black wooden coffin. To the west lays the openeing you came from."));
	//13
	dungeon.push_back(new Room("A dark open cavern lies before you. You hear the soft growl of some kind of animal coming from the back of the room. To the north lies a lit hallway, to the east is a passageway."));
	//14
	dungeon.push_back(new Room("A room that looks it was hand carved lit with torches greets you. To the north is a crack in the wall just big enough to move through, to the east is an arched passageway, to south is dark hallway."));
	//15
	dungeon.push_back(new Room("A room with a crack in the ceiling letting light in from above. Ivy grows to off a cliff on the side. To the west lies an arched doorway, to the north is a long tunnel"));
	//16
	dungeon.push_back(new Room("A cavern with more gwoing lichen on the walls. To the north of the room lies a small lake which seems to be glowing. To the east is an doorway with a wooden door broken of the hinges, to south is a long tunnel, to the west is passageway."));
	//17
	dungeon.push_back(new Room("A bare cavern with a loud hissing. A rock justs out of the wall in the west of the room. To the east is a passageway to the south is a crack in the wall large enough to wiggle through."));
	//18
	dungeon.push_back(new Room("A small corridor which was obviously made witha purpose, a groaning sounds from the shadows. The end of the passage lies a large door marked with runes and words that read 'Here lies the greatest evil.'"));
	//19
	dungeon.push_back(new Room("A large chamber, lit from all sides by light from an unknown source. It is constuctred to look like a temple, and upon the altar a decrepit figure looms. As you approach it rises up, and you see a grotesque face partially hidden beneath the hood of a cloak. It cackles at you and then from nowhere and everywhere you hear these words pound agaisnt from outside and inside your head 'You've done well to make it this far, and I must show my gratitude for breaking the seal upon that door and allowing me my freedom. Let me reward you with a swift death and becoming my latest undead thrall' "));






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

	//connect second level dungeon
	dungeon[11]->connectRooms(nullptr, dungeon[12], nullptr, dungeon[13]);
	dungeon[12]->connectRooms(nullptr, nullptr, nullptr, dungeon[11]);
	dungeon[13]->connectRooms(dungeon[14], dungeon[11], nullptr, nullptr);
	dungeon[14]->connectRooms(dungeon[17], dungeon[15], dungeon[13], nullptr);
	dungeon[15]->connectRooms(dungeon[16], nullptr, nullptr, dungeon[14]);
	dungeon[16]->connectRooms(nullptr, dungeon[18], dungeon[15], dungeon[17]);
	dungeon[17]->connectRooms(nullptr, dungeon[16], dungeon[14], nullptr);
	dungeon[18]->connectRooms(dungeon[19], nullptr, nullptr, dungeon[16]);
	dungeon[19]->connectRooms(nullptr, nullptr, dungeon[18], nullptr);

	// set which rooms allow to take items from the start
	dungeon[0]->setCanTakeItems();
	dungeon[1]->setCanTakeItems();
	dungeon[3]->setCanTakeItems();
	dungeon[7]->setCanTakeItems();
	dungeon[9]->setCanTakeItems();

	for (int i = 11; i < 20; i++)
	{
		dungeon[i]->setCanTakeItems();
	}

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

	dungeon[17]->addItem(Sword("ENCHANCTED SWORD"));
	
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

	//add enemies to second		
	dungeon[12]->setVampire(new Vampire("Vampire"));
	dungeon[13]->setWolf(new Wolf("Wolf"));
	//dungeon[15]->setWight(new Wight("Wight"));
	dungeon[17]->setSnake(new Snake("Snake"));
	dungeon[18]->setGhoul(new Ghoul("Ghoul"));
	//dungeon[19]->setLich(new Lich("Lich"));

	return dungeon;
}