#include "Lever.h"



Lever::Lever()
{
}


bool Lever::getIsPulled()
{
	return this->isPulled;
}

void Lever::setIsPulled()
{
	this->isPulled = true;
}