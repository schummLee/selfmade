#include "ColorInverter.h"

ColorInverter::ColorInverter(cv::Mat& inverted_color_swap) : inverted_color_swap(inverted_color_swap) 
{
    // Constructor body (if any)
}


void ColorInverter::InvertColor(cv::Mat& frame) 
{
    // Invert the color of the frame
    cv::bitwise_not(frame, frame);
}

void ColorInverter::InvertColor_BlacknWhite(cv::Mat& frame)
{
    // Iterate through each pixel in the image
    for (int y = 0; y < frame.rows; ++y) {
        for (int x = 0; x < frame.cols; ++x) {
            // Get the intensity value of the pixel
            uchar& intensity = frame.at<uchar>(y, x);
            
            // Invert the intensity value
            intensity = 255 - intensity;
        }
    }
}
