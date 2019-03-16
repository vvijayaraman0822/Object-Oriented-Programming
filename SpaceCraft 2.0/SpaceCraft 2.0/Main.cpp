#include<iostream>
#include<fstream>
#include<iomanip>
#include"asteroidlist.h"
#include"spacecraft.h"
#include"spaceship.h"
#include"spaceprobe.h"
using namespace std;


void closeFiles(ifstream&, ofstream&);
bool determineStartingPosition();
void displayInfo(ofstream&, SpaceShip, int, AsteroidList, double);
void displayProbeInfo(ofstream&, SpaceProbe, int, AsteroidList, double);
void displayProbeTotals(ofstream&, SpaceProbe&);
void displayShipTotals(ofstream&, SpaceShip&);
int getNumCollect(int);
int getNumVisit(int);
void initList(ifstream&, AsteroidList&);
void openDefault(ifstream&, ofstream&);
void openFiles(ifstream&, ofstream&);
int placeProbeX();
int placeProbeY();
int placeShipX();
int placeShipY();
void printProbeHeader(ofstream&);
void printShipHeader(ofstream&);
void turnOnProbe(ofstream&, int, int, int, SpaceProbe&, AsteroidList&);
void turnOnShip(ofstream&, int, int, SpaceShip&, AsteroidList&);

int main()
{
	//Declare variables
	int asteroidX, asteroidY, place;
	int collect, visit;
	int shipX, shipY;
	int probeX, probeY;
	bool defaultPosition;
	int number, totalAsteroids;

	//Open files
	ifstream infile;
	ofstream outfile;

	//true if user wants to use default positions
	defaultPosition = determineStartingPosition();

	//Opens default
	openDefault(infile, outfile);

	//Opens inputted files
	//openFiles(infile, outfile);

	//Initiates SpaceShip
	SpaceShip aShip;

	//Initiates SpaceProbe
	SpaceProbe aProbe;

	//Initiates AsteroidList
	AsteroidList astArray;

	//Adds asteroids to AsteroidList
	initList(infile, astArray);

	//Number of asteroids in array
	totalAsteroids = astArray.count();

	//Header
	printShipHeader(outfile);

	if (!defaultPosition)
	{
		//User sets spaceship's coordinates
		shipX = placeShipX();
		shipY = placeShipY();

		//sets position of ship at user's coordinates
		aShip.setX(shipX);
		aShip.setY(shipY);

		//Number of asteroids that the user wants collected
		//Spaceship gets first access to array, therefore all asteroids available
		collect = getNumCollect(totalAsteroids);

		//ship searches and collects closest asteroid
		//prints out asteroid information
		turnOnShip(outfile, collect, totalAsteroids, aShip, astArray);

		//Outputs SpaceShip totals
		displayShipTotals(outfile, aShip);

		//User sets space probe's coordinates
		probeX = placeProbeX();
		probeY = placeProbeY();

		//sets position of probe at user's coordinates
		aProbe.setX(probeX);
		aProbe.setY(probeY);

		//Spaceship has now collected asteroids
		//Number of asteroids left in array
		number = astArray.count();

		//Number of asteroids that the user wants to visit
		visit = getNumVisit(number);

		//Header
		printProbeHeader(outfile);

		//probe searches and visits closest asteroid
		//prints out asteroid information
		turnOnProbe(outfile, visit, number, totalAsteroids, aProbe, astArray);

		//Outputs SpaceProbe totals
		displayProbeTotals(outfile, aProbe);


	}
	else
	{
		//Sets ship at default position
		aShip.setX(0);
		aShip.setY(0);

		//Number of asteroids that the user wants collected
		//Spaceship gets first access to array, therefore all asteroids available
		collect = getNumCollect(totalAsteroids);

		//ship searches and collects closest asteroid
		//prints out asteroid information
		turnOnShip(outfile, collect, totalAsteroids, aShip, astArray);

		//Outputs SpaceShip totals
		displayShipTotals(outfile, aShip);

		//Sets probe at default position
		aProbe.setX(0);
		aProbe.setY(0);

		//Spaceship has now collected asteroids
		//Number of asteroids left in array
		number = astArray.count();

		//Number of asteroids that the user wants to visit
		visit = getNumVisit(number);

		//Header
		printProbeHeader(outfile);

		//probe searches and visits closest asteroid
		//prints out asteroid information
		turnOnProbe(outfile, visit, number, totalAsteroids, aProbe, astArray);

		//Outputs SpaceProbe totals
		displayProbeTotals(outfile, aProbe);
	}

	//Close files
	closeFiles(infile, outfile);

	system("pause");
	return 0;
}

