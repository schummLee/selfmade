cmake_minimum_required(VERSION 3.6)
project(color_inverse)

set(CMAKE_CXX_STANDARD 17)


# Find OpenCV
set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/opencv/opencv/build")
find_package(OpenCV REQUIRED)

# Include directories for OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

# Add subdirectories for functions and kernel
add_subdirectory(src/functions)
add_subdirectory(src/kernel)



