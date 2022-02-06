#include "Line.h"

//Constructors:

Line::Line() {
    setType("Line");

    linePoint1 = Point(NULL, NULL, NULL);
    linePoint2 = Point(NULL, NULL, NULL);
    lineVector = Vector(NULL, NULL, NULL);
}

Line::Line(const Point &linePoint1, const Vector &lineVector) :
        linePoint1(linePoint1), lineVector(lineVector) {

    setType("Line");
    linePoint2 = Point(lineVector.getX()+linePoint1.getX(),
                       lineVector.getY()+linePoint1.getY(),
                       lineVector.getZ()+linePoint1.getZ());

}

Line::Line(const Point &linePoint1, const Point &linePoint2) :
        linePoint1(linePoint1), linePoint2(linePoint2) {

    setType("Line");
    lineVector = convertPointsToVector(linePoint1, linePoint2);
}



Line::Line(const Line &la) {
    setType("Line");
    this->linePoint1 = la.linePoint1;
    this->linePoint2 = la.linePoint2;
    this->lineVector = la.lineVector;
}

/**
Line &Line::operator=(const Line &rhs) {
    if (&rhs != this)
    {
        this->setX(rhs.getX());
        this->setY(rhs.getY());
        this->setZ(rhs.getZ());
    }
    return *this;
}
 */

Line::~Line() {}

//Getters and Setters:

const Point &Line::getLinePoint1() const {
    return linePoint1;
}

void Line::setLinePoint1(const Point &lp1) {
    Line::linePoint1 = lp1;
}

const Point &Line::getLinePoint2() const {
    return linePoint2;
}

void Line::setLinePoint2(const Point &lp2) {
    Line::linePoint2 = lp2;
}

const Vector &Line::getLineVector() const {
    return lineVector;
}

void Line::setLineVector(const Vector &lv) {
    Line::lineVector = lv;
}

//Class-internal methods:

Vector Line::convertPointsToVector(Point a, Point b) {
    return Vector(a, b);
}

Vector Line::findLineDirection() {

    if (linePoint1.getY() > linePoint2.getY()) {
        Vector t(this->lineVector);
        Vector v1(linePoint2.getX() - linePoint1.getX(),
                  linePoint2.getY() - linePoint1.getY(),
                  linePoint2.getZ() - linePoint1.getZ());
        cout << "The direction of the line is DOWNWARDS.\nVector = " << v1 << '\n';
        return v1;
    } else if (linePoint1.getY() < linePoint2.getY()) {
        Vector v1(linePoint2.getX() - linePoint1.getX(),
                  linePoint2.getY() - linePoint1.getY(),
                  linePoint2.getZ() - linePoint1.getZ());
        cout << "The direction of the line is UPWARDS.\nVector = " << v1 << '\n';
        return v1;
    } else if (linePoint1.getY() == linePoint2.getY()) {
        Vector v1(linePoint2.getX() - linePoint1.getX(),
                  linePoint2.getY() - linePoint1.getY(),
                  linePoint2.getZ() - linePoint1.getZ());
        cout << "The direction of the line is PLANE (NO DIRECTION).\n\nVector = " << v1 << '\n';
        return v1;
    } else {
        return Vector(NULL, NULL, NULL);
    }
}

Vector Line::findNormalVector() {

    double findX;
    double findY;

    findX = this->linePoint2.getX() - this->linePoint1.getX();
    findY = this->linePoint2.getY() - this->linePoint1.getY();

    Point a(-findY, findX, this->linePoint1.getZ());
    Point b(findY, -findX, this->linePoint2.getZ());
    Vector res(a, b);

    return res;
}



double Line::findAngleBetweenTwoLines(const Line &la, const Line &lb) {

    bool checkIfParallel = (la||lb) || (la==lb);
    if (checkIfParallel) {
        cout << "\nThe two lines are parallel!\n";
        return 0;
    }
    bool checkIfIntersect = (!(la&&lb)) || (la!=lb);
    if (checkIfIntersect) {
        cout << "\nThe two lines do not intersect!\n";
        return 0;
    }

    double scalar;
    double vectorLength1;
    double vectorLength2;
    double angleArcsin;
    double angleRad;

    scalar = (la.lineVector.getX()*lb.lineVector.getX()) +
             (la.lineVector.getY()*lb.lineVector.getY()) +
             (la.lineVector.getZ()*lb.lineVector.getZ());

    vectorLength1 = sqrt(pow(la.lineVector.getX(), 2) +
                         pow(la.lineVector.getY(), 2));
    vectorLength2 = sqrt(pow(lb.lineVector.getX(), 2) +
                         pow(lb.lineVector.getY(), 2) +
                         pow(lb.lineVector.getZ(), 2));

    angleArcsin = scalar/(vectorLength1*vectorLength2);

    angleRad = asin(angleArcsin);

    cout << "Angle = " << angleRad << '\n';

    return angleRad;
}

