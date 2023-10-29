cmake_minimum_required(VERSION 3.10)

project(main VERSION 1.0)

add_executable(Main main.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)

target_link_libraries(Main PUBLIC lib)

target_include_directories(Main PUBLIC
                           "${PROJECT_SOURCE_DIR}/lib"
                           )
