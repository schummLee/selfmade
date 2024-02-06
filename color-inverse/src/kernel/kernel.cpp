#include <iostream>
#include <chrono>
#include "../functions/VideoProcessor.h"

void kernel_as_multithreading_enaplied_as_decentralized() 
{
    // Initialize VideoProcessor with video file path and desired FPS
    VideoProcessor videoProcessor("input_video.mp4", 30.0);

    // Initialize processing components here


    // Set dynamic parameters (optional)
    videoProcessor.SetDesiredFPS(60.0);

    // Process video
    auto start = std::chrono::high_resolution_clock::now();

    videoProcessor.ProcessVideo();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Total processing time: " << duration.count() << " ms" << std::endl;
}

int main() 
{
    kernel_as_multithreading_enaplied_as_decentralized(); 
    // initilize as processing is in state of multi-threading etc..
    return 0;
}


