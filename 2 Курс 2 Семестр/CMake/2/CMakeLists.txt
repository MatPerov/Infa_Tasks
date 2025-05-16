cmake_minimum_required(VERSION 3.10)
project(ImageLibrary)

add_library(lib STATIC image.cpp)

target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})