#include "ThresholdApplier.h"

ThresholdApplier::ThresholdApplier() 
{
    // Constructor initialization if needed
}

void ThresholdApplier::ApplyThreshold(cv::Mat& frame) 
{
    // Apply binary thresholding to the frame
    cv::threshold(frame, frame, 127, 255, cv::THRESH_BINARY); // Adjust threshold value as needed
}

