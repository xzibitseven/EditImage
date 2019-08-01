#ifndef GAUSSIANBLURRING_HPP
#define GAUSSIANBLURRING_HPP

#include "smoothing.hpp"

class GaussianBlurring : public Smoothing {
    public:
        GaussianBlurring() = default;
        virtual void smooth(cv::Mat& m) {
            cv::Mat dst;
            cv::GaussianBlur(m, dst,cv::Size(5,5),0);
            m = std::move(dst);
        }
};

#endif // GAUSSIANBLURRING_HPP
