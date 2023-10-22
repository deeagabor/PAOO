#include "Student.h"

Student::Student(std::string n, float g1, float g2, float g3) : name(n), grade1(g1), grade2(g2), grade3(g3) {}

float Student::calculateMedia() const{
    return (grade1 + grade2 + grade3) / 3.0;
}

std::string Student::getName() const{
    return name;
}
