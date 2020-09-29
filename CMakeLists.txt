# version

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_COMPILER c++)
set(CMAKE_CXX_STANDARD 17)

# project 

project(DES)

# include 

include_directories(./include ./src)

# target 

add_executable(DES ./src/main.cpp ./src/des.cpp ./src/rng-utils.cpp)


