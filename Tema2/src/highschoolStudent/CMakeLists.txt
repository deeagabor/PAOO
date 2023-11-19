add_library(highschoolStudent STATIC highschoolStudent.cpp)

target_include_directories(highschoolStudent PUBLIC "${PROJECT_SOURCE_DIR}")
target_include_directories(highschoolStudent PUBLIC "${PROJECT_SOURCE_DIR}/student")