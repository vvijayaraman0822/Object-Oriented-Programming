#include"spacecraft.h"

SpaceCraft::SpaceCraft()
{
	toCollect = 0;
	totalTravelled = 0;
	totalCaptured = 0;

}



//parameterized constructor
SpaceCraft::SpaceCraft(int collect)
{
	toCollect = collect;
	totalTravelled = 0;
	totalCaptured = 0;

}

//creates new Ship that is exactly like other Ship
SpaceCraft::SpaceCraft(const SpaceCraft &other)
{
	x = other.x;
	y = other.y;
	toCollect = other.toCollect;
	totalTravelled = other.totalTravelled;
	totalCaptured = other.totalCaptured;
}

//determines distance from ship to asteroid
double SpaceCraft::distanceToAsteroid(int x2, int y2)
{
	double differenceX = x2 - x;
	double distanceX = pow(differenceX, 2);

	double differenceY = y2 - y;
	double distanceY = pow(differenceY, 2);

	double calcDistance = sqrt(distanceX + distanceY);

	return calcDistance;
}

//returns total number of captured asteroids
int SpaceCraft::getTotalCaptured()
{
	return totalCaptured;
}

//returns total distance travelled by ship
double SpaceCraft::getTotalDistance()
{
	return totalTravelled;
}

//moves position of ship to position of asteroid
void SpaceCraft::movePosition(int newX, int newY)
{
	totalTravelled += distanceToAsteroid(newX, newY);

	x = newX;
	y = newY;
}

//finds closest asteroid to ship
int SpaceCraft::searchField(AsteroidList &astArray, int asteroidPopulation)
{
	//sets asteroid to first asteroid in array
	Asteroid closest = astArray.getAsteroid(0);

	int closestIndex = 0;

	//position of closest asteroid
	int closestX = astArray.getAsteroid(0).getX();
	int closestY = astArray.getAsteroid(0).getY();

	for (int i = 0; i < asteroidPopulation; i++)
	{
		//position of targeted asteroid
		int asteroidX = astArray.getAsteroid(i).getX();
		int asteroidY = astArray.getAsteroid(i).getY();

		//if asteroid is closer to ship than closest
		if (distanceToAsteroid(asteroidX, asteroidY) < distanceToAsteroid(closestX, closestY))
		{
			closest = astArray.getAsteroid(i);
			closestIndex = i;
		}
	}
	return closestIndex;
}

//destructor
SpaceCraft::~SpaceCraft()
{
	toCollect = 0;
	totalCaptured = 0;
	totalTravelled = 0;
}