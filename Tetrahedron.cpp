#include "Tetrahedron.h"

//Default constructor
Tetrahedron::Tetrahedron() : Triangle(), D(0, 0, 0)
{
	setType("Tetrahedron");
}
//Parameter constructor

//Exceptions
Tetrahedron::Tetrahedron(const Point& A, const Point& B, const Point& C, const Point& D)
{
	setType("Tetrahedron");

	if (A == B)
	{
		throw EqualPointException(A, B);
	}
	else if (A == C)
	{
		throw EqualPointException(A, C);
	}
	else if (A == D) 
	{
		throw EqualPointException(A, D);
	}
	else if (B == C)
	{
		throw EqualPointException(B, C);
	}
	else if (B == D)
	{
		throw EqualPointException(B, D);
	}
	else if (C == D)
	{
		throw EqualPointException(C, D);
	}

	setA(A);
	setB(B);
	setC(C);
	this->D = D;
}
//Copy constructor
Tetrahedron::Tetrahedron(const Tetrahedron& rhs) : Triangle(rhs.getA(), rhs.getB(), rhs.getC()), D(rhs.D)
{
	setType("Tetrahedron");
}
//Overload operator =
Tetrahedron& Tetrahedron:: operator=(const Tetrahedron& rhs)
{
	if (&rhs != this)
	{
		this->setA(rhs.getA());
		this->setB(rhs.getB());
		this->setC(rhs.getC());
		this->D = rhs.D;
	}

	return *this;
}
//Destructor
Tetrahedron::~Tetrahedron()
{
}

Point Tetrahedron::getD()const
{
	return this->D;
}

//Returns the surrounding surface of tetrahedron
double Tetrahedron::getSurface() const
{
	Triangle BCD(this->getB(), this->getC(), this->D);
	Triangle CAD(this->getC(), this->getA(), this->D);
	Triangle ADB(this->getA(), this->D, this->getB());


	//area of triangles 
	double SBCD = BCD.getArea();
	double SCAD = CAD.getArea();
	double SADB = ADB.getArea();
	
	return SBCD+SCAD+SADB;
}
//Returns the volume of tetrahedron
double Tetrahedron::getVolume()const
{
	Vector CA(getC(), getA());//u
	Vector CB(getC(), getB());//v
	//u x v vectorno = uv
	//uv.w
	Vector CD(getC(), D);//w

	return abs(CA(CB, CD))*1/6;

}
//Returns true if all edges are orthogonal
bool Tetrahedron::IsOrthogonal() const
{
	Vector AB(getA(), getB());
	Vector CD(getC(), D);
	Vector AC(getA(),getC());
	Vector BD(getB(),D);
	Vector AD(getA(),D);
	Vector BC(getB(),getC());

	return AB.isPerpendicularWith(CD) && AC.isPerpendicularWith(BD) && AD.isPerpendicularWith(BC);

}
//Returns true if all edges are equal
bool Tetrahedron::IsRegular() const
{
	//comperison of Triangles

	Triangle BCD(this->getB(), this->getC(), this->D);
	Triangle CAD(this->getC(), this->getA(), this->D);
	Triangle ADB(this->getA(), this->D, this->getB());
	Triangle CAB(this->getC(), this->getA(), this->getB());

	//comperison of Perimeters

	double PBCD = BCD.getPerimeter();
	double PCAD = CAD.getPerimeter();
	double PADB = ADB.getPerimeter();
	double PCAB = CAB.getPerimeter();

	bool allEq = BCD.isEquilateral() && CAD.isEquilateral() && ADB.isEquilateral() && CAB.isEquilateral();
	bool allP = (PBCD - PCAD + PADB - PCAB) == 0;

	return allEq && allP;
}

//Inside
bool operator<(const Point& lhs, const Tetrahedron& rhs)
{
	
	Triangle BCD(rhs.getB(), rhs.getC(), rhs.getD());
	Triangle CAD(rhs.getC(), rhs.getA(), rhs.getD());
	Triangle ADB(rhs.getA(), rhs.getD(), rhs.getB());
	Triangle CAB(rhs.getC(), rhs.getA(), rhs.getB());
    //BCD
	Vector BC(rhs.getB(), rhs.getC());
	Vector BD(rhs.getB(), rhs.getD());
	
	//normala
	Vector BCDn = (BD ^ BC);
	//d
	double BCDplaned = (rhs.getB().getX() * BCDn.getX() + rhs.getB().getY() * BCDn.getY() + rhs.getB().getZ() * BCDn.getZ()) * -1;
    //a*x+b*y+c*z+d=0
    double BCDpl = lhs.getX()*BCDn.getX()+ lhs.getY() * BCDn.getY()+ lhs.getZ() * BCDn.getZ()+BCDplaned;

	//CAD
	Vector CA(rhs.getC(),rhs.getA());
	Vector CD(rhs.getC(),rhs.getD());
	//normala
	Vector CADn = (CD ^ CA);
	//d
	double CADplaned = (rhs.getC().getX() * CADn.getX() + rhs.getC().getY() * CADn.getY() + rhs.getC().getZ() * CADn.getZ()) * -1;
	//a*x+b*y+c*z+d=0
	double CADpl= lhs.getX() * CADn.getX() + lhs.getY() * CADn.getY() + lhs.getZ() * CADn.getZ() + CADplaned;

	//ADB
	Vector AB (rhs.getA(), rhs.getB());
    Vector AD (rhs.getA(), rhs.getD());
	//normala
	Vector ADBn = (AD ^ AB);
	//d
	double ADBplaned = (rhs.getB().getX() * ADBn.getX() + rhs.getB().getY() * ADBn.getY() + rhs.getB().getZ() * ADBn.getZ()) * -1;
	//a*x+b*y+c*z+d=0
    double ADBpl = lhs.getX() * ADBn.getX() + lhs.getY() * ADBn.getY() + lhs.getZ() * ADBn.getZ() + ADBplaned;

	//CAB
	
	Vector CB(rhs.getC(), rhs.getB());

	//normala
	Vector CABn = (CA ^ CB);
	//d
	double CABplaned = (rhs.getB().getX() * CABn.getX() + rhs.getB().getY() * CABn.getY() + rhs.getB().getZ() * CABn.getZ()) * -1;
	//a*x+b*y+c*z+d=0
	double CABpl = lhs.getX() * CABn.getX() + lhs.getY() * CABn.getY() + lhs.getZ() * CABn.getZ() + CABplaned;

	//cout << BCDpl << " " << CADpl << " " << ADBpl << " " << CABpl << endl;



	return BCDpl < 0 && CADpl < 0 && ADBpl < 0 && CABpl < 0;
}

bool operator>(const Point& lhs, const Tetrahedron& rhs)
{
	return !(operator <(lhs,rhs)) && !(operator==(lhs,rhs));
}
bool operator==(const Point& lhs, const Tetrahedron& rhs)
{

	Triangle BCD(rhs.getB(), rhs.getC(), rhs.getD());
	Triangle CAD(rhs.getC(), rhs.getA(), rhs.getD());
	Triangle ADB(rhs.getA(), rhs.getD(), rhs.getB());
	Triangle CAB(rhs.getC(), rhs.getA(), rhs.getB());


	return lhs == BCD || lhs == CAD || lhs == ADB || lhs == CAB;
}

