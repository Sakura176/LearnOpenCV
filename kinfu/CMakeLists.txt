cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE "Release")
add_definitions("-DENABLE_SSE")

project(kinfu_demo)

find_package(OpenCV 4 REQUIRED)

include_directories(
        ${OpenCV_INCLUDE_DIRS})

add_executable(kinfu_demo kinfu_demo.cpp)

target_link_libraries(kinfu_demo ${OpenCV_LIBS})