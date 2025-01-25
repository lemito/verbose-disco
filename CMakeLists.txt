cmake_minimum_required(VERSION 3.30)
project(verbose_disco)

set(CMAKE_CXX_STANDARD 26)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++26")

include_directories(GenerativePatterns/Singleton)

add_executable(singleton
    GenerativePatterns/Singleton/Singleton.cpp
    GenerativePatterns/Singleton/Singleton.h)
add_executable(builder
        GenerativePatterns/Builder/Builder.cpp
        GenerativePatterns/Builder/Builder.h)
