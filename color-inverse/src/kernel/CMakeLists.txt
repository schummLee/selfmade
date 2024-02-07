# src/kernel/CMakeLists.txt
add_executable(kernel
    kernel.cpp
    # Add other source files here
)

# Include directories for OpenCV if needed
target_include_directories(kernel PUBLIC ${OpenCV_INCLUDE_DIRS})

# Link with OpenCV if needed
target_link_libraries(kernel PUBLIC ${OpenCV_LIBS})

# Link with functions library
target_link_libraries(kernel PUBLIC functions)
