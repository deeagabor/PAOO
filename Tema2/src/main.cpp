#include <iostream>

#include "acStudent.h"

using namespace Campus;

int main() {
    UniversityStudent uniStudent("Bob Smith", "University Politehnica of Timisoara", 9, 8, 7);

    std::cout << "University Student: " << uniStudent.getName() << std::endl;
    std::cout << "Media: " << uniStudent.calculateMedia() << std::endl;
    std::cout << "Scholarship: " << uniStudent.calculateScholarship() << std::endl;
    uniStudent.attendClasses();

    std::cout << std::endl;

    UniversityStudent uniStudentCopy("Copy Bob Smith", "University Politehnica of Timisoara", 9, 8, 7);
    uniStudent = uniStudentCopy;

    std::cout << "University Student of copy: " << uniStudent.getName() << std::endl;
    std::cout << "Media of copy: " << uniStudent.calculateMedia() << std::endl;
    std::cout << "Scholarship of copy: " << uniStudent.calculateScholarship() << std::endl;
    uniStudent.attendClasses();

    std::cout << std::endl;

    AcStudent acStudent("Joe Doe", "University Politehnica of Timisoara", 6, 7, 5);
    std::cout << "University Student: " << acStudent.getName() << std::endl;
    std::cout << "Media: " << acStudent.calculateMedia() << std::endl;
    std::cout << "Scholarship: " << acStudent.calculateScholarship() << std::endl;
    acStudent.attendClasses();

    std::cout << std::endl;

    AcStudent acStudentMove("Jim Bim", "University Politehnica of Timisoara", 3, 4, 5);
    std::cout << "University Student: " << acStudentMove.getName() << std::endl;
    std::cout << "Media: " << acStudentMove.calculateMedia() << std::endl;

    acStudentMove = AcStudent("Move Jim Bim", "University Politehnica of Timisoara", 4, 5, 6);

    std::cout << "Scholarship of move: " << acStudentMove.calculateScholarship() << std::endl;
    acStudentMove.attendClasses();

    std::cout << std::endl;

    return 0;
}