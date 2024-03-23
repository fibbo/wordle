cmake_minimum_required(VERSION 3.28)

project(Wordle)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost 1.75.0 REQUIRED COMPONENTS system)

add_executable(wordle-local src/main.cpp src/game.cpp)

target_link_libraries(wordle-local Boost::system)


# Download wordle word-bank and dictionary from github
file(DOWNLOAD https://raw.githubusercontent.com/seanpatlan/wordle-words/main/valid-words.csv ${CMAKE_CURRENT_SOURCE_DIR}/valid_words.txt)
file(DOWNLOAD https://raw.githubusercontent.com/seanpatlan/wordle-words/main/word-bank.csv ${CMAKE_CURRENT_SOURCE_DIR}/word_bank.txt)
