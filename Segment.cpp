#include "Segment.h"

Segment::Segment()
{
	setType("Segment");
	setLinePoint1(Point(0, 0, 0));
	setLinePoint2(Point(0, 0, 0));
	setLineVector(Vector(getLinePoint1(), getLinePoint2()));
}
Segment::Segment(const Point& start, const Point& end)
{
	setType("Segment");
	setLinePoint1(start);
	setLinePoint2(end);
	setLineVector(Vector(getLinePoint1(), getLinePoint2()));
}

Segment::Segment(Point& p, Vector& vec)
{
	//t=1
	//x = a+b
	//b = x - a
	setType("Segment");
	setLinePoint1(p);
	setLinePoint2(Point(vec.getX() - p.getX(), vec.getY() - p.getY(), vec.getZ() - p.getZ()));
	setLineVector(Vector(getLinePoint1(), getLinePoint2()));
}
Segment::Segment(Segment& cpyObj)
{
	setType("Segment");
	setLinePoint1(cpyObj.getLinePoint1());
	setLinePoint2(cpyObj.getLinePoint2());
	setLineVector(Vector(getLinePoint1(), getLinePoint2()));
}

double Segment::getLength()const
{
	return getLineVector().getMagnitude();
}
Point Segment::findMiddle()const
{
	Point mid;
	mid.setX((getLinePoint1().getX() + getLinePoint2().getX()) / 2);
	mid.setY((getLinePoint1().getY() + getLinePoint2().getY()) / 2);
	mid.setZ((getLinePoint1().getZ() + getLinePoint2().getZ()) / 2);
	return mid;
}
bool Segment::operator==(const Point& p)const
{
	double xT, yT, zT;
	//coefficents in front of t for x,y,z of given point
	Vector lineVec = getLineVector();
	if (lineVec.getX() != 0)
		xT = (p.getX() - getLinePoint1().getX()) / lineVec.getX();
	else
		xT = p.getX() - getLinePoint1().getX();
	if (lineVec.getY() != 0)
		yT = (p.getY() - getLinePoint1().getY()) / lineVec.getY();
	else
		yT = p.getY() - getLinePoint1().getY();
	if (lineVec.getZ() != 0)
		zT = (p.getZ() - getLinePoint1().getZ()) / lineVec.getZ();
	else
		zT = p.getZ() - getLinePoint1().getZ();
	if (xT >= 0 && xT <= 1 && yT >= 0 && yT <= 1 && zT >= 0 && zT <= 1)
	{
		return true;
	}
	return false;
}
Segment::~Segment()
{

}
Segment& Segment::operator=(const Segment& obj)
{
	setLinePoint1(obj.getLinePoint1());
	setLinePoint2(obj.getLinePoint2());
	setLineVector(Vector(getLinePoint1(), getLinePoint2()));
	return *this;
}

ostream& operator<<(ostream& out, const Segment& seg)
{
	out << "Segment: \n" << seg.getLinePoint1() << "\n" << seg.getLinePoint2() << "\nLength: " << seg.getLength() << "\nMiddle: " << seg.findMiddle() << '\n';
	return out;
}
