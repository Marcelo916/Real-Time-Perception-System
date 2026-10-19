#include "video_reader.hpp"

VideoReader::VideoReader(const std::string& path)
    : capture_(path) {}

bool VideoReader::isOpened() const {
    return capture_.isOpened();
}

bool VideoReader::readFrame(cv::Mat& frame) {
    return capture_.read(frame);
}

double VideoReader::getFPS() const {
    return capture_.get(cv::CAP_PROP_FPS);
}

int VideoReader::getWidth() const {
    return static_cast<int> (
        capture_.get(cv::CAP_PROP_FRAME_WIDTH)
    );
}

int VideoReader::getHeight() const {
    return static_cast<int> (
        capture_.get(cv::CAP_PROP_FRAME_HEIGHT)
    );
}

int VideoReader::getFrameCount() const {
    return static_cast<int> (
        capture_.get(cv::CAP_PROP_FRAME_COUNT)
    );
}