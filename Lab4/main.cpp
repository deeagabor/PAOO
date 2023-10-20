#include "Student.h"
#include <iostream>
#include "TutorialConfig.h.in"


int main() {

    Student student("John Doe");
    
    student.setGrades(85, 90, 78);
    double average = student.calculateAverage();
    
    std::cout << "Student: " << student.getName() << std::endl;
    std::cout << "Media: " << average << std::endl;
    
    return 0;
}