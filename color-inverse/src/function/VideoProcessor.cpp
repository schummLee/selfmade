#include "VideoProcessor.h"

void VideoProcessor::ProcessVideo() 
{
    try {
        double frameInterval = 1.0 / GetDesiredFPS();
        cv::Mat frame;

        while (cap.read(frame)) {
            // Update dynamic parameters if needed
            double currentFPS = GetDesiredFPS();
            frameInterval = 1.0 / currentFPS;

            // Process the frame
            processingThreads.emplace_back(&VideoProcessor::ProcessFrame, this, frame.clone());

            // Wait for the calculated frame interval before processing the next frame
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>((frameInterval * 1000))));
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // Perform cleanup or additional error handling if needed
    }
}


VideoProcessor::VideoProcessor(const std::string& videoPath, double desiredFPS)
    : cap(videoPath), desiredFPS(desiredFPS) 
{
    if (!cap.isOpened()) {
        throw std::runtime_error("Error: Unable to open video file");
    }
}

VideoProcessor::~VideoProcessor() 
{
    // Join all processing threads before destruction
    for (auto& thread : processingThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

void VideoProcessor::SetDesiredFPS(double fps) 
{
    // std::lock_guard<std::mutex> lock(parameterMutex);
    desiredFPS = fps;
}

double VideoProcessor::GetDesiredFPS() const 
{
    // std::lock_guard<std::mutex> lock(parameterMutex);
    return desiredFPS;
}

void VideoProcessor::ProcessFrame(cv::Mat frame) 
{
    // Process the frame here
}

bool VideoProcessor::HasNextFrame() 
{
    return cap.isOpened() && cap.grab();
}

cv::Mat VideoProcessor::GetNextFrame() 
{
    cv::Mat frame;
    cap >> frame;
    return frame;
}
