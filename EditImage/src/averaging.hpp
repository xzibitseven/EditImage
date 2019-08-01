#ifndef AVERAGING_HPP
#define AVERAGING_HPP

#include "smoothing.hpp"

class Averaging : public Smoothing {
    public:
        Averaging() = default;
        virtual void smooth(cv::Mat& m) {
            cv::Mat dst;
            cv::blur(m, dst, cv::Size(5,5));
            m = std::move(dst);
        }
};

#endif // AVERAGING_HPP
