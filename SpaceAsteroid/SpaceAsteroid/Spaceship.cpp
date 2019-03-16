#include "Spaceship.h"
#include<iostream>
using namespace std;

Ship::Ship()
{
	x = 0;
	y = 0;
	toCollect = 0;
	captured = 0;
	totalTravelled = 0;
	totalWeight = 0;
}

Ship::Ship(int X, int Y, int collect)
{
	x = X;
	y = Y;
	toCollect = collect;
	totalTravelled = 0;
	totalWeight = 0;
	captured = 0;
}
int Ship::totalCollected()
{
	return captured;
}
void Ship::collectAsteroid(int i, AsteroidList &astArray)
{
	int asteroidX = astArray.getAsteroid(i).getX();
	int asteroidY = astArray.getAsteroid(i).getY();

	movePosition(asteroidX, asteroidY);

	if (!astArray.getAsteroid(i).isCollected())
		astArray.getAsteroid(i).changeStatus();


	captured++;

	astArray.decrement();

	totalWeight += astArray.getAsteroid(i).getWeight();

}

double Ship::distanceToAsteroid(int x2, int y2)
{
	int differenceX = x2 - x;
	int distanceX = pow(differenceX, 2);

	int differenceY = y2 - y;
	int distanceY = pow(differenceY, 2);

	double calcDistance = static_cast<double>(sqrt(distanceX + distanceY));


	return calcDistance;
}

double Ship::getTotalWeight()
{
	return totalWeight;
}
int Ship::getX()
{
	return x;
}

int Ship::getY()
{
	return y;
}

void Ship::movePosition(int newX, int newY)
{
	totalTravelled += distanceToAsteroid(newX, newY);

	x = newX;
	y = newY;
}

int Ship::searchField(AsteroidList aList)
{
	Asteroid closest = aList.getAsteroid(0);
	for (int i = 0; i < toCollect; i++)
	{
		if (closest.isCollected())
		{
			closest = aList.getAsteroid(i);
		}

		if (!aList.getAsteroid(i).isCollected())
		{
			int closestX = closest.getX();
			int closestY = closest.getY();

			int asteroidX = aList.getAsteroid(i).getX();
			int asteroidY = aList.getAsteroid(i).getY();

			if (distanceToAsteroid(asteroidX, asteroidY) < distanceToAsteroid(closestX, closestY))
				closest = aList.getAsteroid(i);
		}

	}
	return closest.getIndex();
}

double Ship::totalDistance()
{
	return totalTravelled;
}

Ship::~Ship()
{

}