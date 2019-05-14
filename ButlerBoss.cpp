#include "ButlerBoss.h"



ButlerBoss::ButlerBoss(std::string name) : Ghost(name)
{

}

//boss first attack
void ButlerBoss::strike()
{
	std::cout << "The butler's hand flies up quickly, and a glint of light reflects off the steel candleabra he is holding as it smashed into your head" << std::endl;
}

//boss second attack
void ButlerBoss::stab()
{
	std::cout << "The butler laughs manically as he thrusts a dinner knife into your abdomen." << std::endl;
}

//boss third attack
void ButlerBoss::curse()
{
	std::cout << "The butler's eyes glow like a black fire and you feel a dark power crash down over you wringing out your life force." << std::endl;
}

void ButlerBoss::lowerHp(int dmg)
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
		this->hp == hp - dmg;
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
		this->hp == 10;
		this->isCorporal == true;
	}
	if (dmg == 95)
	{
		std::cout << "The vacuum whirs as it pulls the bellowing Butler into its hose and into the containtment unit. But just as you think its over the unit begins to buzz loudly and cracks, allowing the Butler to free himself and breaks the backpack." << std::endl;
		this->hp = hp - dmg;
	}
}
