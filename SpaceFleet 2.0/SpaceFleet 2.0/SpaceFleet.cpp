// Name    : Vasudev Vijayaraman

// Course  : Object Oriented Prgramming, CMPS - 2143
//           Fall 2017, Dr. Catherine Stringfellow

// Purpose : This program has six classes named SpaceCraft, AsteroidList, SpaceObject, SpaceProbe and Spaceship 
//           and Asteroid. The main concept used is this program in inheritance and overriding. uses an array to hold x and y coordinates.
//			 We build a Spaceship and control its actions, on.  A spaceship will search a “field” of asteroids and go to the 
//			 closest asteroid. The remaining asteroids are computed again, and the spaceship will go the next closest asteroid.  
//           It will continue to do this for the number of asteroids that the user wants collect. The program takes in an input
//           file named input.txt and the outfile is named output.txt


#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include"Asteroid.h"
#include"AsteroidList.h"
#include"SpaceCraft.h"
#include"SpaceShip.h"
#include"SpaceProbe.h"
using namespace std;

// Array of pointers
typedef SpaceCraft *aFleet[50];


// Prototyping
void open(ifstream&, ifstream&, ofstream &);

//Closes files
void closeFiles(ifstream&, ifstream&, ofstream&);


void displayCraftInfo(ofstream&, aFleet&, AsteroidList*&);
void displayPreciousList(AsteroidList*&, ofstream&);
void displayShipInfo(ofstream&, int, AsteroidList*&, double, int);
void displayTotals(ofstream&, aFleet&, int);

//Returns number of SpaceShips
int getNumberOfShips(aFleet&, int);

//Returns number of SpaceProbes
int getNumberOfProbes(aFleet&, int);

//Initiation
void initList(ifstream&, AsteroidList&);
void initFleet(ifstream&, aFleet&);

//Opens files
void openFiles(ifstream&, ifstream&, ofstream&);

void printCollectedHeader(ofstream&);
void turnOnProbe(aFleet&, AsteroidList*&, int, int, int);
void turnOnShip(aFleet&, AsteroidList*&, int, int, ofstream&);



int main()
{
	//Declare variables and their types
	int number;
	int probeCount;
	int fleetCount;

	
	ifstream infile;
	ifstream spaceFile;
	ofstream outfile;


	open(infile, spaceFile, outfile);
	AsteroidList *astArray = new AsteroidList();

	
	initList(infile, *astArray);

	//Array of SpaceCraft pointers
	aFleet fleet;

	//Number of asteroids in array
	number = astArray->count();

	
	initFleet(spaceFile, fleet);
	fleetCount = fleet[0]->getNumCrafts();
	probeCount = getNumberOfProbes(fleet, fleetCount);
	turnOnProbe(fleet, astArray, number, probeCount, fleetCount);
	AsteroidList *preciousList = new AsteroidList();



	fleet[0]->copyList(*preciousList);
	displayPreciousList(preciousList, outfile);
	number = preciousList->count();
	printCollectedHeader(outfile);
	turnOnShip(fleet, preciousList, number, fleetCount, outfile);
	displayCraftInfo(outfile, fleet, astArray);


	//Writes totals of SpaceCraft to file
	displayTotals(outfile, fleet, probeCount);


	//Close files
	closeFiles(infile, spaceFile, outfile);


	system("pause");
	return 0;
}
void open(ifstream& ifile, ifstream& sfile, ofstream &ofile)
{
	ifile.open("input.txt");
	sfile.open("Spacecraft.txt");
	ofile.open("output.txt");
}

// Closes files
void closeFiles(ifstream &infile, ifstream &sfile, ofstream &outfile)
{
	infile.close();
	sfile.close();
	outfile.close();
}

//displays information about the craft
void displayCraftInfo(ofstream &ofile, aFleet &fleet, AsteroidList *&astArray)
{
	//Number of SpaceCraft
	int fleetSize = fleet[0]->getNumCrafts();

	//Displays each SpaceCraft's status report
	for (int i = 0; i < fleetSize; i++)
	{
		ofile << fleet[i]->toString() << endl;
	}
}

// displays precious list
void displayPreciousList(AsteroidList *&precious, ofstream &ofile)
{
	ofile << "PRECIOUS LIST" << endl;
	//Header
	ofile << left << setw(26)
		<< "Asteroid" << left << setw(21)
		<< "Position" << left << setw(10) << "Size" << endl;

	for (int i = 0; i < precious->count(); i++)
	{
		//Ouput order in which asteroids were collected(index)
		ofile << left << setw(26) << i;

		//output position
		ofile << "(" << left << setw(3) << precious->getAsteroid(i).getX() << left << setw(2) << "," << left << setw(3)
			<< precious->getAsteroid(i).getY() << left << setw(13) << ")";

		//output size
		ofile << left << setw(12) << precious->getAsteroid(i).getWeight();

		ofile << endl;
	}

	
}


// displays ship info
void displayShipInfo(ofstream &ofile, int i, AsteroidList *&preciousList, double distance, int position)
{
	// outputs to file
	ofile << left << setw(26) << position;
	ofile << left << setw(26) << i;
	ofile << "(" << left << setw(3) << preciousList->getAsteroid(i).getX() << left << setw(2) << "," << left << setw(3)
		<< preciousList->getAsteroid(i).getY() << left << setw(13) << ")";
	ofile << left << setw(12) << preciousList->getAsteroid(i).getWeight();
	ofile << distance << endl;
}

