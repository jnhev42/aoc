cmake_minimum_required(VERSION 3.26)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

add_library(mylib STATIC Move.h Move.cpp Outcome.h Outcome.cpp)

add_executable(cpp main.cpp)

target_link_libraries(cpp PUBLIC mylib)


