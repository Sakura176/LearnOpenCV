#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/***
 * @description: 最大池化，取网格内的最大值进行池化操作
 * @param image 输入的图像
 * @return Mat
 */
cv::Mat max_pooling(const cv::Mat &image);

int main(int argc, char const *argv[])
{
    cv::Mat image = imread(argv[1], cv::IMREAD_COLOR);
    cv::Mat out = max_pooling(image);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

cv::Mat max_pooling(const cv::Mat &image)
{
    cv::Mat img = image;

    // 获取图像的宽和高
    int width = img.cols;
    int height = img.rows;
    int channel = img.channels();

    // size_t 和 int 不能混用
    int r = 8;
    uchar MaxPixel = 0;
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            for (int c = 0; c < channel; c++)
            {
                for (int _j = 0; _j < r; _j++)
                    for (int _i = 0; _i < r; _i++)
                    {
                        MaxPixel = img.at<cv::Vec3b>(j + _j, i + _i)[c] > MaxPixel ? \
                            img.at<cv::Vec3b>(j + _j, i + _i)[c] : MaxPixel;
                    }

                for (int _j = 0; _j < r; _j++)
                    for (int _i = 0; _i < r; _i++)
                    {
                        img.at<cv::Vec3b>(j + _j, i + _i)[c] = MaxPixel;
                    }
                // 最大像素值归零，避免影响到下一通道   
                MaxPixel = 0; 
            }
            
            i += (r - 1);
            
        }
        j += (r - 1);
    }
    return img;
}