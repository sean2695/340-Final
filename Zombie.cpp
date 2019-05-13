//attack for the zombie
void Zombie::bite()
{
	std::cout << "The zombie groans as its rotting fingers clutches you. The smell of death lingers on its breath as the few remaining teeth chomp on you." << std::endl;

}

void Zombie::lowerHp(int dmg)
{
	if (dmg == 1)
	{
		std::cout << "Your fist drives home into the zombies decayed face." << std::endl;
		this->hp - dmg;
	}
	if (dmg == 2)
	{
		std::cout << "You bash your shovel agaisnt the zombies skull hearing a satisfying crunch." << std::endl;
		this->hp = hp - dmg;

	}
	if (dmg == 3)
	{
		std::cout << "Your blade flies true, lopping off the zombies head with one stroke." << std::endl;
		this->hp = hp - dmg;
	}
}