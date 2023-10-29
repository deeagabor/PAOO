#include "Student.h"
#include <iostream>

// Constructor
Student::Student(const char* n, const float g1, const float g2, const float g3) {
    name = new char[strlen(n) + 1]; 
    strcpy(name, n);
    grade1 = g1;
    grade2 = g2;
    grade3 = g3;

    std::cout << "Constructor has been called for " << name << std::endl;
}

// Copy Constructor
Student::Student(const Student& other) {
    name = new char[strlen(other.name) + 1]; 
    strcpy(name, other.name);
    grade1 = other.grade1;
    grade2 = other.grade2;
    grade3 = other.grade3;

    std::cout << "Copy constructor has been called for " << name << std::endl;
}

// Move Constructor
Student::Student(Student&& other) {
    name = other.name; 
    grade1 = other.grade1;
    grade2 = other.grade2;
    grade3 = other.grade3;

    other.name = nullptr;
    other.grade1 = 0.0;
    other.grade2 = 0.0;
    other.grade3 = 0.0;

    std::cout << "Move constructor has been called for " << name << std::endl;
}

// Deconstructor
Student::~Student() {
    delete[] name;
    std::cout << "Student has been destructed!" << std::endl;
}

float Student::calculateMedia() {
    return (grade1 + grade2 + grade3) / 3.0;
}

char* Student::getName() {
    return name;
}
