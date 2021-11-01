cmake_minimum_required(VERSION 3.0)

# 添加C++11标准
set(CMAKE_CXX_FLAGS "-std=c++11")

set(CMAKE_BUILD_TYPE Debug)

project(question_21-30)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(question21 question21.cpp)
target_link_libraries(question21 ${OpenCV_LIBS})

add_executable(question22 question22.cpp)
target_link_libraries(question22 ${OpenCV_LIBS})

add_executable(question23 question23.cpp)
target_link_libraries(question23 ${OpenCV_LIBS})

add_executable(question24 question24.cpp)
target_link_libraries(question24 ${OpenCV_LIBS})

# add_executable(question15 question15.cpp)
# target_link_libraries(question15 ${OpenCV_LIBS})

# add_executable(question16 question16.cpp)
# target_link_libraries(question16 ${OpenCV_LIBS})

# add_executable(question17 question17.cpp)
# target_link_libraries(question17 ${OpenCV_LIBS})

# add_executable(question18 question18.cpp)
# target_link_libraries(question18 ${OpenCV_LIBS})

# add_executable(question19 question19.cpp)
# target_link_libraries(question19 ${OpenCV_LIBS})

# add_executable(question20 question20.cpp)
# target_link_libraries(question20 ${OpenCV_LIBS})

# add_executable(test test.cpp)
# target_link_libraries(test ${OpenCV_LIBS})