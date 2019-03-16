
#include"spaceship.h"

SpaceShip::SpaceShip()
{
	totalWeight = 0;
}


//Creates new SpaceShip that is exactly like other SpaceShip
SpaceShip::SpaceShip(const SpaceShip &other)
{
	totalWeight = other.totalWeight;
}


//Moves position of ship to position of asteroid
//Changes status of asteroid in array
//Increments total captured by ship
//Decrements total asteroids in array
//Adds weight of asteroid to total weight
void SpaceShip::collectAsteroid(int i, AsteroidList &astArray)
{
	int asteroidX = astArray.getAsteroid(i).getX();
	int asteroidY = astArray.getAsteroid(i).getY();

	movePosition(asteroidX, asteroidY);

	if (!astArray.getAsteroid(i).isCollected())
	{
		astArray.getAsteroid(i).changeCollectedStatus();
		astArray.getAsteroid(i).changeVisitedStatus();
	}


	totalCaptured++;

	astArray.decrement();

	totalWeight += astArray.getAsteroid(i).getWeight();

}

//Returns total weight of asteorids
double SpaceShip::getTotalWeight()
{
	return totalWeight;
}

//Finds closest asteroid to ship
int SpaceShip::searchField(AsteroidList &aList, int asteroidPopulation)
{
	//sets asteroid to first asteroid in array
	Asteroid closest = aList.getAsteroid(0);

	int closestIndex = 0;

	//position of closest asteroid
	int closestX = aList.getAsteroid(0).getX();
	int closestY = aList.getAsteroid(0).getY();

	for (int i = 1; i < asteroidPopulation; i++)
	{
		//changes closest asteroid if it is collected or overweight
		if (closest.isCollected() || closest.getWeight() > 10)
		{
			closest = aList.getAsteroid(i);

			closestIndex = i;

			closestX = aList.getAsteroid(i).getX();
			closestY = aList.getAsteroid(i).getY();
		}

		//if asteroid at index is not collected  
		if (!aList.getAsteroid(i).isCollected())
		{
			//if asteroid is less than size 10
			if (aList.getAsteroid(i).getWeight() < 10)
			{
				int asteroidX = aList.getAsteroid(i).getX();
				int asteroidY = aList.getAsteroid(i).getY();

				//if asteroid is closer to ship than closest
				if (distanceToAsteroid(asteroidX, asteroidY) < distanceToAsteroid(closestX, closestY))
				{
					closest = aList.getAsteroid(i);
					closestIndex = i;
				}
			}
		}
	}
	return closestIndex;
}

//Destructor
SpaceShip::~SpaceShip()
{
	totalWeight = 0;
}