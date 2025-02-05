cmake_minimum_required(VERSION 3.16)
project(paint_tool C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(libs/SDL EXCLUDE_FROM_ALL)
add_subdirectory(libs/glad EXCLUDE_FROM_ALL)

add_executable(paint_tool src/main.c)
target_link_libraries(paint_tool PRIVATE SDL3::SDL3 glad)
target_include_directories(paint_tool PRIVATE ${CMAKE_SOURCE_DIR}/include)