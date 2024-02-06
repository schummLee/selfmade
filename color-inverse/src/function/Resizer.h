#ifndef RESIZER_H
#define RESIZER_H

#include <opencv2/opencv.hpp>

class Resizer 
{
public:
    Resizer();

    // Function to resize a frame to a specified size
    void ResizeFrame(cv::Mat& frame, int width, int height);

private:
    // Add any private member variables or functions as needed

};

#endif // RESIZER_H
