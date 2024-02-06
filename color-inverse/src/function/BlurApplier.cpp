#include "BlurApplier.h"

BlurApplier::BlurApplier() 
{
    // Constructor initialization if needed
}

void BlurApplier::ApplyBlur(cv::Mat& frame) 
{
    // Apply Gaussian blur to the frame
    cv::GaussianBlur(frame, frame, cv::Size(5, 5), 0); // Adjust kernel size as needed
}

