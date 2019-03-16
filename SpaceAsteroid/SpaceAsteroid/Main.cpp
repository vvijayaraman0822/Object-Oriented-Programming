// Name    : Vasudev Vijayaraman

// Course  : Object Oriented Prgramming

// Purpose : This program has three classes named Ship, AsteroidList and Asteroid and uses an array to hold x and y coordinates.
//			 We build a Spaceship and control its actions, on.  A spaceship will search a “field” of asteroids and go to the 
//			 closest asteroid. The remaining asteroids are computed again, and the spaceship will go the next closest asteroid.  
//           It will continue to do this for the number of asteroids that the user wants collect. The program takes in an input
//           file named input.txt and the outfile is named output.txt
			 


#include<iostream>
#include<fstream> //input and output files
#include<iomanip> // formatting
#include<math.h>	
#include "Asteroid.h"
#include "AsteroidList.h"
#include "Spaceship.h"
using namespace std;

void closeFiles(ifstream&, ofstream&);
void displayInfo(ofstream&, Ship, int, AsteroidList, double);
int getNumCollect();
void initList(ifstream&, AsteroidList&);
void openFiles(ifstream&, ofstream&);
int placeShipX();
int placeShipY();
void printHeader(ofstream&);


int main()
{
	// declare variables
	int asteroidX, asteroidY;
	double weight;
	int collect;
	int shipX, shipY;

	//Open files
	ifstream infile;
	ofstream outfile;
	openFiles(infile, outfile);


	shipX = placeShipX();
	shipY = placeShipY();
	
	// Stores how many Asteroids the user enters at the screen to be collected
	collect = getNumCollect();

	//Initiates AsteroidList
	AsteroidList astArray(collect);
	AsteroidList collectedAsteroids(collect);
	//Adds asteroids to AsteroidList
	initList(infile, astArray);


	printHeader(outfile);



	//Letting the spaceship go
	Ship spaceship(shipX, shipY, collect);

	Asteroid found;
	int place;
	for (int m = 0; m < collect; m++)
	{
	
		place = spaceship.searchField(astArray);

		//Coordinates of the closest asteroid
		asteroidX = astArray.getAsteroid(place).getX();
		asteroidY = astArray.getAsteroid(place).getY();

		//Distance to the closest asteroid
		double asteroidsDistance = spaceship.distanceToAsteroid(asteroidX, asteroidY);

		//Collects closest asteroid
		spaceship.collectAsteroid(place, astArray);

		displayInfo(outfile, spaceship, place, astArray, asteroidsDistance);
	}



	//Output number of asteroids collected
	outfile << spaceship.totalCollected() << " Asteroids collected" << endl;

	//Output total distance
	outfile << "Total distance" << spaceship.totalDistance() << endl;

	
	closeFiles(infile, outfile);
	system("pause");
	return 0;
}

void closeFiles(ifstream &infile, ofstream &outfile)
{
	infile.close();
	outfile.close();
}
void displayInfo(ofstream &ofile, Ship spaceship, int i, AsteroidList list, double distance)
{
	//Ouput order in which asteroids were collected
	ofile << i;

	
	ofile << right << setw(25) << "(" << list.getAsteroid(i).getX() << "," << list.getAsteroid(i).getY() << ")";

	//print size
	ofile << right << setw(27) << list.getAsteroid(i).getWeight();

	
	ofile << right << setw(23) << distance << endl;
}

int getNumCollect()
{
	int num;

	
	cout << "How many asteroids should the spaceship collect?" << endl;

	cin >> num;

	return num;
}

void initList(ifstream &ifile, AsteroidList &astArray)
{
	int aX, aY;
	int i = 0;
	double weight;

	
	ifile >> aX >> aY >> weight;
	while (!ifile.eof())
	{
		Asteroid anAsteroid(aX, aY, weight, i);

		astArray.add(i, anAsteroid);

		i++;

		ifile >> aX >> aY >> weight;
	}
}



void openFiles(ifstream &infile, ofstream &outfile)
{
	string ifile = "input.txt";
	infile.open(ifile);

	string ofile = "output.txt";
	outfile.open(ofile);
}

int placeShipX()
{
	int shipX;


	cout << "Enter X coordinate: " << endl;

	
	cin >> shipX;

	return shipX;
}

int placeShipY()
{
	int shipY;

	
	cout << "Enter Y coordinate : " << endl;

	//initial position entered  by user
	cin >> shipY;

	return shipY;
}

void printHeader(ofstream &ofile)
{

	ofile << "Asteroid Collected" << setw(15) << "Position" << setw(25) << "Size"
		<< setw(25) << "Distance" << endl;
}