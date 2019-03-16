#pragma once
#include "Asteroid.h"

const int MAXITEMS = 50;

class AsteroidList
{
public:
	//Default constructor
	AsteroidList();

	//Parameterized constructor
	AsteroidList(int);

	//Inserts an asteroid to array
	void add(int, Asteroid);

	//Returns amount of asteroids in array
	int count();
	void decrement();
	bool full();
	Asteroid& getAsteroid(int i);
	void print();
	~AsteroidList();



private:
	Asteroid *A;
	int Total;
	int Size;


};