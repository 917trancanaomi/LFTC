cmake_minimum_required(VERSION 3.21)
project(Lab2_HashTable)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2_HashTable main.cpp HashTable/HashTable.h SymbolTable/SymbolTable.h SymbolTable/SymbolTable.cpp Scanner/Scanner.h Scanner/Scanner.cpp)
