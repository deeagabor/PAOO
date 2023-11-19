#include <iostream>

#include "acStudent.h"

using namespace Campus;

AcStudent::AcStudent(const char* n, const char* un, float g1, const float g2, const float g3) : UniversityStudent(n, un, g1, g2, g3){}

AcStudent::~AcStudent() {
    std::cout << "Ac student " << name <<" has been destructed!" << std::endl;
}

void AcStudent::attendClasses() const {
    std::cout << getName() << " is attending classes at " << universityName << ", Computer Science Faculty." << std::endl;
}

AcStudent& AcStudent::operator= (const AcStudent &other) {
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

AcStudent& AcStudent::operator= (AcStudent &&other) {
    if (this != &other) {
        if (name != nullptr) {
            delete[] name;
        }
        if (universityName != nullptr) {
            delete[] universityName;
        }
        
        name = other.name; 
        universityName = other.universityName; 

        grade1 = other.grade1;
        grade2 = other.grade2;
        grade3 = other.grade3;

        universityName = nullptr;
        name = nullptr;

        other.grade1 = 0.0;
        other.grade2 = 0.0;
        other.grade3 = 0.0;

        std::cout << "Move assignment has been called for " << name << std::endl;
    }

    return *this;
}