bool Line::IsZSlopeOfTwoLinesEqual(const Line &la, const Line &lb) {

    if (la.linePoint1.getZ() == la.linePoint2.getZ() ==
        lb.linePoint1.getZ() == lb.linePoint2.getZ())
        return true;

    double offsetXZla = sqrt((la.linePoint2.getZ() - la.linePoint1.getZ())*2 +
                             (la.linePoint2.getX() - la.linePoint1.getX())*2);
    double offsetXZlb = sqrt((lb.linePoint2.getZ() - lb.linePoint1.getZ())*2 +
                             (lb.linePoint2.getX() - lb.linePoint1.getX())*2);
    double slopeXZla = (la.linePoint2.getY() - la.linePoint1.getY()) / offsetXZla;
    double slopeXZlb = (lb.linePoint2.getY() - lb.linePoint1.getY()) / offsetXZlb;

    slopeXZla = abs(slopeXZla);
    slopeXZlb = abs(slopeXZlb);

    if (slopeXZla == slopeXZlb)
        return true;
    else
        return false;
}

//Class-external methods:

ostream &operator<<(ostream &out, const Line &l) {
    out << "Line: " << l.getLinePoint1() << "; " <<
        l.getLinePoint2() << '\n';
    return out;
}

bool operator+(const Point& p1, const Line &lb) {

    bool ckr = false;

    double ab = sqrt((lb.linePoint2.getX()-lb.linePoint1.getX())*
                        (lb.linePoint2.getX()-lb.linePoint1.getX())+
                        (lb.linePoint2.getY()-lb.linePoint1.getY())*
                        (lb.linePoint2.getY()-lb.linePoint1.getY())+
                        (lb.linePoint2.getZ()-lb.linePoint1.getZ())*
                        (lb.linePoint2.getZ()-lb.linePoint1.getZ()));

    double ap = sqrt((p1.getX()-lb.linePoint1.getX())*
                        (p1.getX()-lb.linePoint1.getX())+
                        (p1.getY()-lb.linePoint1.getY())*
                        (p1.getY()-lb.linePoint1.getY())+
                        (p1.getZ()-lb.linePoint1.getZ())*
                        (p1.getZ()-lb.linePoint1.getZ()));

    double pb = sqrt((lb.linePoint2.getX()-p1.getX())*
                        (lb.linePoint2.getX()-p1.getX())+
                        (lb.linePoint2.getY()-p1.getY())*
                        (lb.linePoint2.getY()-p1.getY())+
                        (lb.linePoint2.getZ()-p1.getZ())*
                        (lb.linePoint2.getZ()-p1.getZ()));

    if(ab == ap + pb)
        return true;

    return ckr;
}

bool operator||(const Line &la, const Line &lb) {

    double slopeLA = (la.linePoint2.getY()-la.linePoint1.getY()) /
                     (la.linePoint2.getX()-la.linePoint1.getX());

    double slopeLB = (lb.linePoint2.getY()-lb.linePoint1.getY()) / (
            lb.linePoint2.getX()-lb.linePoint1.getX());

    bool isZEqual = Line::IsZSlopeOfTwoLinesEqual(la, lb);

    if ((slopeLA == slopeLB) && (isZEqual)) {
        return true;
    } else {
        return false;
    }
}

int Line::findLineOrientation(Point p, Point q, Point r) {

    //Method used in redefining operator && and !=

    double ckr = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
                 (q.getX() - p.getX()) * (r.getY()- q.getY());

    if (ckr == 0)
        return 0;

    return (ckr > 0)? 1: 2;
}

bool Line::checkSegment(Point p, Point q, Point r) {

    //Method used in redefining operator && and != for special cases

    if (q.getX() <= max(p.getX(), r.getX()) && q.getX() >= min(p.getX(), r.getX()) &&
        q.getY() <= max(p.getY(), r.getY()) && q.getY() >= min(p.getY(), r.getY()))
        return true;

    return false;
}

