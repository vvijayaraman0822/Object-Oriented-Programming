#pragma once
#include"spaceobject.h"

class Asteroid : public SpaceObject
{
public:
	//default contructor
	Asteroid();

	//parameterized constructor
	Asteroid(double, bool);

	//copy constructor
	Asteroid(const Asteroid&);

	//changes status to collected
	void changeCollectedStatus();

	//changes status to collected
	void changeVisitedStatus();


	//returns weight
	double getWeight();

	//determines whether or not asteroid has precious metals
	bool hasPreciousMetals();

	//return whether or not asteroid has been collected
	bool isCollected();

	//returns whether or not an asteroid has been visited
	bool isVisited();

	//sets collected status
	void setCollected(bool);

	//sets precious metal in asteroid
	void setPreciousStatus(bool);

	//sets size of asteroid
	void setSize(double);

	//sets visited status
	void setVisited(bool);

	//destructor
	~Asteroid();

private:
	double size;
	bool collected;
	bool precious;
	bool visited;
}; 
