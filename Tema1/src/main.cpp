#include "student.h"
#include <iostream>

int main() {

    Student student1("Gabor Andreea", 10, 9, 7);
    Student student2("Wolf Lorena", 10, 10, 8);

    float media1 = student1.calculateMedia();
    float media2 = student2.calculateMedia();
    
    std::cout << "Student 1: " << student1.getName() << std::endl;
    std::cout << "Media 1: " << media1 << std::endl;

    std::cout << "Student 2: " << student2.getName() << std::endl;
    std::cout << "Media 2: " << media2 << std::endl;

    Student studentCopy = student1; // Using the copy constructor

    float copyMedia = studentCopy.calculateMedia();

    std::cout << "Copy Student: " << studentCopy.getName() << std::endl;
    std::cout << "Copy Media: " << copyMedia << std::endl;


    Student studentMove(std::move(student2)); // Using the move constructor
    
    float moveMedia = studentMove.calculateMedia();

    std::cout << "Move Student: " << studentMove.getName() << std::endl;
    std::cout << "Move Media: " << moveMedia << std::endl;

    return 0;
}