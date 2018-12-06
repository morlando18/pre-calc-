cmake_minimum_required(VERSION 3.3)
project(InfixToPostFix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(InfixToPostFix ${SOURCE_FILES})