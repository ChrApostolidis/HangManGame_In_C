cmake_minimum_required(VERSION 3.30)
project(Hangman2_0 C)

set(CMAKE_C_STANDARD 11)

add_executable(Hangman2_0 main.c)
target_link_libraries(Hangman2_0 winmm)
