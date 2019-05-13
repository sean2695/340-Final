#pragma once
#include <string>
#include <iostream>

class Item
{
public:
	//constructor
	Item(std::string name);
	//return name of Item
	std::string getName();
protected:
	std::string name;
};