#pragma once
#include"spaceobject.h"
#include"asteroidlist.h"
#include<math.h>

class SpaceCraft : public SpaceObject
{
public:

	SpaceCraft();
	
	//parameterized constructor
	SpaceCraft(int);

	//copy constructor
	SpaceCraft(const SpaceCraft&);

	//returns distance to asteroid
	double distanceToAsteroid(int, int);

	//Returns number of asteroids collected
	virtual int	getTotalCaptured();

	//returns total distance covered
	double getTotalDistance();

	//changes the position of Ship
	//updates totalDistance
	void movePosition(int, int);

	//finds closest asteorid to collect
	virtual int searchField(AsteroidList&, int);

	//destructor
	virtual ~SpaceCraft();


protected:
	int totalCaptured;
	int totalVisited;
	double totalTravelled;
	int toCollect;
}; 
