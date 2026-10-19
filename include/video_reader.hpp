#pragma once

#include <opencv2/opencv.hpp>
#include <string>

class VideoReader {
    public:
        explicit VideoReader(const std::string& path);

        bool isOpened() const;
        bool readFrame(cv::Mat& frame);

        double getFPS() const;
        int getWidth() const;
        int getHeight() const;
        int getFrameCount() const;

    private:
        cv::VideoCapture capture_;
};