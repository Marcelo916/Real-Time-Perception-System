#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>

#include "video_reader.hpp"
#include "video_writer.hpp"

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

    VideoWriter writer(
        "data/processed.avi",
        video.getFPS(),
        video.getWidth(),
        video.getHeight()
    );

    if (!writer.isOpened()) {
        std::cerr << "Error: Could not create output video.\n";
        return 1;
    }

    cv::Mat frame;
    int frameCount = 0;

    // Start performance timer
    auto start = std::chrono::steady_clock::now();

    while (video.readFrame(frame)) {
        frameCount++;

        // Add frame number to the image
        cv::putText(
            frame,
            "Frame: " + std::to_string(frameCount),
            cv::Point(20, 40),
            cv::FONT_HERSHEY_SIMPLEX,
            1.0,
            cv::Scalar(0, 255, 0),
            2
        );

        // Add video timestamp
        double timestamp = frameCount / video.getFPS();

        cv::putText(
            frame,
            "Time: " + std::to_string(timestamp) + " s",
            cv::Point(20, 80),
            cv::FONT_HERSHEY_SIMPLEX,
            0.8,
            cv::Scalar(0, 255, 0),
            2
        );

        writer.writeFrame(frame);

        if(frameCount % 100 == 0) {
            std::cout << "Processed " << frameCount << " frames\n";
        }
        
    }

    // Stop performance timer
    auto end = std::chrono::steady_clock::now();

    // Calculate elapsed time in seconds
    std::chrono::duration<double> elapsed = end - start;

    double totalSeconds = elapsed.count();

    // Calculate processing FPS
    double processingFPS = frameCount / totalSeconds;

    // Print performace results
    std::cout << "\n--- Performace Results ---\n";

    std::cout << "Total time: " << totalSeconds << " seconds\n";

    std::cout << "Processing FPS: " << processingFPS << "\n";

    std::cout << "Finished processing " << frameCount << " frames.\n";

    return 0;
}