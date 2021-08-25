#include "../include/gradebook.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

Gradebook::Gradebook() : exams{ nullptr }, size_{} {}

Gradebook::Gradebook(std::initializer_list<Exam> list) :
	size_{ list.size() }
{
	// allocating buffer
	exams = new Exam[size_];

	// copying elements
	size_t i = 0u;
	for (auto it = list.begin(); it != list.end() && i < list.size(); ++it, ++i)
		exams[i] = *it;
}

Gradebook::Gradebook(const Gradebook& other) : 
	size_{ other.size_ }
{
	// allocating buffer
	exams = new Exam[size_];

	// copying elements
	size_t i = 0;
	for (auto it = other.begin(); it != other.end(); ++it, ++i)
		exams[i] = *it;
}

Gradebook::Gradebook(Gradebook&& other) noexcept
{
	// allocating buffer
	exams = new Exam[size_];

	// copying elements
	size_t i = 0;
	for (auto it = other.begin(); it != other.end(); ++it, ++i)
		exams[i] = *it;
}

Gradebook::~Gradebook()
{
	if (exams != nullptr)
		delete[] exams;
}

Gradebook& Gradebook::operator=(const Gradebook& other)
{
	// deleting previous container
	if (exams != nullptr) { delete[] exams; exams = nullptr; }

	// copying elements
	size_ = other.size_;
	exams = new Exam[size_];
	size_t i = 0;
	for (auto it = other.begin(); it != other.end(); ++it, ++i)
		exams[i] = *it;

	return *this;
}

Gradebook& Gradebook::operator=(Gradebook&& other) noexcept
{
	// deleting previous container
	if (exams != nullptr) { delete[] exams; exams = nullptr; }

	// copying elements
	size_ = other.size_;
	exams = new Exam[size_];
	size_t i = 0;
	for (auto it = other.begin(); it != other.end(); ++it, ++i)
		exams[i] = *it;

	return *this;
}

size_t Gradebook::size() const noexcept
{
	return size_;
}

void Gradebook::push_back(const Exam& exam)
{
	// resizing container
	Exam* newExams = new Exam[size_ + 1];

	// copying elements
	if (!empty()) {
		int i = 0;
		for (auto it = begin(); it != end(); ++it, ++i)
			newExams[i] = *it;
	}
	newExams[size_] = exam;

	// deleting previous container
	if (exams != nullptr) { delete[] exams; exams = nullptr; }
	exams = newExams;
	++size_;
}

void Gradebook::push_back(Exam&& exam)
{
	// resizing container
	Exam* newExams = new Exam[size_ + 1];

	// copying elements
	if (!empty()) {
		int i = 0;
		for (auto it = begin(); it != end(); ++it, ++i)
			newExams[i] = *it;
	}
	newExams[size_] = exam;

	// deleting previous container
	if (exams != nullptr) { delete[] exams; exams = nullptr; }
	exams = newExams;
	++size_;
}

void Gradebook::pop_back()
{
	// if container is already empty, throw exeption
	if (empty())
		throw std::exception{ std::runtime_error{ "Container is already empty" } };

	// resizing container
	--size_;
	Exam* newExams = new Exam[size_];
	
	// copying elements
	size_t i = 0;
	for (auto it = begin(); i < size_; ++it, ++i)
		newExams[i] = *it;

	// deleting previous container
	if (exams != nullptr) { delete[] exams; exams = nullptr; }

	exams = newExams;

	std::cout << "Exam has been successfully deleted" << std::endl;
}

bool Gradebook::empty() const noexcept
{
	return !size_;
}

void Gradebook::print() const
{
	if (empty()) { std::cout << "Gradebook is empty" << std::endl; return; }
	for (auto i = begin(); i != end(); ++i)
	{
		(*i).print();
		std::cout << "-------------------------------------------------" << std::endl;
	}

}

void Gradebook::save(std::string_view fileName)
{
	// opening file
	std::ofstream file(fileName.data(), std::ios_base::out);

	// writing data to file
	file << size_ << std::endl;
	for (auto i = begin(); i != end(); ++i)
		file << *i;
	file.close();

	if (file.good())
		std::cout << "Gradebook has been successfully saved" << std::endl;
	else
		throw std::exception{ std::runtime_error{"Can't save gradebook"} };
}

void Gradebook::load(std::string_view fileName)
{
	// opening file
	std::ifstream file(fileName.data(), std::ios_base::in);

	// reading data from file
	Exam exam;
	size_t size;
	file >> size;
	for (size_t i = 0; !file.eof() && i < size; ++i)
	{
		file >> exam;
		push_back(std::move(exam));
	}
	file.close();

	if(file.good())
		std::cout << "Gradebook has been successfully loaded" << std::endl;
	else
		throw std::exception{ std::runtime_error{"Can't load gradebook, file is corrupted"} };
}

void Gradebook::clean()
{
	if (exams != nullptr) { delete[] exams; exams = nullptr; }
	size_ = 0;
}
