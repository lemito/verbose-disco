cmake_minimum_required(VERSION 3.30)
project(verbose_disco)

#set(CMAKE_CXX_STANDARD 26)
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2c")
set(CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")

include_directories(GenerativePatterns/Singleton)

add_executable(singleton
    GenerativePatterns/Singleton/Singleton.cpp
    GenerativePatterns/Singleton/Singleton.h)
add_executable(builder
        GenerativePatterns/Builder/Builder.cpp
        GenerativePatterns/Builder/Builder.h)
add_executable(FactoryMethod GenerativePatterns/FactoryMethod/FactoryMethod.cpp GenerativePatterns/FactoryMethod/FactoryMethod.h)
add_executable(AbstractFactory GenerativePatterns/AbstrractFactory/AbstractFactory.cpp GenerativePatterns/AbstrractFactory/AbstractFactory.h)
add_executable(BST BehavioralPatterns/Iterators/BST/BST.cpp BehavioralPatterns/Iterators/BST/BST.h)
add_executable(Prototype GenerativePatterns/Prototype/Prototype.cpp GenerativePatterns/Prototype/Prototype.h)
add_executable(ranges ranges/ranges.cpp)
