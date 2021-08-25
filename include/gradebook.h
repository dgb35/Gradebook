#pragma once

#include <iterator>
#include "exam.h"

class Gradebook
{
public:
	// constructors 
	Gradebook();
	Gradebook(std::initializer_list<Exam> list);
	Gradebook(const Gradebook&);
	Gradebook(Gradebook&&) noexcept;

	// = operators
	Gradebook& operator=(const Gradebook&);
	Gradebook& operator=(Gradebook&&) noexcept;

	// virtual destructor
	virtual ~Gradebook();

public:
	// iterator class
	class Iterator
	{
	public:
		// constructors 
		explicit Iterator(Exam* p) : p(p) {}
		Iterator(const Iterator& it) : p(it.p) {}

	public:
		// suffix & postfix ++ operators
		Iterator& operator++() { ++p; return *this; }
		Iterator operator++(int) { Iterator returnValue = *this; ++(*this); return returnValue; }

		// suffix & postfix -- operators
		Iterator& operator--() { --p; return *this; }
		Iterator operator--(int) { Iterator returnValue = *this; --(*this); return returnValue; }

		// equality operators
		bool operator==(const Iterator& other) const { return p == other.p; }
		bool operator!=(const Iterator& other) const { return p != other.p; }

		// dereference operator
		Exam& operator*() { return *p; }

	protected:
		// current element
		Exam* p;
	};

public:
	// returns size
	[[nodiscard]] size_t size() const noexcept;

	// adds an element to the container
	void push_back(const Exam&);
	void push_back(Exam&&);

	// deletes an element from the container
	void pop_back();

	// retuns iterators reffered to beginning and end of the container
	Iterator begin() const noexcept { return Iterator(exams); }
	Iterator end() const noexcept { return Iterator(exams + size_); }

	// saves/loads container to/from file 
	void save(std::string_view fileName);
	void load(std::string_view fileName);

	// cleans the container
	void clean();
	// returns true if container is empty, otherwise returns false
	bool empty() const noexcept;

	//prints the container to the console
	void print() const;

protected:
	// pointer to container data
	Exam* exams;
	// container size
	size_t size_;
};

