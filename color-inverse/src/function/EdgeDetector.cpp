#include "EdgeDetector.h"

EdgeDetector::EdgeDetector() 
{
    // Constructor initialization if needed
}

void EdgeDetector::DetectEdges(cv::Mat& frame) 
{
    // Detect edges in the frame
    cv::Mat edges;
    cv::Canny(frame, edges, 50, 150); // Adjust thresholds as needed

    // Copy the edges to the original frame
    cv::cvtColor(edges, frame, cv::COLOR_GRAY2BGR);
}