bool operator&&(const Line &la, const Line &lb) {

    int orn1 = Line::findLineOrientation(la.linePoint1, la.linePoint2, lb.linePoint1);
    int orn2 = Line::findLineOrientation(la.linePoint1, la.linePoint2, lb.linePoint2);
    int orn3 = Line::findLineOrientation(lb.linePoint1, lb.linePoint2, la.linePoint1);
    int orn4 = Line::findLineOrientation(lb.linePoint1, lb.linePoint2, la.linePoint2);
    bool isZSlope = Line::IsZSlopeOfTwoLinesEqual(la, lb);

    if ((orn1 != orn2 && orn3 != orn4) && isZSlope) {
        return true;
    }

    if (orn1 == 0 && Line::checkSegment(la.linePoint1, la.linePoint2, lb.linePoint1) && isZSlope) {
        return true;
    }

    if (orn2 == 0 && Line::checkSegment(la.linePoint1, lb.linePoint2, la.linePoint2) && isZSlope) {
        return true;
    }

    if (orn3 == 0 && Line::checkSegment(lb.linePoint2, la.linePoint1, la.linePoint2) && isZSlope) {
        return true;
    }

    if (orn4 == 0 && Line::checkSegment(lb.linePoint1, la.linePoint2, lb.linePoint2) && isZSlope) {
        return true;
    }
    return false;

}

bool operator==(const Line &la, const Line &lb) {
    bool parallel;
    bool intersect;

    parallel = la||lb;
    intersect = la&&lb;

    if (parallel && intersect) {
        return true;
    }

    return false;
}

bool operator!=(const Line &la, const Line &lb) {

    int orn1 = Line::findLineOrientation(la.linePoint1, la.linePoint2, lb.linePoint1);
    int orn2 = Line::findLineOrientation(la.linePoint1, la.linePoint2, lb.linePoint2);
    int orn3 = Line::findLineOrientation(lb.linePoint1, lb.linePoint2, la.linePoint1);
    int orn4 = Line::findLineOrientation(lb.linePoint1, lb.linePoint2, la.linePoint2);
    bool isZSlope = Line::IsZSlopeOfTwoLinesEqual(la, lb);

    if ((orn1 != orn2 && orn3 != orn4) && (!isZSlope)) {
        return true;
    }

    if (orn1 == 0 && Line::checkSegment(la.linePoint1, la.linePoint2, lb.linePoint1) && (!isZSlope)) {
        return true;
    }

    if (orn2 == 0 && Line::checkSegment(la.linePoint1, lb.linePoint2, la.linePoint2) && (!isZSlope)) {
        return true;
    }

    if (orn3 == 0 && Line::checkSegment(lb.linePoint2, la.linePoint1, la.linePoint2) && (!isZSlope)) {
        return true;
    }

    if (orn4 == 0 && Line::checkSegment(lb.linePoint1, la.linePoint2, lb.linePoint2) && (!isZSlope)) {
        return true;
    }

    return false;
}

bool operator|(const Line &la, const Line &lb) {

    double tmp1, tmp2;

    if ((la.linePoint2.getX() - la.linePoint1.getX() == 0) &&
        (lb.linePoint2.getX() - lb.linePoint1.getX() == 0)) {
        return false;

    } else if (la.linePoint2.getX() - la.linePoint1.getX() == 0) {

        tmp2 = (lb.linePoint2.getY() - lb.linePoint1.getY()) /
               (lb.linePoint2.getX() - lb.linePoint1.getX());

        if (tmp2 == 0) {
            return true;
        }
        else {
            return false;
        }
    } else if (lb.linePoint2.getX() - lb.linePoint1.getX() == 0) {

        tmp1 = (la.linePoint2.getY() - la.linePoint1.getY()) /
               (la.linePoint2.getX() - la.linePoint1.getX());

        if (tmp1 == 0) {
            return true;
        }
        else {
            return false;
        }
    } else {
        tmp1 = (la.linePoint2.getY() - la.linePoint1.getY()) /
               (la.linePoint2.getX() - la.linePoint1.getX());

        tmp2 = (lb.linePoint2.getY() - lb.linePoint1.getY()) /
               (lb.linePoint2.getX() - lb.linePoint1.getX());

        if (tmp1 * tmp2 == -1) {
            return true;
        }
        else {
            return false;
        }
    }
}



