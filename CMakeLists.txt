cmake_minimum_required(VERSION 3.15.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(cpp_projects)

add_subdirectory(libs/eigen)
add_subdirectory(refresher/hello_world)

add_subdirectory(refresher/eigen)
add_subdirectory(refresher/progress_bar) 
add_subdirectory(refresher/terminal_args)
add_subdirectory(refresher/vector)