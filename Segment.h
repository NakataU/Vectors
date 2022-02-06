#ifndef SEGMENT_H
#define SEGMENT_H

#include "Line.h"

class Segment : public Line
{
	friend ostream& operator<<(ostream& out, const Segment& seg);

public:
	Segment();//default
	Segment(const Point&, const Point&);//s nachalna i kraina tochka
	Segment(Point&, Vector&);//s to4ka i posoka
	Segment(Segment&);//copy
	virtual ~Segment();
	double getLength() const;//smqta duljina na otsechka
	Point findMiddle() const;//vrushta to4kata s koordinati (xa + xb)/2 i tn
	Segment& operator=(const Segment&);//assignment operator;
	bool operator==(const Point&) const;//proverka dali to4ka e ot otse4kata

};

ostream& operator<<(ostream& out, const Segment& seg);

#endif