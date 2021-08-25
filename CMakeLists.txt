cmake_minimum_required(VERSION 3.6)
project(gradebook CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FILES
        cpp/exam.cpp
        cpp/gradebook.cpp
        cpp/menu/menu.cpp
        cpp/person.cpp
        cpp/student.cpp
        cpp/teacher.cpp
        cpp/main.cpp

        include/exam.h
        include/gradebook.h
        include/menu/menu.h
        include/person.h
        include/student.h
        include/teacher.h
        )

include_directories("include")

add_executable(gradebook ${FILES})