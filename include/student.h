#pragma once
#include <string>

#include "person.h"

class Student : public virtual Person
{
public:
	using uint = unsigned int;

	// constructors 
	Student();
	Student(std::string_view secondName, uint group);
	Student(const Student&) = default;
	Student(Student&&) = default;

	// = operators
	Student& operator=(const Student&) = default;
	Student& operator=(Student&&) = default;

	// i/o operators
	friend std::ostream& operator<<(std::ostream& os, const Student& other);
	friend std::istream& operator>>(std::istream& is, Student& other);

	// default destructor
	~Student() = default;

public:
	// setters & getters for fields
	[[nodiscard]] uint getGroup() const noexcept;
	void setGroup(uint group);

	// virtual functions
	virtual std::string toString() const override;
	virtual void print() const override;
	virtual void fill() override;

protected:
	std::string secondName;
	uint group;
};

