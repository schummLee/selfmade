#ifndef HISTOGRAM_EQUALIZER_H
#define HISTOGRAM_EQUALIZER_H

#include <opencv2/opencv.hpp>

class HistogramEqualizer 
{
public:
    HistogramEqualizer();

    // Function to apply histogram equalization to a frame
    void EqualizeHistogram(cv::Mat& frame);

private:
    // Add any private member variables or functions as needed

};

#endif // HISTOGRAM_EQUALIZER_H
