#pragma once
#include "Item.h"
#include "Ghost.h"

class HolyWater : public Item
{
public:
	//constructor
	HolyWater(std::string name);
private:
	int uses = 3;
};