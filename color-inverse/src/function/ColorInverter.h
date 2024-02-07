#ifndef COLOR_INVERTER_H
#define COLOR_INVERTER_H

#include <opencv2/opencv.hpp>

class ColorInverter 
{
public:
    ColorInverter(cv::Mat& inverted_color_swap);
    // Function to invert the color of a single frame
    void InvertColor(cv::Mat& frame);
    void InvertColor_BlacknWhite(cv::Mat& frame);

private:
    // Add any private member variables or functions as needed
    cv::Mat& inverted_color_swap;
};

#endif // COLOR_INVERTER_H

