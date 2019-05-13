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
