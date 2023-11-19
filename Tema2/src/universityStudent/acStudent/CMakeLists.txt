add_library(acStudent STATIC acStudent.cpp)

target_include_directories(acStudent PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(acStudent PUBLIC "${PROJECT_SOURCE_DIR}/universityStudent")
target_include_directories(acStudent PUBLIC "${PROJECT_SOURCE_DIR}/student")