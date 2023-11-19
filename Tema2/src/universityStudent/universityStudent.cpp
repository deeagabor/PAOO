#include <iostream>

#include "universityStudent.h"

using namespace Campus;


// Constructor
UniversityStudent::UniversityStudent(const char* n, const char* un, const float g1, const float g2, const float g3) {
    name = new char[strlen(n) + 1];
    universityName = new char[strlen(un) + 1];

    strcpy(name, n);
    strcpy(universityName, un);

    grade1 = g1;
    grade2 = g2;
    grade3 = g3;

    std::cout << "Constructor has been called for " << name << std::endl;
}

// Copy Constructor
UniversityStudent::UniversityStudent(const UniversityStudent& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    universityName = new char[strlen(other.universityName) + 1];
    strcpy(universityName, other.universityName);

    grade1 = other.grade1;
    grade2 = other.grade2;
    grade3 = other.grade3;

    std::cout << "Copy constructor has been called for " << name << std::endl;
}

// Move Constructor
UniversityStudent::UniversityStudent(UniversityStudent&& other) {
    name = other.name; 
    universityName = other.universityName; 

    grade1 = other.grade1;
    grade2 = other.grade2;
    grade3 = other.grade3;

    other.name = nullptr;
    other.universityName = nullptr;

    other.grade1 = 0.0;
    other.grade2 = 0.0;
    other.grade3 = 0.0;

    std::cout << "Move constructor has been called for " << name << std::endl;
}

// Deconstructor
UniversityStudent::~UniversityStudent() {
    std::cout << "University student " << name <<" has been destructed!" << std::endl;
    delete[] name;
    delete[] universityName;
}

float UniversityStudent::calculateMedia() {
    return (grade1 + grade2 + grade3) / 3.0;
}

char* UniversityStudent::getName() const{
    return name;
}




float UniversityStudent::calculateScholarship() {
    return calculateMedia() * 1000; 
}

void UniversityStudent::attendClasses() const{
    std::cout << getName() << " is attending classes at " << universityName << "." << std::endl;
}




UniversityStudent& UniversityStudent::operator= (const UniversityStudent &other) {
    if (this != &other) {
        delete[] name;
        delete[] universityName;

        name = new char[strlen(other.name) + 1];
        universityName = new char[strlen(other.universityName) + 1];

        strcpy(name, other.name);
        strcpy(universityName, other.universityName);

        grade1 = other.grade1;
        grade2 = other.grade2;
        grade3 = other.grade3;

        std::cout << "Copy assignment has been called for " << name << std::endl;
    }

    return *this;
}

UniversityStudent& UniversityStudent::operator= (UniversityStudent &&other) {
    if (this != &other) {
        delete[] this->name;
        delete[] this->universityName;
        
        this->name = other.name; 
        this->universityName = other.universityName; 

        this->grade1 = other.grade1;
        this->grade2 = other.grade2;
        this->grade3 = other.grade3;

        other.name = nullptr;
        other.universityName = nullptr;

        other.grade1 = 0.0;
        other.grade2 = 0.0;
        other.grade3 = 0.0;

        std::cout << "Move assignment has been called for " << name << std::endl;
    }

    return *this;
}