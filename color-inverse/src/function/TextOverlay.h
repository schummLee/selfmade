#ifndef TEXT_OVERLAY_H
#define TEXT_OVERLAY_H

#include <opencv2/opencv.hpp>
#include <string>

class TextOverlay 
{
public:
    TextOverlay();

    // Function to overlay text on a frame
    void OverlayText
    (
        cv::Mat& frame, 
        const std::string& text, 
        cv::Point position,
        cv::Scalar color = cv::Scalar(255, 255, 255), 
        int fontFace = cv::FONT_HERSHEY_SIMPLEX,
        double fontScale = 1.0, 
        int thickness = 1
    );

private:
    // Add any private member variables or functions as needed

};

#endif // TEXT_OVERLAY_H
