cmake_minimum_required(VERSION 3.5)
project(Choose)

if(NOT DEFINED ENV{ANIMAL_TYPE} AND NOT DEFINED ANIMAL_TYPE)
  message(FATAL_ERROR " ")
endif()

if(DEFINED ENV{ANIMAL_TYPE})
  set(ANIMAL_TYPE "$ENV{ANIMAL_TYPE}")
endif()

# В зависимости от значения выбираем исходный файл
if(ANIMAL_TYPE STREQUAL "Cat")
  set(SOURCE_FILE "src/cat.cpp")
  set(EXECUTABLE_NAME "animal")
elseif(ANIMAL_TYPE STREQUAL "Dog")
  set(SOURCE_FILE "src/dog.cpp")
  set(EXECUTABLE_NAME "animal")
elseif(ANIMAL_TYPE STREQUAL "Mouse")
  set(SOURCE_FILE "src/mouse.cpp")
  set(EXECUTABLE_NAME "animal")
else()
  message(FATAL_ERROR " ")
endif()

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
