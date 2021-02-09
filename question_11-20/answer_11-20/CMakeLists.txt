cmake_minimum_required(VERSION 3.0)

# 添加C++11标准
set(CMAKE_CXX_FLAGS "-std=c++11")

set(CMAKE_BUILD_TYPE Debug)

project(question_11-20)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(question11 question11.cpp)
target_link_libraries(question11 ${OpenCV_LIBS})

add_executable(question12 question12.cpp)
target_link_libraries(question12 ${OpenCV_LIBS})

add_executable(question13 question13.cpp)
target_link_libraries(question13 ${OpenCV_LIBS})

add_executable(question14 question14.cpp)
target_link_libraries(question14 ${OpenCV_LIBS})

add_executable(question15 question15.cpp)
target_link_libraries(question15 ${OpenCV_LIBS})


add_executable(test test.cpp)
target_link_libraries(test ${OpenCV_LIBS})