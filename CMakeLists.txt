cmake_minimum_required(VERSION 3.16)
project(paint_tool C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/libs")

include_directories(include)

# SDL3 and glad
add_subdirectory(libs/SDL)
add_subdirectory(libs/glad)

add_executable(paint_tool src/main.c)
target_link_libraries(paint_tool PRIVATE SDL3::SDL3 glad)