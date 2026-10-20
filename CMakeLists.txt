cmake_minimum_required(VERSION 3.16)

project(RealTimePerceptionSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

add_executable(perception 
    src/main.cpp
    src/video_reader.cpp
    src/video_writer.cpp
)

target_include_directories(perception PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(perception PRIVATE ${OpenCV_LIBS})