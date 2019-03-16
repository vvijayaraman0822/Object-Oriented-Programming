#include "Asteroid.h"
using namespace std;

//default constructor
Asteroid::Asteroid()
{
	size = 0;
	collected = false;
	precious = false;
	visited = false;
}

//parameterized constructor
Asteroid::Asteroid(double Size, bool metal)
{
	size = Size;
	collected = false;
	precious = metal;
	visited = false;
}

//creates new Asteroid that is exactly like other Asteroid
Asteroid::Asteroid(const Asteroid &other)
{
	size = other.size;
	collected = other.collected;
	precious = other.precious;

}


//gets weight
double Asteroid::getWeight()
{
	return size;
}


//returns true if asteroid is collected
bool Asteroid::isCollected()
{
	return collected;
}

//changes asteroid status to collected
void Asteroid::changeCollectedStatus()
{
	collected = true;
}

//changes asteroid status to visited
void Asteroid::changeVisitedStatus()
{
	visited = true;
}

bool Asteroid::hasPreciousMetals()
{
	return precious;
}

bool Asteroid::isVisited()
{
	return visited;
}


//sets status of asteroid
void Asteroid::setCollected(bool flag)
{
	collected = flag;
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
	visited = flag;
}

//destructor
Asteroid::~Asteroid()
{
	size = 0;
	collected = false;

}
