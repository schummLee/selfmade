#include "ColorInverter.h"

ColorInverter::ColorInverter() 
{
    // Constructor initialization if needed
}

void ColorInverter::InvertColor(cv::Mat& frame) 
{
    // Invert the color of the frame
    cv::bitwise_not(frame, frame);
}


