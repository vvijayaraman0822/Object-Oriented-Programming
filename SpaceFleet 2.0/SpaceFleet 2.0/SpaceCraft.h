// Vasudev Vijayaraman

#pragma once
#include"SpaceObject.h"
#include"AsteroidList.h"
#include<math.h>




class SpaceCraft : public SpaceObject
{
public:
	//default constructor
	SpaceCraft();

	//parameterized constructor
	SpaceCraft(int, int, int, int);

	//copy constructor
	SpaceCraft(const SpaceCraft&);

	
	virtual void collect(int, AsteroidList&);
	void copyList(AsteroidList&);
	double distanceToAsteroid(int, int);
	int getCollectedCount();
	double getDistanceTravelled();
	string getList();
	double getMaxWeight();
	int getNumCrafts();

	
	int getNumberToCollect();
	int getNumberToVisit();
	int getTotalCollected();
	double getTotalDistance();
	int getTotalVisited();
	int getVisitedCount();

	//changes the position of Ship
	//updates totalDistance
	void movePosition(int, int);

	//Finds closest asteorid to collect
	virtual int searchField(AsteroidList&, int);

	//Sets number of asteroid to collect
	void setNumberToCollect(int);

	//Sets number of asteroid to visit
	void setNumberToVisit(int);

	//Sets max size all SpaceShip can collect
	void setWeightCapacity(double);

	//Returns a status report
	virtual string toString();

	//Destructor
	virtual ~SpaceCraft();


protected:
	double travelled;
	int collected;
	int visited;
	int fleetCount;
	int position;

	static double weightCapacity;
	static int totalToVisit;
	static int totalToCollect;
	static int totalCollected;
	static int totalVisited;
	static double totalTravelled;
	static AsteroidList preciousAsteroids;

};



