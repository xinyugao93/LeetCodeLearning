cmake_minimum_required(VERSION 3.25)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra)

add_executable(${PROJECT_NAME} main.cpp)
