#include "AsteroidList.h"
#include<iostream>
using namespace std;


//Default contructor
AsteroidList::AsteroidList()
{
	Total = 0;
	Size = MAXITEMS;
	A = new Asteroid[Size];

}

//Parameterized constructor
AsteroidList::AsteroidList(int num)
{
	Total = 0;
	Size = num;
	A = new Asteroid[Size];
}

// adds an asteroid
void AsteroidList::add(int i, Asteroid x)
{
	if (!full())
	{
		A[i] = x;
		Total++;
	}
	else
		cout << "The array is full" << endl;
}

// counts the number of asteroid 
int AsteroidList::count()
{
	return Total;
}

// -1 from the asteroid list
void AsteroidList::decrement()
{
	Total--;
}

// returns full or not
bool AsteroidList::full()
{
	return (Total == Size);
}

Asteroid& AsteroidList::getAsteroid(int i)
{
	return A[i];
}

void AsteroidList::print()
{
	for (int i = 0; i < Total; i++)
	{
		cout << A[i].getX() << endl;
	}
}

AsteroidList::~AsteroidList()
{
	//delete[] A;
}