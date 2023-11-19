#include <iostream>

#include "highschoolStudent.h"

using namespace Campus;


// Constructor
HighschoolStudent::HighschoolStudent(const char* n, const char* hi, const float g1, const float g2) {
    name = new char[strlen(n) + 1];
    highschoolName = new char[strlen(hi) + 1];

    strcpy(name, n);
    strcpy(highschoolName, hi);

    grade1 = g1;
    grade2 = g2;

    std::cout << "Constructor has been called for " << name << std::endl;
}

// Deconstructor
HighschoolStudent::~HighschoolStudent() {
    std::cout << "Highschool student " << name <<" has been destructed!" << std::endl;
    delete[] name;
    delete[] highschoolName;
}

float HighschoolStudent::calculateMedia() {
    return (grade1 + grade2) / 2.0;
}

char* HighschoolStudent::getName() const{
    return name;
}

float HighschoolStudent::calculateScholarship() {
    return calculateMedia() * 200;
}