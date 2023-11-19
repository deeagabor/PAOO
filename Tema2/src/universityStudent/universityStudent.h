#pragma once
#include "student.h"

namespace Campus {
    class UniversityStudent : public IStudent {
        protected:
            char* name;
            char* universityName;

            float grade1;
            float grade2;
            float grade3;

        public:
            UniversityStudent(const char* n, const char* un, float g1, const float g2, const float g3); // Constructor
            UniversityStudent(const UniversityStudent& other); // Copy Constructor
            UniversityStudent(UniversityStudent&& other); // Move Constructor
            ~UniversityStudent(); // Destructor


            float calculateMedia() override;
            char* getName() const override;
            float calculateScholarship() override;
            virtual void attendClasses() const;

            UniversityStudent& operator=(const UniversityStudent &other);
            UniversityStudent& operator=(UniversityStudent &&other);
    };
}