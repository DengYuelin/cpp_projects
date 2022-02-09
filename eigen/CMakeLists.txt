find_package (Eigen3 3.3 REQUIRED NO_MODULE)
 
add_executable (myeigen main.cpp)
target_link_libraries (myeigen Eigen3::Eigen)