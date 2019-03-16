
#include "Asteroid.h"
using namespace std;

Asteroid::Asteroid()
{
	x = 0;
	y = 0;
	size = 0;
	index = 0;
	collected = false;
}
void Asteroid::change()
{
	size = 15;
}
Asteroid::Asteroid(int X, int Y, double Size, int i)
{
	x = X;
	y = Y;
	size = Size;
	index = i;
	collected = false;
}
int Asteroid::getX()
{
	return x;
}

int Asteroid::getY()
{
	return y;
}
int Asteroid::getIndex()
{
	return index;
}
double Asteroid::getWeight()
{
	return size;
}

bool Asteroid::isCollected()
{
	return collected;
}

void Asteroid::changeStatus()
{
	collected = true;
}

Asteroid::~Asteroid()
{

}


