#pragma once
#include <string>
#include <string_view>

class Person abstract
{
public:
	using uint = unsigned int;

	// constructors 
	Person();
	Person(std::string_view secondName);
	Person(const Person&) = default;
	Person(Person&&) = default;

	// = operators
	Person& operator=(const Person&) = default;
	Person& operator=(Person&&) = default;

	// virtual destructor
	virtual ~Person();

public:
	// setters & getters for fields
	[[nodiscard]] std::string_view getSecondName() const;
	void setSecondName(std::string_view secondName);

	// pure virtual functions
	virtual void print() const = 0;
	virtual void fill() = 0;
	virtual std::string toString() const = 0;

protected:
	std::string secondName;
};

