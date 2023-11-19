#pragma once
#include "student.h"

namespace Campus {
    class HighschoolStudent : public IStudent {
        protected:
            char* name;
            char* highschoolName;

            float grade1;
            float grade2;

        public:
            HighschoolStudent(const char* n, const char* hi, float g1, const float g2); // Constructor
            ~HighschoolStudent(); // Destructor

            float calculateMedia() override;
            char* getName() const override;
            float calculateScholarship() override;
    };
}