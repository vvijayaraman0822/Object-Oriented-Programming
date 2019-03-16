#include"spaceobject.h"

//returns x value
int SpaceObject::getX()
{
	return x;
}

//returns y value
int SpaceObject::getY()
{
	return y;
}

//sets x value
void SpaceObject::setX(int X)
{
	x = X;
}

//sets y value
void SpaceObject::setY(int Y)
{
	y = Y;
}

//destructor
SpaceObject::~SpaceObject()
{
	x = 0;
	y = 0;
}