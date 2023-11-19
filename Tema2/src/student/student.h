#pragma once

namespace Campus {
    class IStudent {
        public:
            virtual float calculateScholarship() = 0; 
            virtual float calculateMedia() = 0;
            virtual char* getName() const = 0;
    };
}
