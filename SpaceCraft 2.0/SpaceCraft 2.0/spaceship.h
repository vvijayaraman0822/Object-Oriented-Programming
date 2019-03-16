#pragma once
#include"SpaceCraft.h"

class SpaceShip : public SpaceCraft
{
public:
	//default constructor
	SpaceShip();

	//copy constructor
	SpaceShip(const SpaceShip&);

	//collects asteroid and calls movePosition
	void collectAsteroid(int, AsteroidList&);

	//returns total weight of asteroids collected
	double getTotalWeight();

	//finds closest asteorid to collect
	int searchField(AsteroidList&, int);

	~SpaceShip();

private:
	double totalWeight;
};
