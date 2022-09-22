cmake_minimum_required(VERSION 3.15.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(refresh_cpp)

add_subdirectory(libs/eigen)
add_subdirectory(hello_world)

add_subdirectory(eigen)
add_subdirectory(progress_bar) 
add_subdirectory(terminal_args)
add_subdirectory(vector)