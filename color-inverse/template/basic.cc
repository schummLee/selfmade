#include <iostream>
#include <chrono>
#include "../functions/VideoProcessor.h"
#include "../functions/GrayscaleConverter.h"
#include "../functions/EdgeDetector.h"
#include "../functions/BlurApplier.h"
#include "../functions/ThresholdApplier.h"
#include "../functions/HistogramEqualizer.h"
#include "../functions/Rotator.h"
#include "../functions/Resizer.h"
#include "../functions/TextOverlay.h"
#include "../functions/FrameSaver.h"

template<typename VideoProcessorType, typename GrayscaleConverterType, typename EdgeDetectorType,
         typename BlurApplierType, typename ThresholdApplierType, typename HistogramEqualizerType,
         typename RotatorType, typename ResizerType, typename TextOverlayType, typename FrameSaverType>
void kernel_as_multithreading_enaplied_as_decentralized() 
{
    // Initialize VideoProcessor with video file path and desired FPS
    VideoProcessorType videoProcessor("input_video.mp4", 30.0);

    // Initialize processing components
    GrayscaleConverterType grayscaleConverter;
    EdgeDetectorType edgeDetector;
    BlurApplierType blurApplier;
    ThresholdApplierType thresholdApplier;
    HistogramEqualizerType histogramEqualizer;
    RotatorType rotator;
    ResizerType resizer;
    TextOverlayType textOverlay;
    FrameSaverType frameSaver;

    // Set dynamic parameters (optional)
    videoProcessor.SetDesiredFPS(60.0);

    // Process video
    auto start = std::chrono::high_resolution_clock::now();

    videoProcessor.ProcessVideo();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Total processing time: " << duration.count() << " ms" << std::endl;
}

// Function to determine weather conditions based on input video
template<typename VideoProcessorType, typename GrayscaleConverterType, typename EdgeDetectorType,
         typename HistogramEqualizerType, typename TextOverlayType, typename FrameSaverType>
void determineWeatherConditions(const std::string& inputVideoPath) {
    // Initialize VideoProcessor with the input video file path and desired FPS
    VideoProcessorType videoProcessor(inputVideoPath, 30.0);

    // Initialize processing components
    GrayscaleConverterType grayscaleConverter;
    EdgeDetectorType edgeDetector;
    HistogramEqualizerType histogramEqualizer;
    TextOverlayType textOverlay;
    FrameSaverType frameSaver;

    // Set dynamic parameters if needed

    // Process video frame by frame
    while (videoProcessor.HasNextFrame()) {
        // Read the next frame
        cv::Mat frame = videoProcessor.GetNextFrame();

        // Convert the frame to grayscale
        // cv::Mat grayFrame = grayscaleConverter.ConvertToGrayscale(frame);

        // // Apply edge detection
        // cv::Mat edges = edgeDetector.DetectEdges(grayFrame);

        // // Apply histogram equalization
        // cv::Mat equalizedFrame = histogramEqualizer.Equalize(grayFrame);

        // // Apply text overlay indicating weather conditions
        // cv::Mat annotatedFrame = textOverlay.AddText(equalizedFrame, "Weather: Sunny");

        // // Save or display the annotated frame
        // frameSaver.SaveFrame(annotatedFrame);
        // cv::imshow("Annotated Frame", annotatedFrame);
        // cv::waitKey(30); // Adjust the delay between frames if needed
    }
}

void main -> int () 
{
    kernel_as_multithreading_enaplied_as_decentralized<VideoProcessor, GrayscaleConverter, EdgeDetector,
        BlurApplier, ThresholdApplier, HistogramEqualizer, Rotator, Resizer, TextOverlay, FrameSaver>(); 
    // initialize as processing is in state of multi-threading etc..
    return 0;
}

