#pragma once
#include "asteroid.h"

const int MAXITEMS = 50;

class AsteroidList
{
public:
	//Default constructor
	AsteroidList();

	//Parameterized constructor
	AsteroidList(int);

	//copy constructor
	AsteroidList(const AsteroidList&);

	//Inserts an asteroid to array
	void add(Asteroid&, int, int);

	//Returns amount of asteroids in array
	int count();

	//Decreases total by 1
	void decrement();

	//Determines if array is full
	bool full();

	//Returns asteroid at an index
	Asteroid& getAsteroid(int i);

	//Returns array size
	int getSize();

	//destructor
	~AsteroidList();

private:
	Asteroid *A;
	int index;
	int Total;
	int Size;
	int maxAsteroids;
}; 