/**
* @FunctionName: closeFiles
* @Description:
*    closes opened files
* @Params:
*    ifstream &ifile - allows to read from file
*    ofstream &ofile - allows to write to file
* @Returns:
*    void
*/
void closeFiles(ifstream &infile, ofstream &outfile)
{
	infile.close();
	outfile.close();
}

/**
* @FunctionName: determineStartingPosition
* @Description:
*    asks user if spacecrafts should start at default position
* @Params:
*    none
* @Returns:
*    bool - true if spaceship should start at default position
*/
bool determineStartingPosition()
{
	char answer;
	cout << "Should the spaceship and space probe start at default position (0,0)?" << endl;
	cout << " Enter Y/N: ";
	cin >> answer;

	if (answer == 'Y' || answer == 'y')
		return 1;
	else
		return 0;
}

/**
* @FunctionName: displayInfo
* @Description:
*    outputs asteroid information to file
* @Params:
*    ifstream &ofile - allows to write to file
*    Ship spaceship - instance of class ship
*	 int i - index of asteroid
*	 AsteroidList list - instance of AsteroidList
*	 double distance - distance from ship to asteroid
* @Returns:
*    void
*/
void displayInfo(ofstream &ofile, SpaceShip spaceship, int i, AsteroidList list, double distance)
{
	//Ouput order in which asteroids were collected(index)
	ofile << left << setw(26) << i;

	//output position
	ofile << "(" << left << setw(3) << list.getAsteroid(i).getX() << left << setw(2) << "," << left << setw(3)
		<< list.getAsteroid(i).getY() << left << setw(13) << ")";

	//output size
	ofile << left << setw(12) << list.getAsteroid(i).getWeight();

	//output distance
	ofile << distance << endl;
}

void displayProbeInfo(ofstream &ofile, SpaceProbe probe, int i, AsteroidList list, double distance)
{
	//Ouput order in which asteroids were collected(index)
	ofile << left << setw(26) << i;

	//output position
	ofile << "(" << left << setw(3) << list.getAsteroid(i).getX() << left << setw(2) << "," << left << setw(3)
		<< list.getAsteroid(i).getY() << left << setw(13) << ")";

	//output size
	ofile << left << setw(12) << list.getAsteroid(i).getWeight();

	//output distance
	ofile << left << setw(23) << distance;

	//output if asteroid has precious metals or not
	if (list.getAsteroid(i).hasPreciousMetals())
		ofile << "YES" << endl;
	else
		ofile << "NO" << endl;

}


void displayProbeTotals(ofstream &ofile, SpaceProbe &probe)
{
	ofile << endl;

	//copies precious asteroid list in space probe to
	//AsteroidList preciousMetals
	AsteroidList preciousMetals;
	probe.getPictures(preciousMetals);

	double distance = probe.getTotalDistance() * 10;

	//Output number of asteroids collected
	ofile << probe.getTotalCaptured() << " Asteroids visited" << endl;

	//Output total distance
	ofile << "Total distance: " << distance << " miles" << endl;

	//Output number of visited asteroids have precious metals
	ofile << preciousMetals.count() << " asteroid(s) have precious metals" << endl;

}


