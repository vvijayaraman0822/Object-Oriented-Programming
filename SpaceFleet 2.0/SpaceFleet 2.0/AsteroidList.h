// Vasudev Vijayaraman

#pragma once
#include "Asteroid.h"
#include<string>
using namespace std;

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

	void add(Asteroid&);
	int count();
	void decrement();
	bool empty();
	bool full();
	Asteroid& getAsteroid(int);
	int getSize();
	string toString();

	//destructor
	~AsteroidList();

private:
	Asteroid *A;
	int index;
	int Total;
	int Size;
	int maxAsteroids;
};
