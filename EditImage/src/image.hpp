#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include "smoothing.hpp"

class Image {
    public:
        explicit Image() = default;
        explicit Image(const std::string& fileName);

        void open(const std::string& fileName);
        void save(const std::string& fileName);
        void smoothing(const std::unique_ptr<Smoothing>& upSmothing);
        void outlineSelection();

    private:
        cv::Mat m_image;
};

#endif // IMAGE_HPP
