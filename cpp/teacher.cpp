#include "teacher.h"
#include <sstream>
#include <iostream>

Teacher::Teacher() :
	secondName{ "Unknown" },
	post{ "Unknown" }
{
}

Teacher::Teacher(std::string_view secondName, std::string_view post):
	secondName{ secondName },
	post{ post }
{
}

std::string_view Teacher::getPost() const
{
	return post;
}

void Teacher::setPost(std::string_view post)
{
	if (post.size() > 0)
		this->post = post;
}

std::string Teacher::toString() const
{
	std::stringstream ss;
	ss << "secondName: " << secondName << std::endl
		<< "post: " << post << std::endl << std::endl;
	return ss.str();
}

void Teacher::print() const
{
	std::cout << "Second name: " << secondName << std::endl
		<< "Post: " << post << std::endl;
}

void Teacher::fill()
{
	std::cout << "Please enter teacher's data: " << std::endl;
	std::cout << "Second name: "; 	
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
			std::cout << exeption.what();
		}
	}

	std::cout << "Post: "; 
	while (true) {
		std::cin >> post;
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
}

std::ostream& operator<<(std::ostream& os, const Teacher& other)
{
	os << other.secondName << std::endl
		<< other.post << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Teacher& other)
{
	is >> other.secondName >> other.post;
	return is;
}
