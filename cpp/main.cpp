#include <iostream>

#include "../include/person.h"
#include "../include/student.h"
#include "../include/teacher.h"
#include "../include/exam.h"
#include "../include/gradebook.h"
#include "../include/menu.h"

constexpr const std::string_view fileName = "data.txt";

int main() {
	using namespace menu;

	setlocale(0, "");

	Gradebook gradebook;
	std::unique_ptr<Person> teacher(new Teacher);
	std::unique_ptr<Person> student(new Student);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Menu menu(hConsole);

	menu.AddItem("Show gradebook", [&gradebook] { gradebook.print(); });
	menu.AddItem("Add exam to gradebook", [&gradebook] { 
		try {
			Exam exam;
			exam.fill();
			gradebook.push_back(std::move(exam));
		}
		catch (std::exception& exeption) {
			std::cout << exeption.what() << std::endl;
		}
		});
	menu.AddItem("Delete exam from gradebook", [&gradebook] {
		try {
			gradebook.pop_back();
		}
		catch (std::exception& exeption) {
			std::cout << exeption.what() << std::endl;
		}
		});

	menu.AddItem("Show teacher", [&teacher] { teacher->print(); });
	menu.AddItem("Show student", [&student] { student->print(); });

	menu.AddItem("Create teacher", [&teacher] { 
		try {
			teacher->fill();		
		}
		catch (std::exception& exeption) {
			std::cout << exeption.what() << std::endl;
		}
	});
	menu.AddItem("Create student", [&student] {
		try {
			student->fill();
		}
		catch (std::exception& exeption) {
			std::cout << exeption.what() << std::endl;
	}});

	menu.AddItem("Save gradebook", [&gradebook] {
		try {
			gradebook.save(fileName);
		}
		catch (std::exception& exeption) {
			std::cout << exeption.what() << std::endl;
	}});
	menu.AddItem("Load gradebook", [&gradebook] {
		try 
		{ 
			gradebook.clean(); 
			gradebook.load(fileName); 
		}
		catch (std::exception& exeption) {
			std::cout << exeption.what() << std::endl;
	}});

	menu.GetInput();

	return 0;
}