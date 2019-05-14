#include "Item.h"

//constructor
Item::Item(std::string name)
{
	this->name = name;
}

// return the name of the item
std::string Item::getName()
{
	return this->name;
}

