cmake_minimum_required(VERSION 3.25)
project(guess C)

set(CMAKE_C_STANDARD 17)

add_subdirectory(0-intro)
add_subdirectory(1-types-io)
add_subdirectory(oj-work-4)
add_subdirectory(5-function)
add_subdirectory(oj-work-5)
add_subdirectory(exam-1)
add_subdirectory(6-)
add_subdirectory(oj-work-6)
add_subdirectory(7-data-type)
add_subdirectory(oj-work-7)
add_subdirectory(oj-work-8)
add_subdirectory(9-pointers-c-strings)
add_subdirectory(oj-work-9)
add_subdirectory(10-double-pointers)
add_subdirectory(11-function-pointers)
add_subdirectory(oj-work-10)
add_subdirectory(12-struct)
add_subdirectory(13-linked-lists)
add_executable(uoj uoj.c)
add_subdirectory(oj-work-11)
add_subdirectory(2021-exam)

add_executable(turn turn.c)
