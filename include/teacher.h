#pragma once
#include <string>

#include "person.h"

class Teacher : public virtual Person
{
public:
	using uint = unsigned int;

	// constructors 
	Teacher();
	Teacher(std::string_view secondName, std::string_view post);
	Teacher(const Teacher&) = default;
	Teacher(Teacher&&) = default;

	// = operators
	Teacher& operator=(const Teacher&) = default;
	Teacher& operator=(Teacher&&) = default;

	// i/o operators
	friend std::ostream& operator<<(std::ostream& os, const Teacher& other);
	friend std::istream& operator>>(std::istream& is, Teacher& other);

	// default destructor
	~Teacher() = default;

public:
	// setters & getters for fields
	[[nodiscard]] std::string_view getPost() const;
	void setPost(std::string_view post);

	// virtual functions
	virtual std::string toString() const override;
	virtual void print() const override;
	virtual void fill() override;

protected:
	std::string secondName;
	std::string post;
};

