#pragma once
#include<string>
#include<math.h>
#include "AsteroidList.h"
#include"Asteroid.h"



class Ship
{
public:
	//default constructor
	Ship();

	Ship(int, int,int);

	

	//collects asteroid
	void collectAsteroid(int,AsteroidList&);

	//returns distance to asteroid
	double distanceToAsteroid(int, int);


	double getTotalWeight();

// x coordinate
	int getX();

	// y coordinate
	int getY();

	
	void movePosition(int, int);
	int originalPosition();
    int searchField(AsteroidList);
	int	totalCollected();

	//returns total distance covered
	double totalDistance();

	//destructor
	~Ship();

private:
	int x;
	int y;
	int toCollect;
	double totalTravelled;
	double totalWeight;
	int captured;

};