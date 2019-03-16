#pragma once
#include"SpaceCraft.h"

class SpaceProbe :public SpaceCraft
{
public:

	//Default contructor
	SpaceProbe();


	//Returns list of asteroids with precious metals
	void getPictures(AsteroidList&);

	//Returns number of asteroids visited
	int getTotalCaptured();

	//Adds closest asteroid to array 
	//if it contains precious metals
	void takePicture(int, AsteroidList&);

	//Adds asteroid with precious metals to an AsteroidList
	void savePicture(int, int, int, AsteroidList&);

	//Finds closest asteorid to collect
	int searchField(AsteroidList&, int);

	//Destructor
	~SpaceProbe();
private:
	AsteroidList preciousAsteroids;

}; 
