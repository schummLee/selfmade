#include "FrameSaver.h"

FrameSaver::FrameSaver() 
{
    // Constructor initialization if needed
}

void FrameSaver::SaveFrame(const cv::Mat& frame, const std::string& filename) 
{
    // Save the frame to an image file
    cv::imwrite(filename, frame);
}
