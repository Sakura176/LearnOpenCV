#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/***
 * @description: 对图片进行池化操作，将网格内的像素值全部改为网格像素的平均值
 * @param image 输入的图像
 * @return Mat
 * TODO 函数无法自适应不同大小的图片，图片大小必须是网格大小的倍数
 */
cv::Mat mean_pooling(const cv::Mat &image);

int main(int argc, char const *argv[])
{
    cv::Mat image = imread(argv[1], cv::IMREAD_COLOR);
    cv::Mat out = mean_pooling(image);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

cv::Mat mean_pooling(const cv::Mat &image)
{
    cv::Mat img = image;

    // 读取图片的长和宽，以及图像的通道
    int width = img.cols;
    int height = img.rows;
    int channel = img.channels();

    // 循环遍历各个通道的所有像素
    int r = 8;
    double v = 0;
    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            for (int c = 0; c < channel; ++c)
            {
                // 计算 r * r 大小的网格内像素的和
                for (size_t _j = 0; _j < r; _j++)
                {
                    for (size_t _i = 0; _i < r; _i++)
                    {
                        v += (img.at<cv::Vec3b>(j + _j, i + _i)[c]);
                    }
                }

                // 计算网格内像素的平均值
                v = v / (r * r);

                // 将网格内的像素点的值都改为平均值
                for (size_t _j = 0; _j < r; _j++)
                {
                    for (size_t _i = 0; _i < r; _i++)
                    {
                        img.at<cv::Vec3b>(j + _j, i + _i)[c] = v;
                    }
                }
            }
            // 跳过被修改的像素点
            i += (r - 1);
        }
        j += (r - 1);
    }
    return img;
}