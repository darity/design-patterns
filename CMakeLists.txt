cmake_minimum_required(VERSION 4.0)
project(PS)

set(CMAKE_CXX_STANDARD 14)

include_directories(Singleton/cpp)

add_executable(PS
        Singleton/cpp/Singleton.cpp
        Singleton/cpp/Singleton.h)
