cmake_minimum_required(VERSION 3.16)
project(paint_tool C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

file(GLOB SOURCES "src/*.c")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(libs/SDL EXCLUDE_FROM_ALL)
add_subdirectory(libs/glad EXCLUDE_FROM_ALL)
add_subdirectory(libs/stb_ds EXCLUDE_FROM_ALL)

add_executable(paint_tool ${SOURCES})
target_link_libraries(paint_tool PRIVATE SDL3::SDL3 glad stb_ds)
target_include_directories(paint_tool PUBLIC ${CMAKE_SOURCE_DIR})