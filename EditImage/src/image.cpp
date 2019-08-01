#include "image.hpp"

Image::Image(const std::string& fileName):
        m_image(cv::imread(fileName)) {
    if(m_image.empty())
        throw std::runtime_error("Failed to read " + fileName);
}

void Image::open(const std::string& fileName) {
    m_image = cv::imread(fileName);
    if(m_image.empty())
        throw std::runtime_error("Failed to read " + fileName);
}

void Image::save(const std::string& fileName) {
    cv::imwrite(fileName, m_image);
}

void Image::smoothing(const std::unique_ptr<Smoothing>& upSmothing) {
    upSmothing->smooth(m_image);
}

void Image::outlineSelection() {
    cv::Mat imgray;
    cv::cvtColor(m_image,imgray, cv::COLOR_BGR2GRAY);

    double thresh{127};
    cv::threshold(imgray,imgray, thresh, 255, 0);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(imgray, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    cv::Scalar color( 0, 255, 0 );
    cv::drawContours( m_image, contours, -1, color);
}
