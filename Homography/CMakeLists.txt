cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE "Release")
add_definitions("-DENABLE_SSE")

project(homography)

find_package(OpenCV 4 REQUIRED)

include_directories(
        ${OpenCV_INCLUDE_DIRS})

add_executable(homography virtual-billboard.cpp)

target_link_libraries(homography ${OpenCV_LIBS})