#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>

cv::Mat gamma_correction(cv::Mat image, int c = 1, double gamma = 2.2);

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "请输入正确的图像路径！";
        return 0;
    }
    cv::Mat image = imread(argv[1], cv::IMREAD_COLOR);
    cv::Mat out = gamma_correction(image, 128, 52);
    imshow("image", image);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

cv::Mat gamma_correction(cv::Mat image, int gamma_c, double gamma_g)
{
    int width = image.cols;
    int height = image.rows;
    int channels = image.channels();
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);
    double temp;

    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            for (int c = 0; c < channels; c++)
            {
                temp = (double)image.at<cv::Vec3b>(i, j)[c] / 255;
                out.at<cv::Vec3b>(i, j)[c] = (uchar)(pow(temp / gamma_c, 1 / gamma_g) * 255);
            }
        }
    }
    return out;
}