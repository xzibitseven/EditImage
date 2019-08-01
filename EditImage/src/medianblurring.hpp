#ifndef MEDIANBLURRING_HPP
#define MEDIANBLURRING_HPP

#include "smoothing.hpp"

class MedianBlurring : public Smoothing {
    public:
        MedianBlurring() = default;
        virtual void smooth(cv::Mat& m) {
            cv::Mat dst;
            medianBlur( m, dst, 5 );
            m = std::move(dst);
        }
};

#endif // MEDIANBLURRING_HPP
