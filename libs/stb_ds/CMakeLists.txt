cmake_minimum_required(VERSION 3.16)
project(stb_ds)

add_library(stb_ds src/stb_ds.c)
target_include_directories(stb_ds PUBLIC include/)