find_package (Eigen3 3.3 REQUIRED NO_MODULE)
 
add_executable (example example.cpp)
target_link_libraries (example Eigen3::Eigen)