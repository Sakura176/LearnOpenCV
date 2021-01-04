cmake_minimum_required(VERSION 3.0)

# 添加C++11标准
set(CMAKE_CXX_FLAGS "-std=c++11")

project(question_11-20)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(question11 question11.cpp)
target_link_libraries(question11 ${OpenCV_LIBS})