#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>

class Element
{
public:
	/*
		The Big Five rule
	*/
	//Default constructor
	Element();
	//Parameter constructor
	Element(const char*);
	//Copy constructor
	Element(const Element&);
	//Overload operator =
	Element& operator=(const Element&);
	//Pure virtual destructor, because Element is an abstract class
	virtual ~Element() = 0;

	//Getters, Setters
	char* getType() const;
	void setType(const char*);
private:
	//Type of element
	char* type;

	//Friend methods
	friend std::ostream& operator<<(std::ostream&, const Element&);
};

std::ostream& operator<<(std::ostream&, const Element&);

#endif