#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <limits>
#include <fstream>
#include <cstdlib>

#include "Element.h"
#include "Line.h"
#include "Point.h"
#include "Segment.h"
#include "Vector.h"
#include "Triangle.h"
#include "Tetrahedron.h"

using namespace std;

//General methods:
void mainMenu();                    //Main menu;
int chooseStream();                 //Choose the input stream;
//Choose the geometrical object to work with;
char chooseGeoObject(int opt, std::fstream& userOutput, std::fstream& textTmp, const char* inputArr);


//Object specific methods:

//For class Point:
void menuPoint(int stream, std::fstream& userOutput, std::fstream& textTmp, const char* inputArr);         //Point submenu;
Point createNewPoint(const char* inputArr);             //UI for new Point;

//For class Vector:
void menuVector(int stream, std::fstream& userOutput, std::fstream& textTmp, const char* inputArr);        //Vector submenu;
Vector createNewVector(const char* inputArr);           //UI for new Vector;

//For class Line:
void menuLine(int stream, std::fstream& userOutput, std::fstream& textTmp, const char* inputArr);        //Line submenu;
Line createNewLine(const char* inputArr);                 //UI for new Line;

//For class Segment
void menuSegment(int stream, std::fstream& userOutput, std::fstream& textTmp, const char* inputArr);     //Segment submenu;
Segment createNewSegment(const char* inputArr);         //UI for new Segment;

void menuTriangle(int stream, std::fstream& userOutput, std::fstream& textTmp, const char* inputArr);    //Triangle submenu;
Triangle createNewTriangle(const char* inputArr);		//UI for new Triangle

void menuTetrahedron(int stream, std::fstream& userOutput, std::fstream& textTmp, const char* inputArr);     //Tetrahedron submenu;
Tetrahedron createNewTetrahedron(const char* inputArr);         //UI for new Tetrahedron;
#endif //MENU_H