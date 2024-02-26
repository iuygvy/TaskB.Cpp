cmake_minimum_required(VERSION 3.24)
project(Zadanie_B)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest-release-1.12.1)

add_executable(Zadanie_B ${PROJECT_SOURCE_DIR}/ Operation.cpp Sum.cpp Mult.cpp testy_zad_c.cpp head.h source.cpp)

target_link_libraries(Zadanie_B gtest gtest_main)

