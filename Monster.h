#pragma once
#include <string>
#include <iostream>

class Monster
{
public:
	// constuctor for Monster abstract class
	Monster(std::string name);
	//lowers Monster hp
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
	//Monster hp
	int hp;
	// name of enemy
	std::string name;
	//boolean to check if defeated
	bool isDefeated = false;
};