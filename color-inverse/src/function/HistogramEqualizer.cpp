#include "HistogramEqualizer.h"

HistogramEqualizer::HistogramEqualizer() 
{
    // Constructor initialization if needed
}

void HistogramEqualizer::EqualizeHistogram(cv::Mat& frame) 
{
    // Convert the frame to grayscale if it's not already in grayscale
    if (frame.channels() > 1) {
        cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
    }

    // Apply histogram equalization to the frame
    cv::equalizeHist(frame, frame);
}

