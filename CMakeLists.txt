cmake_minimum_required(VERSION 3.16)
project(paint_tool CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_subdirectory(libs/SDL EXCLUDE_FROM_ALL)
add_subdirectory(libs/glad EXCLUDE_FROM_ALL)
add_subdirectory(libs/glm EXCLUDE_FROM_ALL)
add_subdirectory(libs/imgui EXCLUDE_FROM_ALL)

add_executable(paint_tool ${SOURCES})
target_link_libraries(paint_tool PRIVATE SDL3::SDL3 glad glm imgui)
target_include_directories(paint_tool PUBLIC ${CMAKE_SOURCE_DIR}/include)