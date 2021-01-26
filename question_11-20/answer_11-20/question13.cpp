#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/***
 * @description: 使用冒泡排序对滤波器进行从大到小排序
 * @param *fil 滤波器数组
 * @param len  滤波器数组的大小
 * @return fil 滤波器数组
 */
int *filter_sort(int *fil, int len);

cv::Mat MAX_MIN_filter(cv::Mat image, cv::Size ksize);

int main(int argc, char const *argv[])
{
    cv::Mat image = imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::Mat out = MAX_MIN_filter(image, cv::Size(3, 3));
    imshow("image", image);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

int *filter_sort(int *fil, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (fil[i] < fil[j])
            {
                uchar temp = fil[i];
                fil[i] = fil[j];
                fil[j] = temp;
            }
        }
    }
    return fil;
}

cv::Mat MAX_MIN_filter(cv::Mat image, cv ::Size ksize)
{
    int width = image.cols;
    int height = image.rows;

    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);
    int len = ksize.width * ksize.height;
    int filter[len];
    int center = (ksize.width - 1) / 2;
    for (int i = 0; i < len; i++)
    {
        filter[i] = 0;
    }

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int count = 0;
            for (int _j = -center; _j < center + 1; _j++)
            {
                for (int _i = -center; _i < center + 1; _i++)
                {
                    if (((j + _j) >= 0) && ((i + _i) >= 0))
                    {
                        filter[count++] = int(image.at<uchar>(j + _j, i + _i));
                    }
                }
            }
            int *sortFilter = filter_sort(filter, ksize.width * ksize.height);
            for (int num = 0; num < len; num++)
            {
                std::cout << sortFilter[num] << ' ';
            }
            std::cout << std::endl;
            out.at<uchar>(j, i) = uchar(sortFilter[0] - sortFilter[ksize.width * ksize.height - 1]);
        }
    }
    return out;
}
