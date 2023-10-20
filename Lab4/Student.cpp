#include "Student.h"

Student::Student(const std::string& name) : name(name), grade1(0), grade2(0), grade3(0) {}

void Student::setGrades(double grade1, double grade2, double grade3) {
    this->grade1 = grade1;
    this->grade2 = grade2;
    this->grade3 = grade3;
}

double Student::calculateAverage() const {
    return (grade1 + grade2 + grade3) / 3.0;
}

std::string Student::getName() const {
    return name;
}
