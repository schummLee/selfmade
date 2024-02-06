#ifndef EDGE_DETECTOR_H
#define EDGE_DETECTOR_H

#include <opencv2/opencv.hpp>

class EdgeDetector 
{
public:
    EdgeDetector();

    // Function to detect edges in a frame
    void DetectEdges(cv::Mat& frame);

private:
    // Add any private member variables or functions as needed

};

#endif // EDGE_DETECTOR_H
