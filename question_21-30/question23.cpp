#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>

cv::Mat histogram_equalization(cv::Mat img);

int main(int argc, char const *argv[])
{
    if(argc != 2)
    {
        std::cout << "请输入正确的图像路径！";
        return 0;
    }
    cv::Mat image = imread(argv[1], cv::IMREAD_COLOR);
    cv::Mat out = histogram_equalization(image);
    imshow("image", image);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

cv::Mat histogram_equalization(cv::Mat img)
{
    int width = img.cols;
    int height = img.rows;
    int channels = img.channels();
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

    double Zmax = 255;
    double hist[255];
    int S = width * height * channels;
    int temp;
    double hist_sum = 0;

    // 初始化
    for (int i = 0; i < 255; i++)
    {
        hist[i] = 0; 
    }

    // 计算图片的像素分布
    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            for (int c = 0; c < channels; c++)
            {
                temp = (int)img.at<cv::Vec3b>(i, j)[c];
                hist[temp]++;
            }
        }
    }

    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            for (int c = 0; c < channels; c++)
            {
                // 计算累积分布， 将像素分布中小于当前像素的值相加
                temp = (int)img.at<cv::Vec3b>(i, j)[c];
                hist_sum = 0;
                for (int k = 0; k < temp; k++)
                {
                    hist_sum += hist[k];
                }
                out.at<cv::Vec3b>(i, j)[c] = Zmax / S * hist_sum;
            }
        }
    }
    return out;

}
