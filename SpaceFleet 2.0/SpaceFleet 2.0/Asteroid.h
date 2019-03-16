// Vasudev Vijayaraman

#pragma once
#include"SpaceObject.h"

class Asteroid : public SpaceObject
{
public:
	//default contructor
	Asteroid();

	//parameterized constructor
	Asteroid(double, bool);

	//copy constructor
	Asteroid(const Asteroid&);

	
	void changeCollectedStatus();
	void changeVisitedStatus();
	double getWeight();
	bool hasPreciousMetals();
	bool isCollected();
	bool isVisited();
	void setCollected(bool);
	void setPreciousStatus(bool);
	void setSize(double);
	void setVisited(bool);

	
	virtual string toString();

	Asteroid& operator = (Asteroid&);


	//destructor
	~Asteroid();

private:
	double size;
	bool visitedStatus;
	bool precious;
	bool collectedStatus;
};


