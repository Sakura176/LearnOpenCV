#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>

cv::Mat hist_flat(cv::Mat img, int m, int s);

int main(int argc, char const *argv[])
{
    if(argc != 2)
    {
        std::cout << "请输入正确的图像路径！";
        return 0;
    }
    cv::Mat image = imread(argv[1], cv::IMREAD_COLOR);
    cv::Mat out = hist_flat(image, 128, 52);
    imshow("image", image);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

cv::Mat hist_flat(cv::Mat img, int m0, int s0)
{
    int width = img.cols;
    int height = img.rows;
    int channel = img.channels();
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);
    int sum = 0;
    int m = 0;
    int s_sum = 0;
    int s = 0;

    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            for (int c = 0; c < channel; c++)
            {
                sum += img.at<cv::Vec3b>(i, j)[c]; 
            }
        }
    }
    m = sum / (width * height * channel);

    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            for (int c = 0; c < channel; c++)
            {
                s_sum += pow(img.at<cv::Vec3b>(i, j)[c] - m, 2); 
            }
        }
    }
    s = sqrt(s_sum / (width * height * channel));

    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            for (int c = 0; c < channel; c++)
            {
                out.at<cv::Vec3b>(i, j)[c] = (s0 / s) * (img.at<cv::Vec3b>(i, j)[c] - m) + m0; 
            }
        }
    }
    return out;
}