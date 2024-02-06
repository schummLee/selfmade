#include "Rotator.h"

Rotator::Rotator() 
{
    // Constructor initialization if needed
}

void Rotator::RotateFrame(cv::Mat& frame, double angle) 
{
    // Get the center of the frame
    cv::Point2f center(static_cast<float>(frame.cols / 2), static_cast<float>(frame.rows / 2));

    // Compute the rotation matrix
    cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, angle, 1.0);

    // Apply the rotation to the frame
    cv::warpAffine(frame, frame, rotationMatrix, frame.size());
}

