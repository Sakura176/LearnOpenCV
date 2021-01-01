#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/***
 * @description: 高斯滤波可以使图像平滑，用于去除噪声
 * @param Mat 输入图像
 * @param Size 卷积核的大小
 * @return Mat
 * Step 1 准备卷积核模板
 * Step 2 对图像进行卷积操作
 * 注意事项，在读取图像数据时，使用at方法必须严格注意数据类型，不同的类型读取方式对结果影响极大
 */
cv::Mat GaussianFilter(cv::Mat &image, double sigma, cv::Size ksize);

int main(int argc, char const *argv[])
{
    cv::Mat image = imread(argv[1], cv::IMREAD_COLOR);
    cv::Mat out = GaussianFilter(image, 1.3, cv::Size(3, 3));
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

cv::Mat GaussianFilter(cv::Mat &image, double sigma, cv::Size ksize)
{
    cv::Mat img = image;

    int width = img.cols;
    int height = img.rows;
    int channel = img.channels();

    // Step 生成卷积核模板
    // 获取卷积核中心点的坐标
    int center = (ksize.width - 1) / 2;
    // 计算sigma的平方
    float sigma_2 = pow(sigma, 2);
    float sum = 0;
    // 定义卷积核， 数据类型很重要
    cv::Mat filter(ksize, CV_32FC1);
    // 计算卷积核每个点的值
    for (int j = 0; j < ksize.height; j++)
    {
        for (int i = 0; i < ksize.width; i++)
        {
            float sqr = pow((j - center), 2) + pow((i - center), 2);
            filter.at<float>(j, i) = float(1 / (2 * M_PI * sigma_2) *
                                           exp(-sqr / (2 * sigma_2)));
            sum += filter.at<float>(j, i);
        }
    }
    // 小数模板，将每个值除以卷积核总和
    filter = filter / sum;
    // 整数模板
    //filter = filter * (1.0 / filter.at<float>(0, 0));

    for (int j = 0; j < ksize.height; j++)
    {
        for (int i = 0; i < ksize.width; i++)
        {
            std::cout << filter.at<float>(j, i) << "  ";
        }
        std::cout << std::endl;
    }

    // Step 对图像进行卷积操作
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);
    double cal;
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            for (int c = 0; c < channel; c++)
            {
                cal = 0;
                for (int _j = -center; _j < center + 1; _j++)
                {
                    for (int _i = -center; _i < center + 1; _i++)
                    {
                        if (((j + _j) >= 0) && ((i + _i) >= 0))
                        {
                            cal += double(img.at<cv::Vec3b>(j + _j, i + _i)[c] * filter.at<float>(_j + center, _i + center));
                        }
                    }
                }
                // ? 左值为uchar类型，右值为double类型，没出现问题？
                out.at<cv::Vec3b>(j, i)[c] = cal;
            }
        }
    }
    return out;
}