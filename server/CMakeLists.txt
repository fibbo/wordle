cmake_minimum_required(VERSION 3.28)

project(Wordle)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost 1.75.0 REQUIRED COMPONENTS system)

add_executable(wordle-local src/main.cpp src/game.cpp)

target_link_libraries(wordle-local Boost::system)
