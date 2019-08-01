#ifndef SMOOTHING_HPP
#define SMOOTHING_HPP

#include <opencv2/opencv.hpp>

class Smoothing {
    public:
        Smoothing() = default;
        virtual ~Smoothing() = default;
        virtual void smooth(cv::Mat& ) = 0;
};

#endif // SMOOTHING_HPP
