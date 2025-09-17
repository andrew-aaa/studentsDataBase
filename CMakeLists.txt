cmake_minimum_required(VERSION 3.10)
project(StudentDatabase)

set(CMAKE_CXX_STANDARD 17)

# Добавляем GoogleTest
add_subdirectory(googletest)

# Основная программа
add_executable(student_database main.cpp student.cpp)

# Тестовая программа
add_executable(student_tests test.cpp student.cpp)
target_link_libraries(student_tests PRIVATE gtest_main)
target_include_directories(student_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})