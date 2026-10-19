#include <iostream>
#include "video_reader.hpp"

int main() {
    std::cout << "Real-Time Perception System\n";

    // Open the input video
    VideoReader video("data/video.avi");

    // Check whether the video opened succesfully
    if (!video.isOpened()) {
        std::cerr << "Error: Could not open video.\n";
        return 1;
    }

    std::cout << "Video opened succesffully!\n";

    // Retrieve video information
    std::cout << "FPS: " << video.getFPS() << "\n";
    std::cout << "Resolution: "
                << video.getWidth() << " x "
                << video.getHeight() << "\n";

    std::cout << "Total frames: " << video.getFrameCount() << "\n";

    // Read the video frame by frame
    cv::Mat frame;
    int frameCount = 0;

    while (video.readFrame(frame)) {
        frameCount++;

        if (frameCount % 100 == 0) {
            std::cout << "Processed " << frameCount << " frames\n";
        }
    }

    std::cout << "Finished processing " << frameCount << " frames.\n";

    return 0;
}