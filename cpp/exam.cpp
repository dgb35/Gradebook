#include "../include/exam.h"
#include <sstream>
#include <ctime>
#include <iostream>
#include <iomanip>

Exam::Exam() :
	Teacher(),
	Student(),
	subjectName{ "Unknown" },
	hoursNumber{ 1 },
	mark{}
{
	// setting default value for date
	time_t now = time(0);;
	gmtime_s(&date, &now);;
}

Exam::Exam(std::string_view teacherSecondName, std::string_view post,
	std::string_view studentSecondName, uint group, std::string_view subjectName, 
	uint hoursNumber, std::tm date, uint mark):
	Teacher(teacherSecondName, post),
	Student(studentSecondName, group),
	subjectName{ subjectName },
	hoursNumber{ hoursNumber },
	date{ date },
	mark{ mark }
{
}

std::string_view Exam::getSubjectName() const
{
	return subjectName;
}

void Exam::setSubjectName(std::string_view subjectName)
{
	if (subjectName.size() > 0)
		this->subjectName = subjectName;
	else
		throw std::exception{ std::runtime_error{ "Can't set an empty string"} };
}

unsigned int Exam::getHoursNumber() const noexcept
{
	return hoursNumber;
}

void Exam::setHoursNumber(uint hoursNumber)
{
	if (hoursNumber > 0u)
		this->hoursNumber = hoursNumber;
	else
		throw std::exception{ std::runtime_error{ "Can't set 0 hours for a subject"} };
}

std::tm Exam::getDate() const noexcept
{
	return date;
}

void Exam::setDate(std::tm date)
{
	this->date = date;
}

unsigned int Exam::getMark() const noexcept
{
	return mark;
}

void Exam::setMark(uint mark)
{
	this->mark = mark;
}

std::string Exam::toString() const 
{
	std::stringstream ss;
	ss << "teacherSecondName: " << Teacher::secondName << std::endl
		<< "post: " << post << std::endl
		<< "studentSecondName: " << Student::secondName << std::endl
		<< "group: " << Student::group << std::endl
		<< "subjectName: " << subjectName << std::endl
		<< "hoursNumber: " << hoursNumber << std::endl
		<< "date: " << date.tm_hour << ':' << date.tm_min << ' ' << date.tm_mday << '.' << date.tm_mon + 1 << '.' << 1900 + date.tm_year << std::endl
		<< "mark: " << mark << std::endl << std::endl;
	return ss.str();
}

void Exam::print() const
{
	std::cout << "Teacher" << std::endl 
		<< "Second name: " << Teacher::secondName << std::endl
		<< "Post: " << Teacher::post << std::endl
		<< std::endl

		<< "Student" << std::endl
		<< "Second name: " << Student::secondName << std::endl
		<< "Group: " << Student::group << std::endl 
		<< std::endl

		<< "Subject" << std::endl
		<< "Subject name: " << subjectName << std::endl
		<< "Hours number: " << hoursNumber << std::endl 
		<< std::endl

		<< "Exam " << std::endl
		<< "Date: " << date.tm_hour << ':' << date.tm_min << ' ' << date.tm_mday << '.' << date.tm_mon + 1 << '.' << 1900 + date.tm_year << std::endl
		<< "Mark: " << mark << std::endl 
		<< std::endl;
}

void Exam::fill()
{
	std::cout << "Please enter exam data" << std::endl << std::endl;

	Teacher::fill();
	std::cout << std::endl;

	Student::fill();
	std::cout << std::endl;

	std::cout << "Subject data:" << std::endl;
	std::cout << "Subject name: "; 
	while (true) {
		std::cin >> subjectName;
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

	std::cout << "Hours number: ";
	while (true) {
		std::cin >> hoursNumber;
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
			std::cout << exeption.what();
		}
	}

	std::cout << std::endl << "Exam: " << std::endl;
	std::cout << "Date(format: 10:45-9.05.2021): ";
	std::string str;
	std::cin.ignore(32767, '\n');
	std::cin >> str;
	std::stringstream ss(str);
	ss >> std::get_time(&date, "%H:%M-%d.%m.%y");

//	if (ss.fail() or std::cin.fail())
//		throw std::exception{ std::runtime_error{"Data parse failed. Wrong data."} };

	std::cout << "Mark: "; 
	while (true) {
		std::cin >> mark;
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
			std::cout << exeption.what();
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Exam& other)
{
	os << other.Teacher::secondName << std::endl
		<< other.Teacher::post << std::endl
		<< other.Student::secondName << std::endl
		<< other.Student::group << std::endl
		<< other.subjectName << std::endl 
		<< other.hoursNumber << std::endl 
		<< other.date.tm_hour << std::endl
		<< other.date.tm_min << std::endl
		<< other.date.tm_mday << std::endl
		<< other.date.tm_mon << std::endl
		<< other.date.tm_year << std::endl
		<< other.mark << std::endl << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Exam& other)
{
	is >> other.Teacher::secondName
		>> other.Teacher::post
		>> other.Student::secondName 
		>> other.Student::group
		>> other.subjectName
		>> other.hoursNumber
		>> other.date.tm_hour
		>> other.date.tm_min
		>> other.date.tm_mday
		>> other.date.tm_mon
		>> other.date.tm_year 
		>> other.mark;
	return is;
}
