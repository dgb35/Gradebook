#include "student.h"
#include <sstream>
#include <iostream>

Student::Student() :
	secondName{ "Unknown" },
	group{}
{
}

Student::Student(std::string_view secondName, uint group) :
	secondName{ secondName },
	group{ group }
{
}

unsigned int Student::getGroup() const noexcept
{
	return group;
}

void Student::setGroup(uint group)
{
	this->group = group;
}

std::string Student::toString() const
{
	std::stringstream ss;
	ss << "secondName: " << secondName << std::endl
		<< "group: " << group << std::endl << std::endl;
	return ss.str();
}

void Student::print() const
{
	std::cout << "Second name: " << secondName << std::endl
		<< "Group: " << group << std::endl;
}

void Student::fill()
{
	std::cout << "Please enter student's data: " << std::endl;
	std::cout << "Second name: "; std::cin.ignore(32767, '\n'); 
	while (true) {
		std::cin >> secondName;
		try {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				throw std::exception{ std::runtime_error{"Wrong input data. Try again"} };
			}
			else {
				break;
			}
		}
		catch (const std::exception& exeption) {
			std::cout << exeption.what() << std::endl;
		}
	}

	std::cout << "Group: ";
	while (true) {
		std::cin >> group;
		try {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(3217, '\n');
				throw std::exception{ std::runtime_error{"Wrong input data. Try again"} };
			}
			else {
				break;
			}
		}
		catch (const std::exception& exeption) {
			std::cout << exeption.what();
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Student& other)
{
	os << other.secondName << std::endl
		<< other.group << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Student& other)
{
	is >> other.secondName >> other.group;
	return is;
}
