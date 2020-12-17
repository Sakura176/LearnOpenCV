#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <chrono>

cv::Mat OtsuMethod(const cv::Mat img)
{
    // 读取图片的宽和高
    int height = img.rows;
    int width = img.cols;

    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

    // 第一步：将图片转为灰度图片
    int val = 0;
    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            val = img.at<cv::Vec3b>(j, i)[2] * 0.2126 +\
                  img.at<cv::Vec3b>(j, i)[1] * 0.7152 +\
                  img.at<cv::Vec3b>(j, i)[0] * 0.0722;
            out.at<uchar>(j, i) = uchar(val);
        }
    }
    // 第二步：计算灰度阈值
    double w0 = 0, w1 = 0;
    double m0 = 0, m1 = 0;
    double max_sb = 0, sb = 0;
    int threshold = 0;

    for (int t = 0; t < 255; t++)
    {
        w0 = 0;
        w1 = 0;
        m0 = 0;
        m1 = 0;
        for (int j = 0; j < height; j++)
        {
            for (int i = 0; i < width; i++)
            {
                val = (int)(out.at<uchar>(j, i));

                if (val < t)
                {
                    w0++;
                    m0 += val;
                }
                else
                {
                    w1++;
                    m1 += val;
                }
            }
        }

        m0 /= w0;
        m1 /= w1;
        w0 /= (height * width);
        w1 /= (height * width);
        sb = w0 * w1 * pow((m0 - m1), 2);

        if (sb > max_sb)
        {
            max_sb = sb;
            threshold = t;
        }
    }

    // binalization
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            val = (int)(out.at<uchar>(j, i));
            if (val < threshold)
            {
                val = 0;
            }
            else
            {
                val = 255;
            }
            out.at<uchar>(j, i) = (uchar)val;
        }
    }

    std::cout << "threshold >> " << threshold << std::endl;

    return out;
}

int main(int argc, char const *argv[])
{
    cv::Mat img = imread(argv[1], cv::IMREAD_COLOR);
    cv::imshow("in", img);

    cv::Mat out = OtsuMethod(img);
    cv::imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
