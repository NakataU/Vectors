#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "Triangle.h"

class Tetrahedron : public Triangle
{
public:
	//Default constructor
	Tetrahedron();
	//Parameter constructor
	Tetrahedron(const Point&, const Point&, const Point&, const Point&);
	//Copy constructor
	Tetrahedron(const Tetrahedron&);
	//Overload operator =
	Tetrahedron& operator=(const Tetrahedron&);
	//Destructor
	~Tetrahedron();

	//Getters, Setters
	Point getD()const;

	//Returns the surrounding surface of tetrahedron
	double getSurface() const;
	//Returns the volume of tetrahedron
	double getVolume()const;
	//Returns true if all edges are orthogonal
	bool IsOrthogonal() const;
	//Returns true if all edges are equal
	bool IsRegular() const;

	
private:
	Point D;
};


bool operator<(const Point&, const Tetrahedron&);
bool operator>(const Point&, const Tetrahedron&);
bool operator==(const Point&, const Tetrahedron&);
#endif