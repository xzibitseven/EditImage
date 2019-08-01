#ifndef BILATERALFILTERING_HPP
#define BILATERALFILTERING_HPP

#include "smoothing.hpp"

class BilateralFiltering : public Smoothing {
    public:
        BilateralFiltering() = default;
        virtual void smooth(cv::Mat& m) {
            cv::Mat dst;
            cv::bilateralFilter(m, dst, 9,75,75);
            m = std::move(dst);
        }
};

#endif // BILATERALFILTERING_HPP
