#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

void filter_sort(int *filter, int len);
cv::Mat median_filter(cv::Mat image, cv::Size size);

int main(int argc, char const *argv[])
{
    cv::Mat image = imread(argv[1], cv::IMREAD_COLOR);
    cv::Mat out = median_filter(image, cv::Size(3, 3));
    imshow("image", image);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

cv::Mat median_filter(cv::Mat image, cv::Size size)
{
    int width = image.cols;
    int height = image.rows;
    int channel = image.channels();

    // 创建中值卷积核
    int center = (size.width - 1) / 2;
    int len = size.height * size.width;
    int filter[len];

    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            for (int c = 0; c < channel; c++)
            {
                int count = 0;
                for (int _j = -center; _j < center + 1; _j++)
                {
                    for (int _i = -center; _i < center + 1; _i++)
                    {
                        if (((j + _j) >=0) && ((i + _i) >= 0))
                        {
                            filter[count++] = int(image.at<cv::Vec3b>(j + _j, i + _i)[c]);
                        }
                    }
                }
                filter_sort(filter, len);
                out.at<cv::Vec3b>(j, i)[c] = uchar(filter[(len + 1) / 2]);

                for (int num = 0; num < len; num++)
                {
                    filter[num] = 0;
                }
            }
        }
    }
    return out;
}

void filter_sort(int *filter, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (filter[j] >= filter[j + 1])
            {
                uchar temp = filter[j];
                filter[j] = filter[j + 1];
                filter[j + 1] = temp;
            }
        }
    }
}