#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

cv::Mat mean_filter(cv::Mat image, cv::Size ksize);

int main(int argc, char const *argv[])
{
    cv::Mat image = imread(argv[1], cv::IMREAD_COLOR);
    cv::Mat out = mean_filter(image, cv::Size(3, 3));
    cv::imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

cv::Mat mean_filter(cv::Mat image, cv::Size ksize)
{
    int width = image.cols;
    int height = image.rows;
    int channel = image.channels();

    int center = (ksize.width - 1) / 2;
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);
    double sum = 0;

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            for (int c = 0; c < channel; c++)
            {
                sum = 0;
                //double mean_value = 0;
                for (int _j = -center; _j < center + 1; _j++)
                {
                    for (int _i = -center; _i < center + 1; _i++)
                    {
                        if (((j + _j) >= 0) && ((i + _i) >= 0))
                        {
                            sum += int(image.at<cv::Vec3b>(j + _j, i + _i)[c]);
                        }
                    }
                }
                sum /= (ksize.width * ksize.height);
                out.at<cv::Vec3b>(j, i)[c] = uchar(sum);
            }
        }
    }
    return out;
}
