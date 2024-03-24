cmake_minimum_required(VERSION 3.28)

project(Wordle)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost 1.75.0 REQUIRED COMPONENTS system)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(wordle-local src/main.cpp src/game.cpp)
target_link_libraries(wordle-local PRIVATE Boost::system)

enable_testing()

add_executable(wordle-test src/test/wordle_tests.cpp src/game.cpp)
target_link_libraries(
  wordle-test
  GTest::gtest_main
  Boost::system
)

include(GoogleTest)
gtest_discover_tests(wordle-test)



# Download wordle word-bank and dictionary from github
file(DOWNLOAD https://raw.githubusercontent.com/seanpatlan/wordle-words/main/valid-words.csv ${CMAKE_CURRENT_SOURCE_DIR}/valid_words.txt)
file(DOWNLOAD https://raw.githubusercontent.com/seanpatlan/wordle-words/main/word-bank.csv ${CMAKE_CURRENT_SOURCE_DIR}/word_bank.txt)
