#pragma once
#include "teacher.h"
#include "student.h"

class Exam: 
	public Teacher, 
	public Student
{
public:
	using uint = unsigned int;

	Exam();
	Exam(std::string_view teatherSecondName, 
		std::string_view post, 
		std::string_view studentSecondName, 
		uint group, 
		std::string_view subjectName, 
		uint hoursNumber, 
		std::tm date, 
		uint mark);

	// default constructors
	Exam(const Exam&) = default;
	Exam(Exam&&) = default;

	// default assign operators
	Exam& operator=(const Exam&) = default;
	Exam& operator=(Exam&&) = default;

	// i/o operators
	friend std::ostream& operator<<(std::ostream& os, const Exam& other);
	friend std::istream& operator>>(std::istream& is, Exam& other);

	// default destructor
	~Exam() = default;

public:
	// setters & getters for fields
	[[nodiscard]] std::string_view getSubjectName() const;
	void setSubjectName(std::string_view subjectName);

	[[nodiscard]] uint getHoursNumber() const noexcept;
	void setHoursNumber(uint subjectName);

	[[nodiscard]] std::tm getDate() const noexcept;
	void setDate(std::tm date);

	[[nodiscard]] uint getMark() const noexcept;
	void setMark(uint mark);

	// virtual functions
	virtual std::string toString() const override;
	virtual void print() const override;
	virtual void fill() override;

protected:
	std::string subjectName;
	uint hoursNumber;
	std::tm date;
	uint mark;
};

