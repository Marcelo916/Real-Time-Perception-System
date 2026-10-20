#include "video_writer.hpp"

VideoWriter::VideoWriter(const std::string& path,
                        double fps,
                        int width,
                        int height)
    : writer_(
            path,
            cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),
            fps,
            cv::Size(width, height)
    ){}

bool VideoWriter::isOpened() const {
    return writer_.isOpened();
}

void VideoWriter::writeFrame(const cv::Mat& frame) {
    writer_.write(frame);
}