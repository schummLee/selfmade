#ifndef THRESHOLD_APPLIER_H
#define THRESHOLD_APPLIER_H

#include <opencv2/opencv.hpp>

class ThresholdApplier 
{
public:
    ThresholdApplier();

    // Function to apply thresholding to a frame
    void ApplyThreshold(cv::Mat& frame);

private:
    // Add any private member variables or functions as needed

};

#endif // THRESHOLD_APPLIER_H
