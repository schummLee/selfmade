#include "Resizer.h"

Resizer::Resizer() 
{
    // Constructor initialization if needed
}

void Resizer::ResizeFrame(cv::Mat& frame, int width, int height) 
{
    // Resize the frame to the specified size
    cv::resize(frame, frame, cv::Size(width, height));
}
