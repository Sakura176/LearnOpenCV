#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>

// cv::Mat hist(cv::Mat image);

cv::Mat hist_normal(cv::Mat image, int a, int b);

int main(int argc, char const *argv[])
{
    cv::Mat image = imread(argv[1], cv::IMREAD_COLOR);
    cv::Mat out = hist_normal(image, 0, 255);
    imshow("image", image);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

cv::Mat hist_normal(cv::Mat image, int a, int b)
{
    int c, d;
    int temp;
    int width = image.cols;
    int height = image.rows;
    int channel = image.channels();
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            for (int k = 0; k < channel; k++)
            {
                temp = (float)image.at<cv::Vec3d>(i, j)[k];
                c = fmin(c, temp);
                d = fmax(d, temp);
            }
        }
    }

    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            for (int k = 0; k < channel; k++)
            {
                temp = image.at<cv::Vec3d>(i, j)[k];
                if (temp < a)
                {
                    out.at<cv::Vec3d>(i, j)[k] = (uchar)a;
                }
                else if (temp <= b)
                {
                    out.at<cv::Vec3d>(i, j)[k] = (uchar)(b - a) / (d - c) * (temp - c) + a;
                }
                else
                {
                    out.at<cv::Vec3d>(i, j)[k] = (uchar)b;
                }
            }
        }
    }
    return out;
}

// cv::Mat hist(cv::Mat image)
// {
//     int channel = image.channels();

//     cv::Mat gray;
//     if (channel == 3)
//     {
//         cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//     }
//     gray = image;
//     // 设置提取直方图的相关变量
//     cv::Mat hist;                // 用于存放直方图计算结果
//     const int channels[1] = {0}; // 通道索引
//     float inRanges[2] = {0, 255};
//     const float *ranges[1] = {inRanges};                                // 像素灰度值范围
//     const int bins[1] = {256};                                          // 直方图的维度， 其实就是像素灰度值的最大值
//     cv::calcHist(&gray, 1, channels, cv::Mat(), hist, 1, bins, ranges); // 计算图像直方图

//     // 准备绘制直方图
//     int hist_w = 512;
//     int hist_h = 400;
//     int width = 2;
//     cv::Mat histImage = cv::Mat::zeros(hist_h, hist_w, CV_8UC3);
//     for (int i = 1; i <= hist.rows; i++)
//     {
//         cv::rectangle(histImage, cv::Point(width * (i - 1), hist_h - 1),
//                       cv::Point(width * i - 1, hist_h - cvRound(hist.at<float>(i - 1) / 15)),
//                       cv::Scalar(255, 255, 255), -1);
//     }
//     return histImage;
// }