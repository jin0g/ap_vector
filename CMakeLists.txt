cmake_minimum_required(VERSION 3.24)
project(ap_vector)

set(CMAKE_CXX_STANDARD 14)

include_directories($ENV{HOME}/include)

add_executable(ap_vector main.cpp)
