#include"spaceprobe.h"


SpaceProbe::SpaceProbe()
{

}

//Copies contents of SpaceProbe's AsteroidList to another list
void SpaceProbe::getPictures(AsteroidList& preciousList)
{
	for (int i = 0; i < preciousAsteroids.count(); i++)
	{
		int aX = preciousAsteroids.getAsteroid(i).getX();
		int aY = preciousAsteroids.getAsteroid(i).getY();
		preciousList.add(preciousAsteroids.getAsteroid(i), aX, aY);
	}
}

//Returns total number of visited asteroids
int SpaceProbe::getTotalCaptured()
{
	return totalVisited;
}

//Moves position of probe to asteroid
//Analyzes asteroid's information and saves picture if precious
void SpaceProbe::takePicture(int i, AsteroidList &astArray)
{
	//position of closest asteroid
	int asteroidX = astArray.getAsteroid(i).getX();
	int asteroidY = astArray.getAsteroid(i).getY();

	//moves SpaceProbe to asteroid's position
	movePosition(asteroidX, asteroidY);

	//changes status of closest asteroid
	if (!astArray.getAsteroid(i).isVisited())
		astArray.getAsteroid(i).changeVisitedStatus();

	//saves asteroid's data if it has precious metals
	if (astArray.getAsteroid(i).hasPreciousMetals())
		savePicture(i, asteroidX, asteroidY, astArray);

	totalVisited++;
}

//Adds asteroid to list
void SpaceProbe::savePicture(int i, int aX, int aY, AsteroidList &astArray)
{
	preciousAsteroids.add(astArray.getAsteroid(i), aX, aY);
}

//Finds closest asteroid to ship
int SpaceProbe::searchField(AsteroidList &astArray, int asteroidPopulation)
{
	//sets asteroid to first asteroid in array
	Asteroid closest = astArray.getAsteroid(0);

	int closestIndex = 0;

	//position of closest asteroid
	int closestX = astArray.getAsteroid(0).getX();
	int closestY = astArray.getAsteroid(0).getY();

	for (int i = 0; i < asteroidPopulation; i++)
	{
		//changes closest asteroid if it is collected or visited
		if (closest.isVisited() || closest.isCollected())
		{
			closest = astArray.getAsteroid(i);

			closestIndex = i;

			closestX = astArray.getAsteroid(i).getX();
			closestY = astArray.getAsteroid(i).getY();
		}

		//if asteroid at index is not collected  
		if (!astArray.getAsteroid(i).isCollected() && !astArray.getAsteroid(i).isVisited())
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
	}

	return closestIndex;
}

//Destructor
SpaceProbe::~SpaceProbe()
{

}