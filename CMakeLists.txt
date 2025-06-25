cmake_minimum_required(VERSION 3.10)

# Project name
project(TextUtility)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(textutil main.cpp text_utility.cpp)