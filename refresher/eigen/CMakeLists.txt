# set the include directive in the same project folder
set(CMAKE_INCLUDE_CURRENT_DIR ON)

##############################################################################
# PACKAGES
##############################################################################
message("***********************")
message("EIGEN3 PACKAGE")
message("***********************")

set(EIGEN3_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/eigen/" )
if(NOT EIGEN3_INCLUDE_DIR )
    message(FATAL_ERROR "Please point the variable EIGEN3_INCLUDE_DIR to the include directory of your Eigen3 installation.")
endif()
message(STATUS "    Eigen3 directory: ${EIGEN3_INCLUDE_DIR}")

##############################################################################
# HEADERS
##############################################################################
include_directories(${EIGEN3_INCLUDE_DIR})

find_package (Eigen3 REQUIRED NO_MODULE)
 
add_executable (myeigen main.cpp)
target_link_libraries (myeigen Eigen3::Eigen)