void displayShipTotals(ofstream &ofile, SpaceShip &spaceship)
{
	ofile << endl;

	double distance = spaceship.getTotalDistance() * 10;

	//Output number of asteroids collected
	ofile << spaceship.getTotalCaptured() << " Asteroids collected" << endl;

	//Output total distance
	ofile << "Total distance: " << distance << endl;

	//Output total size of asteroids
	ofile << "Total weight: " << spaceship.getTotalWeight() << endl;
	ofile << endl;
	ofile << endl;
}

/**
* @FunctionName: getNumCollect
* @Description:
*    prompts user for number of asteroids desired
* @Params:
*    none
* @Returns:
*    int - number of asteroids desired
*/
int getNumCollect(int size)
{
	int num;

	do
	{
		//Prompt user
		cout << "How many asteroids should the spaceship collect?" << endl;

		//User inputs number of asteroids that need to be collected(keyboard)
		cin >> num;

		//if there are not enough asteroids for user's desires
		if (num > size)
			cout << "There are only " << size << " asteroid(s)" << endl;

	} while (num > size);



	return num;
}


int getNumVisit(int size)
{
	int num;

	do
	{

		//Prompt user
		cout << "How many asteroids should the space probe visit?" << endl;

		//User inputs number of asteroids that need to be collected(keyboard)
		cin >> num;

		//if there are not enough asteroids for user's desires
		if (num > size)
			cout << "There are only " << size << " asteroid(s)" << endl;

	} while (num > size);

	return num;
}

/**
* @FunctionName: initList
* @Description:
*    initiates AsteroidList and adds asteroids at an index
* @Params:
*    ifstream &ofile - allows to write to file
*    AsteroidList &astArray - address of AsteroidList
* @Returns:
*    void
*/
void initList(ifstream &ifile, AsteroidList &astArray)
{
	int aX, aY;
	int i = 0;
	double weight;
	char metal;
	bool isPrecious = false;

	//Read file for asteroids' location and size
	ifile >> aX >> aY >> weight >> metal;

	//reads until end of file and while theres not more asteroids
	//than memory allocated
	while (!ifile.eof() && (i < astArray.getSize()))
	{
		//if asteroid has precious metal
		if (metal == 'p' || metal == 'P')
			isPrecious = true;

		//calls paramterized constructor
		Asteroid anAsteroid(weight, isPrecious);

		//sets asteroid's position
		anAsteroid.setX(aX);
		anAsteroid.setY(aY);

		//adds array at an index
		astArray.add(anAsteroid, aX, aY);

		//update index
		i++;

		//resets flag
		isPrecious = false;

		ifile >> aX >> aY >> weight >> metal;
	}
}

void openDefault(ifstream &infile, ofstream &outfile)
{
	infile.open("input.txt");
	outfile.open("output.txt");
}


void openFiles(ifstream &infile, ofstream &outfile)
{
	char inFileName[40];
	char outFileName[40];

	//opens input file
	cout << "enter the input file name : ";
	cin >> inFileName;
	infile.open(inFileName);

	//opens output file
	cout << "enter the output file name : ";
	cin >> outFileName;
	outfile.open(outFileName);
}

/**
* @FunctionName: placeProbeX
* @Description:
*    prompts user for probe's x coordinate
* @Params:
*    none
* @Returns:
*    int - x coordinate
*/
int placeProbeX()
{
	int shipX;

	//prompt user
	cout << "Enter X coordinate : " << endl;

	//User enters initial position of spaceship(keyboard)
	cin >> shipX;

	return shipX;
}

/**
* @FunctionName: placeProbeY
* @Description:
*    prompts user for probe's  y coordinate
* @Params:
*    none
* @Returns:
*    int - y coordinate
*/
int placeProbeY()
{
	int shipY;

	//prompt user
	cout << "Enter Y coordinate : " << endl;

	//User enters initial position of spaceship(keyboard)
	cin >> shipY;

	return shipY;
}

/**
* @FunctionName: placeShipX
* @Description:
*    prompts user for ship's x coordinate
* @Params:
*    none
* @Returns:
*    int - x coordinate
*/
int placeShipX()
{
	int shipX;

	//prompt user
	cout << "Enter X coordinate : " << endl;

	//User enters initial position of spaceship(keyboard)
	cin >> shipX;

	return shipX;
}


