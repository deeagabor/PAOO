#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    Student(const std::string n, float g1, float g2, float g3);

    float calculateMedia() const;
    std::string getName() const;

private:
    std::string name;
    double grade1;
    double grade2;
    double grade3;
};

#endif
