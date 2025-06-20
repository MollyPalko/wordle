cmake_minimum_required(VERSION 3.10)
project(WordleGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Common source files
set(SOURCES src/Wordle.cpp)

# Main game executable
add_executable(wordle src/main.cpp ${SOURCES})

# Tester executable (only built when testing)
add_executable(wordle_tests src/Tester.cpp ${SOURCES})

