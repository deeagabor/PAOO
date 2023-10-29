#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    Student(const char* n, const float g1, const float g2, const float g3); // Constructor
    Student(const Student& other); // Copy Constructor
    Student(Student&& other); // Move Constructor
    ~Student(); // Destructor

    float calculateMedia();
    char* getName();

private:
    char* name;
    float grade1;
    float grade2;
    float grade3;
};

#endif
