#ifndef FRAME_SAVER_H
#define FRAME_SAVER_H

#include <opencv2/opencv.hpp>
#include <string>

class FrameSaver 
{
public:
    FrameSaver();

    // Function to save a frame to an image file
    void SaveFrame(const cv::Mat& frame, const std::string& filename);

private:
    // Add any private member variables or functions as needed

};

#endif // FRAME_SAVER_H
