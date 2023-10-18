cmake_minimum_required(VERSION 3.26)
project(27_4_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(27_4_2 main.cpp
        includes/utilities.h
        includes/Shape.h
        includes/Circle.h
        includes/Rect.h
        includes/Triangle.h
        includes/constants.h)
