#include "GrayscaleConverter.h"

GrayscaleConverter::GrayscaleConverter() 
{
    // Constructor initialization if needed
}

void GrayscaleConverter::ConvertToGrayscale(cv::Mat& frame) 
{
    // Convert the frame to grayscale
    cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
}


