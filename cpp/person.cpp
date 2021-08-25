#include "person.h"

Person::Person() :
	secondName{ "Unknown" }
{
}

Person::Person(std::string_view secondName):
	secondName{ secondName }
{
}

Person::~Person()
{
}

std::string_view Person::getSecondName() const
{
	return secondName;
}

void Person::setSecondName(std::string_view secondName)
{
	if (secondName.size() > 0)
		this->secondName = secondName;
}