#ifndef BLUR_APPLIER_H
#define BLUR_APPLIER_H

#include <opencv2/opencv.hpp>

class BlurApplier 
{
public:
    BlurApplier();

    // Function to apply blur to a frame
    void ApplyBlur(cv::Mat& frame);

private:
    // Add any private member variables or functions as needed

};

#endif // BLUR_APPLIER_H
