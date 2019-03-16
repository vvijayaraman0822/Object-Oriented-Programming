#pragma once

//abstract class
class SpaceObject
{
public:

	//gets y coordinate
	int getX();

	//gets y coordinate
	int getY();

	//sets x coordinate
	void setX(int);

	//sets y coordinate
	void setY(int);

	//destructor
	virtual ~SpaceObject();
protected:
	int x;
	int y;
};