// displays totals
void displayTotals(ofstream &ofile, aFleet &fleet, int count)
{
	//Downcast fleet at index of first SpaceSihp
	SpaceShip *ship = dynamic_cast<SpaceShip*>(fleet[count]);

	ofile << "Total collected: " << fleet[0]->getTotalCollected() << endl;

	ofile << "Total visited: " << fleet[0]->getTotalVisited() << endl;

	ofile << "Total Distance: " << fleet[0]->getTotalDistance() << " miles" << endl;

	ofile << "Total weight in SpaceShips: " << ship->getTotalWeight() << endl;


}


// gets number of probes
int getNumberOfProbes(aFleet &f, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (f[i]->getName() == "SpaceProbe")
			count++;
	}

	return count;
}


int getNumberOfShips(aFleet &f, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (f[i]->getName() == "SpaceShip")
			count++;
	}

	return count;
}


void initFleet(ifstream &sfile, aFleet &fleet)
{
	int i = 0;
	int fleetSize, X, Y;
	double maxWeight;
	int asteroidsForProbe, asteroidsForShip;
	char type;

	
	sfile >> fleetSize;
	sfile >> asteroidsForProbe;
	sfile >> asteroidsForShip;
	sfile >> maxWeight;

	
	fleet[0]->setNumberToCollect(asteroidsForShip);
	fleet[0]->setNumberToVisit(asteroidsForProbe);
	fleet[0]->setWeightCapacity(maxWeight);


	while (!sfile.eof())
	{
		//Type of SpaceCraft,X-coordinate,Y-coordinate
		sfile >> type >> X >> Y;

		//Initiates SpaceShip
		if (type == 'p' || type == 'P')
			fleet[i] = new SpaceProbe(X, Y, fleetSize, i);
		//Initiates SpaceProbe
		else
		{
			fleet[i] = new SpaceShip(X, Y, fleetSize, i);
		}

		//Updates index
		i++;
	}
}


void initList(ifstream &ifile, AsteroidList &astArray)
{
	int aX, aY;
	int i = 0;
	double weight;
	char metal;
	bool isPrecious = false;

	
	ifile >> aX >> aY >> weight >> metal;

	while (!ifile.eof() && (i < astArray.getSize()))
	{
		
		if (metal == 'p' || metal == 'P')
			isPrecious = true;

		
		Asteroid *anAsteroid = new Asteroid(weight, isPrecious);

		
		anAsteroid->setX(aX);
		anAsteroid->setY(aY);
		astArray.add(*anAsteroid);
		i++;
		isPrecious = false;

		ifile >> aX >> aY >> weight >> metal;
	}

}

// opens files
void openFiles(ifstream &infile, ifstream &spaceFile, ofstream &outfile)
{
	char inFileName[40];
	char spaceFileName[40];
	char outFileName[40];

	
	cout << "What is the Asteroid's input file name?";
	cin >> inFileName;
	infile.open(inFileName);

	cout << "What is the SpaceCrfat's input file name?";
	cin >> spaceFileName;
	spaceFile.open(spaceFileName);

	//opens output file
	cout << "What file do you want your output to go to? ";
	cin >> outFileName;
	outfile.open(outFileName);
}


void printCollectedHeader(ofstream &ofile)
{
	ofile << "COLLECTED ASTEROIDS" << endl;

	//Header
	ofile << left << setw(26) << "SpaceCraft position" << left << setw(26)
		<< "Asteroid Collected" << left << setw(21)
		<< "Position" << left << setw(10) << "Size"
		<< "Distance (in miles)" << endl;
}



void turnOnProbe(aFleet &fleet, AsteroidList *&astArray, int asteroidCount, int probeCount, int fleetSize)
{
	
	int place;

	
	int toVisit = fleet[0]->getNumberToVisit();


	if (toVisit > asteroidCount)
	{
		cout << "There are not enough asteroids in the list "
			<< "for the probes to visit." << endl;

		cout << "Number of asteroids in list: " << asteroidCount << endl;
		cout << "Number of asteroids probes need to visit: " << toVisit << endl;
		cout << endl;
	}
	else
	{
		for (int i = 0; i < toVisit; i++)
		{
			
			if (fleet[i % probeCount]->getName() == "SpaceProbe")
			{
				place = fleet[i % probeCount]->searchField(*astArray, asteroidCount);

				if (place >= 0)
				{
					fleet[i % probeCount]->collect(place, *astArray);
				}
			}

		}

	}
}


void turnOnShip(aFleet &fleet, AsteroidList *&preciousList, int asteroidCount, int size, ofstream &ofile)
{
	int place;

	//index
	int i = 0;

	//Number of asteroids SpaceShip is supposed to collect
	int toCollect = fleet[0]->getNumberToCollect();

	
	if (toCollect > asteroidCount)
	{
		cout << "There are not enough asteroids in the list "
			<< "for the ships to collect." << endl;

		cout << "Number of asteroids in list: " << asteroidCount << endl;
		cout << "Number of asteroids ships need to collect: " << toCollect << endl;
		cout << endl;
	}
	else
	{
		while ((fleet[0]->getTotalCollected() != toCollect) && !preciousList->empty())
		{
			//Only collects if SpaceCraft is a SpaceShip
			if (fleet[i%size]->getName() == "SpaceShip")
			{
				place = fleet[i%size]->searchField(*preciousList, asteroidCount);

				//If index is a valid number
				if (place >= 0)
				{
					//Coordinates of the closest asteroid
					int asteroidX = preciousList->getAsteroid(place).getX();
					int asteroidY = preciousList->getAsteroid(place).getY();

					
					double asteroidsDistance = fleet[i%size]->distanceToAsteroid(asteroidX, asteroidY);

					fleet[i%size]->collect(place, *preciousList);

					int shipPosition = i%size;

					displayShipInfo(ofile, place, preciousList, asteroidsDistance, shipPosition);
				}
			}
			i++;
		}
	}


}

