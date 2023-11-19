#include "universityStudent.h"

namespace Campus {
    class AcStudent : public UniversityStudent {

    public:
        AcStudent(const char* n, const char* un, float g1, const float g2, const float g3);
        ~AcStudent();

        void attendClasses() const override;

        AcStudent& operator=(const AcStudent &other);
        AcStudent& operator=(AcStudent &&other);
    };
}