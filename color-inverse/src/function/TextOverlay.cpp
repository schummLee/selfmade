#include "TextOverlay.h"

TextOverlay::TextOverlay() 
{
    // Constructor initialization if needed
}

void TextOverlay::OverlayText
(
    cv::Mat& frame, 
    const std::string& text, 
    cv::Point position,
    cv::Scalar color, 
    int fontFace, 
    double fontScale, 
    int thickness
    ) 
                              
{
    // Overlay text on the frame
    cv::putText(frame, text, position, fontFace, fontScale, color, thickness);
}
