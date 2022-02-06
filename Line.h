#ifndef LINE_H
#define LINE_H

#include "Vector.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Line : public Vector {

    //Making the external methods friends of the class
    friend ostream & operator<<(ostream & out, const Line & l);    //For printing
    friend bool operator+(const Point& p1, const Line& lb);        //Check if a Point lies on a Line
    friend bool operator||(const Line& la, const Line& lb);        //Check if a Line is parallel to another Line
    friend bool operator==(const Line& la, const Line& lb);        //Check if two Lines coincide
    friend bool operator&&(const Line& la, const Line& lb);        //Check if one Line intersects with another Line
    friend bool operator!=(const Line& la, const Line& lb);        //Check if one Line is crossed with another Line
    friend bool operator|(const Line& la, const Line& lb);         //Check if one Line is perpendicular to another Line

public:

    //Default constructor
    Line();

    //Constructor with a Point and a Vector
    Line(const Point &linePoint1, const Vector &lineVector);

    //Constructor with two Points
    Line(const Point &linePoint1, const Point &linePoint2);

    //Copy constructor
    Line(const Line&);

    //Overload operator =
    //Line& operator=(const Line&);

    //Destructor
    virtual ~Line();

    //Getters and Setters
    const Point &getLinePoint1() const;
    void setLinePoint1(const Point &linePoint1);

    const Point &getLinePoint2() const;
    void setLinePoint2(const Point &linePoint2);

    const Vector &getLineVector() const;
    void setLineVector(const Vector &lineVector);


    //Method to convert two Points into a Vector*
    static Vector convertPointsToVector(Point a, Point b);

    //Method to find if the Z slope of the lines is equal*
    static bool IsZSlopeOfTwoLinesEqual(const Line& la, const Line& lb);

    //Method to find the direction of a Line    (ZAD1-Line)
    Vector findLineDirection();

    //Method to find the normal Vector of a Line    (ZAD2-Line)
    Vector findNormalVector();

    //Method to find the angle between two Lines    (ZAD3-Line)
    static double findAngleBetweenTwoLines(const Line &la, const Line &lb);

    //Method to find the orientation of the Line*
    static int findLineOrientation(Point p, Point q, Point r);

    //Method to check the segment of a Line*
    static bool checkSegment(Point p, Point q, Point r);

private:

    Point linePoint1;
    Point linePoint2;
    Vector lineVector;

};

//External methods
ostream & operator<<(ostream & out, const Line & l);

bool operator+(const Point& p1, const Line& lb);

bool operator||(const Line& la, const Line& lb);

bool operator==(const Line& la, const Line& lb);

bool operator&&(const Line& la, const Line& lb);

bool operator!=(const Line& la, const Line& lb);

bool operator|(const Line& la, const Line& lb);

#endif