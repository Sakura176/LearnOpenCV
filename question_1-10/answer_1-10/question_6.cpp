#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

cv::Mat decrease_color(const cv::Mat image);

int main(int argc, char const *argv[])
{
    cv::Mat image = imread(argv[1], cv::IMREAD_COLOR);
    cv::Mat out = decrease_color(image);
    imshow("out image", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

cv::Mat decrease_color(const cv::Mat image)
{
    cv::Mat img = image;

    int width = img.cols;
    int height = img.rows;
    int channel = img.channels();

    uchar temp;
    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            for (int c = 0; c < channel; ++c)
            {
                temp = img.at<cv::Vec3b>(j, i)[c];
                img.at<cv::Vec3b>(j, i)[c] = (temp / 64) * 64 + 32;
            }
        }
    }
    return img;
}