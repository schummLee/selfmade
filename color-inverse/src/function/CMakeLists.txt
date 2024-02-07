# CMakeLists.txt in the src/functions directory

# Add all source files in the functions directory to a library target
add_library(functions
    GrayscaleConverter.cpp
    BlurApplier.cpp
    ColorInverter.cpp
    EdgeDetector.cpp
    FrameSaver.cpp
    HistogramEqualizer.cpp 
    Resizer.cpp 
    Rotator.cpp 
    TextOverlay.cpp 
    ThresholdApplier.cpp 
    VideoProcessor.cpp
    # Add other source files here
)

# Include the src/functions directory as an include directory
target_include_directories(functions PUBLIC ${OpenCV_INCLUDE_DIRS})

target_link_libraries(functions ${OpenCV_LIBS})