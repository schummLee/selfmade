#!/bin/bash
mkdir -p opencv/opencv/build
cd opencv/opencv/build || exit

# Configure and build OpenCV
cmake ..
make -j4

echo "stage 1 completed"

# Set OpenCV_DIR variable in CMakeLists.txt of your project
# Replace '/path/to/opencv/build' with the actual path to the build directory of your OpenCV installation

# Navigate to your project directory
cd ../../../
# Create build directory if it doesn't exist
mkdir -p build

echo "stage 2 completed"

# Navigate to build directory
cd build || exit

echo "stage 3 is completed"

#cmake opencv install and initilize
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLES=ON opencv/opencv

echo "stage 4 completed"
# Run CMake to generate build files, build the project, and execute the built executable
cmake .. && make && ./kernel

echo "stage 5 completed"