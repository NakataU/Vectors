#ifndef POINT_H
#define POINT_H

#include "Element.h"

class Point : public Element
{
public:
	/*
		The Big Five rule
	*/

	//Default constructor
	Point();
	//Parameter constructor
	Point(double, double, double);
	//Copy constructor
	Point(const Point&);
	//Overload operator =
	Point& operator=(const Point&);
	//Destructor
	virtual ~Point();

	//Getters, Setters
	double getX() const, getY() const, getZ() const;
	int setX(double), setY(double), setZ(double);

private:
	double x, y, z;

	//Friend methods
	friend std::ostream& operator<<(std::ostream&, const Point&);
};

//Checks if 2 points are equal.
bool operator==(const Point&, const Point&);
#endif