cmake_minimum_required(VERSION 3.10)

project(Lab4)

project(Lab4 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(TutorialConfig.h.in TutorialConfig.h)

add_executable(Lab4 main.cpp Student.cpp)

target_include_directories(Lab4 PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
