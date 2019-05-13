#pragma once
#include <string>
#include <iostream>

class Undead
{
public:
	// constuctor for Undead abstract class
	Undead(std::string name);
	//lowers Undead hp
	void lowerHp();
	// return the hp
	int getHp();
	// returns name
	std::string getName();
	//returns isDefeated
	bool getisDefeated();
	//sets isDefeated to true
	void setisDefeated();

protected:
	//Undead hp
	int hp;
	// name of enemy
	std::string name;
	//boolean to check if defeated
	bool isDefeated = false;
};