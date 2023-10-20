#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    Student(const std::string& name);

    void setGrades(double grade1, double grade2, double grade3);
    double calculateAverage() const;
    std::string getName() const;

private:
    std::string name;
    double grade1;
    double grade2;
    double grade3;
};

#endif
