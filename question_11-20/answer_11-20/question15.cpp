#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

cv::Mat sobel_filter(cv::Mat image, cv::Size ksize, bool horzontal=true);

int main(int argc, char const *argv[])
{
    cv::Mat image = imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::Mat out = sobel_filter(image, cv::Size(3, 3), false);
    imshow("image", image);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

cv::Mat sobel_filter(cv::Mat image, cv::Size ksize, bool horzontal)
{
    int width = image.cols;
    int height = image.rows;

    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);
    // 如果将第六个常量改为1，图像会变清晰
    cv::Mat fliter = cv::Mat::zeros(ksize, CV_8SC1);
    fliter.at<char>(0, 0) = 1;
    fliter.at<char>(0, 1) = 2;
    fliter.at<char>(1, 2) = 1;
    fliter.at<char>(2, 0) = -1;
    fliter.at<char>(2, 1) = -2;
    fliter.at<char>(2, 2) = -1;
    
    int center = (ksize.height - 1) / 2;
    if (!horzontal)
    {
        fliter = fliter.t();
    }

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            double temp = 0;
            for (int _j = -center; _j < (center + 1); _j++)
            {
                for (int _i = -center; _i < (center + 1); _i++)
                {
                    if (((j + _j) >= 0) && ((i + _i) >= 0) && ((j + _j) < height) && ((i + _i) < width))
                    {
                        temp += image.at<uchar>(j + _j, i + _i) * fliter.at<char>(_j + center, _i + center);
                        
                    }
                }
            }
            temp = fmax(temp, 0);
            temp = fmin(temp, 255);
            out.at<uchar>(j, i) = uchar(temp);
        }
        
    }
    return out;
}
