# cmake版本限制
cmake_minimum_required(VERSION 3.0)

# 添加C++11标准
set(CMAKE_CXX_FLAGS "-std=c++11")

project(question_1-10)

# opencv
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(question_1 question_1.cpp)
# 链接OpenCV库
target_link_libraries(question_1 ${OpenCV_LIBS})

add_executable(question_2 question_2.cpp)
# 链接OpenCV库
target_link_libraries(question_2 ${OpenCV_LIBS})

add_executable(question_3 question_3.cpp)
# 链接OpenCV库
target_link_libraries(question_3 ${OpenCV_LIBS})

add_executable(question_4 question_4.cpp)
# 链接OpenCV库
target_link_libraries(question_4 ${OpenCV_LIBS})

add_executable(question_5 question_5.cpp)
# 链接OpenCV库
target_link_libraries(question_5 ${OpenCV_LIBS})

add_executable(question_6 question_6.cpp)
# 链接OpenCV库
target_link_libraries(question_6 ${OpenCV_LIBS})

add_executable(question_7 question_7.cpp)
# 链接OpenCV库
target_link_libraries(question_7 ${OpenCV_LIBS})

add_executable(question_8 question_8.cpp)
# 链接OpenCV库
target_link_libraries(question_8 ${OpenCV_LIBS})

add_executable(question_9 question_9.cpp)
# 链接OpenCV库
target_link_libraries(question_9 ${OpenCV_LIBS})

add_executable(question_10 question_10.cpp)
target_link_libraries(question_10 ${OpenCV_LIBS})

add_executable(test test.cpp)
# 链接OpenCV库
target_link_libraries(test ${OpenCV_LIBS})