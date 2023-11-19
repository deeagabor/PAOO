cmake_minimum_required(VERSION 3.10)

project(main VERSION 1.0)

add_executable(Main main.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")

add_subdirectory(student)
add_subdirectory(universityStudent)
add_subdirectory(highschoolStudent)

target_link_libraries(Main PUBLIC student)
target_link_libraries(Main PUBLIC universityStudent)
target_link_libraries(Main PUBLIC highschoolStudent)

target_include_directories (Main PUBLIC "${PROJECT_SOURCE_DIR}/student")
target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/universityStudent")
target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/highschoolStudent")
