#include "AsteroidList.h"
#include<iostream>
using namespace std;


//Default contructor
AsteroidList::AsteroidList()
{
	index = 0;
	Total = 0;
	Size = MAXITEMS;
	A = new Asteroid[Size];

}

//Parameterized constructor
AsteroidList::AsteroidList(int num)
{
	index = 0;
	Total = 0;
	Size = num;
	A = new Asteroid[Size];
}

//creates new AsteroidList that is exactly like other AsteroidList
AsteroidList::AsteroidList(const AsteroidList & other)
{
	A = new Asteroid[other.Size];
	for (int j = 0; j < other.Size; j++)
		A[j] = other.A[j];
	Total = other.Total;
	Size = other.Size;


}

//Adds an Asteroid object to array
void AsteroidList::add(Asteroid &as, int X, int Y)
{
	if (!full())
	{
		//sets asteroids position at an index
		A[index].setX(as.getX());
		A[index].setY(as.getY());

		//sets size of asteroid at index
		A[index].setSize(as.getWeight());

		//sets collected status at an index
		A[index].setCollected(as.isCollected());

		//sets visited status at an index
		A[index].setVisited(as.isVisited());

		//sets status of precious metals in asteroid at an index
		A[index].setPreciousStatus(as.hasPreciousMetals());

		index++;

		Total++;
	}
	else
		cout << "The array is full" << endl;
}

//amount of asteroids currently in array
int AsteroidList::count()
{
	return Total;
}

//decrements total by 1
void AsteroidList::decrement()
{
	Total--;
}

//returns true if array is full
bool AsteroidList::full()
{
	return (Total == Size);
}

//returns address of asteroid at an index
Asteroid& AsteroidList::getAsteroid(int i)
{
	return A[i];
}

//returns asteroids size
int AsteroidList::getSize()
{
	return Size;
}

//destructor
AsteroidList::~AsteroidList()
{
	delete[]A;
}