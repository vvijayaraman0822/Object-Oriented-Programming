// Vasudev Vijayaraman

#include "Asteroid.h"
#include<iostream>
using namespace std;

//default constructor
Asteroid::Asteroid()
{
	size = 0;
	collectedStatus = false;
	precious = false;
	visitedStatus = false;
	setName("Asteroid");
}

//parameterized constructor
Asteroid::Asteroid(double Size, bool metal)
{
	size = Size;
	collectedStatus = false;
	precious = metal;
	visitedStatus = false;
	setName("Asteroid");
}

//creates new Asteroid that is exactly like other Asteroid
Asteroid::Asteroid(const Asteroid &other) :SpaceObject(other)
{
	size = other.size;
	collectedStatus = other.collectedStatus;
	visitedStatus = other.visitedStatus;
	precious = other.precious;

}


//gets weight
double Asteroid::getWeight()
{
	return size;
}



bool Asteroid::isCollected()
{
	return collectedStatus;
}


void Asteroid::changeCollectedStatus()
{
	collectedStatus = true;
}


void Asteroid::changeVisitedStatus()
{
	visitedStatus = true;
}

bool Asteroid::hasPreciousMetals()
{
	return precious;
}

bool Asteroid::isVisited()
{
	return visitedStatus;
}



void Asteroid::setCollected(bool flag)
{
	collectedStatus = flag;
}

//sets precious metal in asteroid
void Asteroid::setPreciousStatus(bool flag)
{
	precious = flag;
}

//sets weight of asteroid
void Asteroid::setSize(double s)
{
	size = s;
}

//sets visited status of asteroid
void Asteroid::setVisited(bool flag)
{
	visitedStatus = flag;
}


string Asteroid::toString()
{
	string s = "";
	string conversion;

	s += SpaceObject::toString();

	if (collectedStatus == 0)
		conversion = "no";
	else
		conversion = "yes";
	s += "Collected? " + conversion + '\n';

	if (visitedStatus == 0)
		conversion = "no";
	else
		conversion = "yes";
	s += "Visited? " + conversion + '\n';

	if (precious == 0)
		conversion = "no";
	else
		conversion = "yes";
	s += "Contains precious metals? " + conversion + '\n';

	s += "Weight: " + to_string(size) + '\n';

	return s;

}

Asteroid& Asteroid::operator =(Asteroid &as)
{

	//sets asteroids position at an index
	this->setX(as.getX());
	this->setY(as.getY());

	//sets size of asteroid at index
	this->setSize(as.getWeight());

	//sets collected status at an index
	this->setCollected(as.isCollected());

	//sets visited status at an index
	this->setVisited(as.isVisited());

	//sets status of precious metals in asteroid at an index
	this->setPreciousStatus(as.hasPreciousMetals());



	return *this;


}

//destructor
Asteroid::~Asteroid()
{
	size = 0;
	collectedStatus = false;
	visitedStatus = false;

}