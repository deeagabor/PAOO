add_library(universityStudent STATIC universityStudent.cpp acStudent/acStudent.cpp)

add_subdirectory(acStudent)

target_link_libraries(universityStudent PUBLIC acStudent)

target_include_directories(universityStudent PUBLIC "${PROJECT_SOURCE_DIR}")
target_include_directories(universityStudent PUBLIC "${PROJECT_SOURCE_DIR}/universityStudent/acStudent")
target_include_directories(universityStudent PUBLIC "${PROJECT_SOURCE_DIR}/student")