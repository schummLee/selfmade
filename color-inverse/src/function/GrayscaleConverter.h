#ifndef GRAYSCALE_CONVERTER_H
#define GRAYSCALE_CONVERTER_H

#include <opencv2/opencv.hpp>

class GrayscaleConverter 
{
public:
    GrayscaleConverter();

    // Function to convert a frame to grayscale
    void ConvertToGrayscale(cv::Mat& frame);

private:
    // Add any private member variables or functions as needed

};

#endif // GRAYSCALE_CONVERTER_H

