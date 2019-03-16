#include "AsteroidList.h"
#include<iostream>
#include<iomanip>
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


void AsteroidList::add(Asteroid &as)
{
	if (!full())
	{
		A[Total] = as;

		index++;

		Total++;
	}
	else
		cout << "The array is full" << endl;
}


int AsteroidList::count()
{
	return Total;
}


void AsteroidList::decrement()
{
	Total--;
}


bool AsteroidList::empty()
{
	return Total == 0;
}


bool AsteroidList::full()
{
	return (Total == Size);
}


Asteroid& AsteroidList::getAsteroid(int i)
{
	return A[i];
}

//returns asteroids size
int AsteroidList::getSize()
{
	return Size;
}


string AsteroidList::toString()
{
	string s = "";
	for (int m = 0; m < Total; m++)
	{
		s += A[m].toString();
		s += "Position in List: " + to_string(m) + '\n';
	}

	return s;
}

//destructor
AsteroidList::~AsteroidList()
{
	delete[]A;
}

