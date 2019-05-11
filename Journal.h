#pragma once
#include "Item.h"

class Journal : public Item
{
public:
	//constructor
	Journal(std::string name);
	//print out whats in the journal
	void read();

	
};

