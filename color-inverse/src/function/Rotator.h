#ifndef ROTATOR_H
#define ROTATOR_H

#include <opencv2/opencv.hpp>

class Rotator 
{
public:
    Rotator();

    // Function to rotate a frame by a specified angle
    void RotateFrame(cv::Mat& frame, double angle);

private:
    // Add any private member variables or functions as needed

};

#endif // ROTATOR_H
