#include "Lich.h"



Lich::Lich(std::string name) : Undead(name)
{
}

//boss first attack
void Lich::strike()
{
	std::cout << "The Lich raises its palm and cries out a command in the ancient language. You feel a burning sensastion through your whole body." << std::endl;
}

//boss second attack
void Lich::stab()
{
	std::cout << "The lich raises his palm in the air, bony hands rise from the ground and clutch you, and the Lich fires a bolt of pure evil at you." << std::endl;
}

//boss third attack
void Lich::curse()
{
	std::cout << "The Lich points a single finger at you, and from all directions spirits fly at you and through your own soul, istealing youe very life force." << std::endl;
}

void Lich::lowerHp(int dmg)
{
	if (dmg == -1)
		std::cout << "The Bulter grins wickedly at your attempt, 'No mortal hands can defeat me'." << std::endl;
	if (dmg == 1)
	{
		std::cout << "You throw a heavy punch agaisnt the Butler's jaw, and he staggers back." << std::endl;
		this->hp = hp - dmg;
	}

	if (dmg == 0)
	{
		std::cout << "You slash across the abodemen of the ghostly butler, only to see your swing pass right thorough him.." << std::endl;
	}
	if (dmg == 2)
	{
		std::cout << "You strike at the now embodied spirit with your fists, your punch striking it in the gut." << std::endl;
		this->hp = hp - dmg;
	}
	if (dmg == 25)
	{
		std::cout << "You splash Holy Water onto the Butler, as his spirit sizzles as he grunts in pain." << std::endl;
		this->hp = hp - dmg;
	}
	if (dmg == -2)
	{
		std::cout << "Laughing at your failed spell the butler then shouts 'You can not banish me like some amatuer spirit!'" << std::endl;
	}
	if (dmg == 90)
	{

		std::cout << "The butler gasps as his transparent body solidifies into a solid mass." << std::endl;
		this->hp = 10;
	}
	if (dmg == 95)
	{
		std::cout << "The vacuum whirs as it pulls the bellowing Butler into its hose and into the containtment unit. But just as you think its over the unit begins to buzz loudly and cracks, allowing the Butler to free himself and breaks the backpack." << std::endl;
		this->hp = hp - dmg;
	}
}