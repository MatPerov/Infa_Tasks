cmake_minimum_required(VERSION 3.10)
project(Project) 

add_executable(app main.cpp image.cpp)


target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})