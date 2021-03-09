#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/***
 * @description: 高斯-拉普拉斯滤波器,高斯滤波器使图像平滑化，拉普拉斯滤波器使图像的轮廓更加清晰
 * @param Mat image
 * @param Size ksize 
 * @return 
 */
cv::Mat LoG_filter(cv::Mat image, cv::Size ksize);

int main(int argc, char const *argv[])
{
    cv::Mat image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::Mat out = LoG_filter(image, cv::Size(3, 3));
    imshow("image", image);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

cv::Mat LoG_filter(cv::Mat image, cv::Size ksize)
{
    int width = image.cols;
    int height = image.rows;
    int channel = image.channels();

    int center = (ksize.height - 1) / 2;
    int sigma = 3;
    float sum = 0;
    // 准备滤波器模版
    cv::Mat fliter = cv::Mat::zeros(ksize, CV_32FC1);

    for (int j = 0; j < ksize.height; j++)
    {
        for (int i = 0; i < ksize.width; i++)
        {
            float z = pow((i - center), 2) + pow((j - center), 2);
            fliter.at<float>(j, i) = float((z - pow(sigma, 2)) / (2 * CV_PI * pow(sigma, 6)) *
                                           exp(-z / (2 * pow(sigma, 2))));
            sum += fliter.at<float>(j, i);
        }
    }

    fliter = fliter / sum;
    for (int j = 0; j < ksize.height; j++)
    {
        for (int i = 0; i < ksize.width; i++)
        {
            std::cout << fliter.at<float>(j, i) << "  ";
        }
        std::cout << std::endl;
    }
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            double temp = 0;
            for (int _j = -center; _j < center + 1; _j++)
            {
                for (int _i = -center; _i < center + 1; _i++)
                {
                    if (((j + _j) >= 0) && ((i + _i) >= 0))
                    {
                        temp += double(image.at<uchar>(j + _j, i + _i) *
                                       fliter.at<float>(_j + center, _i + center));
                    }
                }
            }
            out.at<uchar>(j, i) = temp;
        }
    }
    return out;
}