int placeShipY()
{
	int shipY;

	//prompt user
	cout << "Enter Y coordinate : " << endl;

	//User enters initial position of spaceship(keyboard)
	cin >> shipY;

	return shipY;
}

/**
* @FunctionName: printProbeHeader
* @Description:
*    prints and sets width of header for probe
* @Params:
*    ofstream &ofile - allows to write to file
* @Returns:
*    void
*/
void printProbeHeader(ofstream &ofile)
{
	ofile << "SPACE PROBE" << endl;

	//Header
	ofile << left << setw(26) << "Asteroid Collected" << left << setw(21)
		<< "Position" << left << setw(10) << "Size" << left << setw(24)
		<< "Distance (in miles)" << "Precious?" << endl;
}

/**
* @FunctionName: printShipHeader
* @Description:
*    prints and sets width of header for ship
* @Params:
*    ofstream &ofile - allows to write to file
* @Returns:
*    void
*/
void printShipHeader(ofstream &ofile)
{
	ofile << "SPACESHIP" << endl;

	//Header
	ofile << left << setw(26) << "Asteroid Collected" << left << setw(21) << "Position"
		<< left << setw(10) << "Size" << "Distance (in miles)" << endl;
}

void turnOnProbe(ofstream &ofile, int visit, int number, int totalAsteroids, SpaceProbe &aProbe, AsteroidList &astArray)
{
	int place;
	int asteroidX, asteroidY;

	//If desired amount of asteroids exceeds number of asteroids in file
	if (visit > number)
	{
		cout << "Not enough asteroids" << endl;
		cout << "There is only " << totalAsteroids << " asteroids!" << endl;
	}
	else
	{
		for (int m = 0; m < visit; m++)
		{
			//Defines variable for closest asteroid
			place = aProbe.searchField(astArray, totalAsteroids);

			//Coordinates of the closest asteroid
			asteroidX = astArray.getAsteroid(place).getX();
			asteroidY = astArray.getAsteroid(place).getY();

			//Distance to the closest asteroid
			double asteroidsDistance = aProbe.distanceToAsteroid(asteroidX, asteroidY) * 10;

			//Collects closest asteroid
			aProbe.takePicture(place, astArray);

			//Outputs asteroids information
			displayProbeInfo(ofile, aProbe, place, astArray, asteroidsDistance);
		}
	}
}

/**
* @FunctionName: turnOnShip
* @Description:
*    Searches for closest asteroid in AsteroidList and collects it.
*	 Then, displays ateroid's information
* @Params:
*    ofstream &ofile - allows to write to file
*	 int collect - number of asteroids to collect
*	 int number - number of asteroids in array
*	 ship &spaceship - address of Ship
*    AsteroidList &astArray - address of AsteroidList
* @Returns:
*    void
*/
void turnOnShip(ofstream &ofile, int collect, int totalAsteroids, SpaceShip &aShip, AsteroidList &astArray)
{
	int place;
	int asteroidX, asteroidY;

	//If desired amount of asteroids exceeds number of asteroids in file
	if (collect > totalAsteroids)
	{
		cout << "Not enough asteroids" << endl;
		cout << "There is only " << totalAsteroids << " asteroids!" << endl;
	}
	else
	{
		for (int m = 0; m < collect; m++)
		{
			//Defines variable for closest asteroid
			place = aShip.searchField(astArray, totalAsteroids);

			//Coordinates of the closest asteroid
			asteroidX = astArray.getAsteroid(place).getX();
			asteroidY = astArray.getAsteroid(place).getY();

			//Distance to the closest asteroid
			double asteroidsDistance = aShip.distanceToAsteroid(asteroidX, asteroidY) * 10;

			//Collects closest asteroid
			aShip.collectAsteroid(place, astArray);

			//Outputs asteroids information
			displayInfo(ofile, aShip, place, astArray, asteroidsDistance);
		}
	}
}