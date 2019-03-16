// Vasudev Vijayaraman

#include"SpaceCraft.h"


int SpaceCraft::totalToCollect;
int SpaceCraft::totalToVisit;
int SpaceCraft::totalCollected;
int SpaceCraft::totalVisited;
double SpaceCraft::totalTravelled;
double SpaceCraft::weightCapacity;
AsteroidList SpaceCraft::preciousAsteroids;


//default constructor
SpaceCraft::SpaceCraft()
{
	setX(0);
	setY(0);
	totalCollected = 0;
	totalVisited = 0;
	collected = 0;
	visited = 0;
	travelled = 0;
	totalTravelled = 0;
	fleetCount = 0;
}

//parameterized constructor
SpaceCraft::SpaceCraft(int X, int Y, int size, int i)
{
	setX(X);
	setY(Y);
	collected = 0;
	visited = 0;
	travelled = 0;
	totalTravelled = 0;
	totalCollected = 0;
	totalVisited = 0;
	fleetCount = size;
	position = i;

}


SpaceCraft::SpaceCraft(const SpaceCraft &other)
{
	x = other.x;
	y = other.y;
	totalToCollect = other.totalToCollect;
	totalToVisit = other.totalToVisit;
	travelled = other.travelled;
	totalTravelled = other.totalTravelled;
	totalCollected = other.totalCollected;
	totalVisited = other.totalVisited;
	collected = other.collected;
	visited = other.visited;
}


void SpaceCraft::collect(int place, AsteroidList &astArray)
{
	//override
}


void SpaceCraft::copyList(AsteroidList& preciousList)
{
	for (int i = 0; i < preciousAsteroids.count(); i++)
	{
		preciousList.add(preciousAsteroids.getAsteroid(i));
	}
}


double SpaceCraft::distanceToAsteroid(int x2, int y2)
{
	double differenceX = x2 - x;
	double distanceX = pow(differenceX, 2);

	double differenceY = y2 - y;
	double distanceY = pow(differenceY, 2);

	double calcDistance = sqrt(distanceX + distanceY);

	return calcDistance;
}

string SpaceCraft::getList()
{
	string s = preciousAsteroids.toString();

	return s;
}


double SpaceCraft::getMaxWeight()
{
	return weightCapacity;
}


int SpaceCraft::getNumCrafts()
{
	return fleetCount;
}


int SpaceCraft::getNumberToCollect()
{
	return totalToCollect;
}


int SpaceCraft::getNumberToVisit()
{
	return totalToVisit;
}


//Returns distance travelled of SpaceCraft
double SpaceCraft::getDistanceTravelled()
{
	return travelled * 10;
}


int SpaceCraft::getCollectedCount()
{
	return collected;
}


int SpaceCraft::getVisitedCount()
{
	return visited;
}

//returns number of captured asteroids from all SpaceCraft
int SpaceCraft::getTotalCollected()
{
	return totalCollected;
}


//returns total distance travelled by SpaceCraft
double SpaceCraft::getTotalDistance()
{
	return totalTravelled * 10;
}


int SpaceCraft::getTotalVisited()
{
	return totalVisited;
}


void SpaceCraft::movePosition(int newX, int newY)
{
	travelled += distanceToAsteroid(newX, newY);
	totalTravelled += distanceToAsteroid(newX, newY);

	x = newX;
	y = newY;
}

//finds closest asteroid to ship
int SpaceCraft::searchField(AsteroidList &astArray, int asteroidPopulation)
{
	
	Asteroid closest = astArray.getAsteroid(0);

	int closestIndex = 0;

	
	int closestX = astArray.getAsteroid(0).getX();
	int closestY = astArray.getAsteroid(0).getY();

	for (int i = 0; i < asteroidPopulation; i++)
	{
		
		int asteroidX = astArray.getAsteroid(i).getX();
		int asteroidY = astArray.getAsteroid(i).getY();

		
		if (distanceToAsteroid(asteroidX, asteroidY) < distanceToAsteroid(closestX, closestY))
		{
			closest = astArray.getAsteroid(i);
			closestIndex = i;
		}
	}
	return closestIndex;
}

void SpaceCraft::setNumberToCollect(int c)
{
	totalToCollect = c;
}

//
void SpaceCraft::setNumberToVisit(int v)
{
	totalToVisit = v;
}

void SpaceCraft::setWeightCapacity(double w)
{
	weightCapacity = w;
}


string SpaceCraft::toString()
{
	string s = "";

	s += SpaceObject::toString();
	s += "Index: " + to_string(position) + '\n';
	s += "Distance travelled: " + to_string(travelled * 10) + " miles" + '\n';


	return s;
}

//destructor
SpaceCraft::~SpaceCraft()
{
	x = 0;
	y = 0;
	travelled = 0;
	totalTravelled = 0;
}