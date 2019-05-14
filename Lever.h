#pragma once
class Lever
{
public:
	Lever();
	bool getIsPulled();
	void setIsPulled();
	
private:
	bool isPulled = false;
};

