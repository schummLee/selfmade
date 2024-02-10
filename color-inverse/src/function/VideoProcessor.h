#ifndef VIDEO_PROCESSOR_H
#define VIDEO_PROCESSOR_H

#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <vector>
#include <stdexcept> // For std::runtime_error

class VideoProcessor 
{
public:
    VideoProcessor(const std::string& videoPath, double desiredFPS);
    ~VideoProcessor(); // Destructor to join threads

    void ProcessVideo();

    // Public member functions to update parameters dynamically
    void SetDesiredFPS(double fps);
    double GetDesiredFPS() const;

    bool HasNextFrame();
    cv::Mat GetNextFrame();

private:
    cv::VideoCapture cap;
    double desiredFPS;
    std::vector<std::thread> processingThreads;

    // Dynamic parameters (add more as needed)
    std::mutex parameterMutex; // Mutex for thread-safe parameter access

    // Private member functions
    void ProcessFrame(cv::Mat frame);

    // Add any private member variables or functions as needed

};

#endif // VIDEO_PROCESSOR_H
