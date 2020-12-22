/***
 * @Author: 不摇碧莲
 * @Date: 2020-12-18 16:43:20
 * @LastEditTime: 2020-12-18 16:51:14
 * @LastEditors: 不摇碧莲
 * @Description: 
 * @FilePath: /LearnOpenCV/question_1-10/answer_1-10/test.cpp
 * @
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
    system("color F0");
    VideoCapture video(0);
    if(video.isOpened())
    {
        cout << "视频中图像的宽度=" << video.get(CAP_PROP_FRAME_WIDTH) << endl;
    }
    while(1)
    {
        Mat frame;
        video >> frame;
        if(frame.empty())
        {
            break;
        }
        imshow("video", frame);
        waitKey(1000 / video.get(CAP_PROP_FPS));
    }
    waitKey(0);
    return 0;
}
