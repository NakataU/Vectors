#include "Point.h"

//The Big Five
Point::Point() : Element("Point"), x(0), y(0), z(0) {}

Point::Point(double x, double y, double z) : Element("Point"), x(x), y(y), z(z) {}

Point::Point(const Point& rhs) : Element("Point"), x(rhs.x), y(rhs.y), z(rhs.z) {}

Point& Point::operator=(const Point& rhs)
{
	if (&rhs != this)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
	}

	return *this;
}

Point::~Point() {}

//Getters, Setters
double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

double Point::getZ() const
{
	return z;
}

int Point::setX(double x)
{
	this->x = x;
	return 0;
}

int Point::setY(double y)
{
	this->y = y;
	return 0;
}

int Point::setZ(double z)
{
	this->z = z;
	return 0;
}

//Overload operators
bool operator==(const Point& p1, const Point& p2)
{
	return (p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ());
}

std::ostream& operator<<(std::ostream& out, const Point& rhs) {
	out << "(" << rhs.getX() << ", " << rhs.getY() << ", " << rhs.getZ() << ")";
	return out;
}
