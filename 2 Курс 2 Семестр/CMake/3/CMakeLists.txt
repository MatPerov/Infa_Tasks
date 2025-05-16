cmake_minimum_required(VERSION 3.10)
project(LinkLib)


set(LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main_app main.cpp)

target_include_directories(main_app PRIVATE ${LIBRARY_PATH})

target_link_directories(main_app PRIVATE ${LIBRARY_PATH})

target_link_libraries(main_app PRIVATE MyLib)