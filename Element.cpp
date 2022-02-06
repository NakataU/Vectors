#include <iostream>
#include "Element.h"

Element::Element() : type(new char[8]{ "Element" }) {}

Element::Element(const char* type) : type(new char[strlen(type) + 1])
{
	strcpy_s(this->type, strlen(type) + 1, type);
}

Element::Element(const Element& rhs) : type(new char[strlen(rhs.type) + 1])
{
	strcpy_s(this->type, strlen(rhs.type) + 1, rhs.type);
}

Element& Element::operator=(const Element& rhs)
{
	if (&rhs != this)
	{
		if (type != nullptr)
		{
			delete[] type;
		}

		type = new char[strlen(rhs.type) + 1];
		strcpy_s(type, strlen(rhs.type) + 1, rhs.type);
	}

	return *this;
}

Element::~Element()
{
	if (type != nullptr)
	{
		delete[] type;
	}
}

char* Element::getType() const
{
	return type;
}

void Element::setType(const char* type)
{
	if (this->type != nullptr)
	{
		delete[] this->type;
	}

	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}

//Friend methods
std::ostream& operator<<(std::ostream& out, const Element& rhs) {
	out << "Element: " << rhs.getType();
	return out;
}