
class Ghost
{
public:
	//constructor for Ghost abstract class
	Ghost(std::string name);

	//setter for isCorporal
	void setCorporal();
	//setter for isDefeated
	void setDefeated();
	// function to lower the Ghost's hp
	bool getisDefeated();
	// getter to return isCorporal
	bool getisCorporal();
	// gett to return Hp
	int getHp();
	// getter to return name
	std::string getName();

protected:
	// boolean to determine is already beaten
	bool isDefeated = false;
	// boolean to determine is set to corporal
	bool isCorporal = false;
	// name of enemy
	std::string name;
	//hit points of enemy
	int hp = 100;
};