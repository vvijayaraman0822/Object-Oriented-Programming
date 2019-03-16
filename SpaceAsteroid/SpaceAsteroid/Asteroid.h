
#pragma once



class Asteroid
{
public:
	//default contructor
	Asteroid();

	Asteroid(int, int, double, int);

	void changeStatus();

	//returns x coordinate
	int getX();

	//returns y coordinate
	int getY();
	void change();
	int getIndex();

	//returns weight
	double getWeight();

	//return whether or not asteorid has been collected
	bool isCollected();

	//destructor
	~Asteroid();

private:
	int x;
	int y;
	int index;
	bool collected;
	double size;
};