#pragma once

#include <opencv2/opencv.hpp>
#include <string>

class VideoWriter {
    public:
        VideoWriter (const std::string& path,
                    double fps,
                    int width,
                    int height);

        bool isOpened() const;

        void writeFrame(const cv::Mat& frame);

    private:
    cv::VideoWriter writer_;
};