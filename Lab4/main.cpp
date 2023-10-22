#include "Student.h"
#include <iostream>
#include "TutorialConfig.h.in"


int main() {

    Student student("John Doe", 10, 9, 7);
    
    float media = student.calculateMedia();
    
    std::cout << "Student: " << student.getName() << std::endl;
    std::cout << "Media: " << media << std::endl;
    
    return 0;
}