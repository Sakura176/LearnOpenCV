#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#define change(pixel, value) pixel = (pixel < value && pixel >= value - 64) ? value - 32 : pixel 

cv::Mat decrease_color(const cv::Mat image);

int main(int argc, char const *argv[])
{
    cv::Mat image = imread(argv[1], cv::IMREAD_COLOR);
    cv::Mat out = decrease_color(image);
    imshow("out image", out);
    cv::waitKey(0);
    return 0;
}

cv::Mat decrease_color(const cv::Mat image)
{
    cv::Mat img = image;

    int width = img.cols;
    int height = img.rows;

    uchar r, g, b;
    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            r = img.at<cv::Vec3b>(j, i)[2];
            g = img.at<cv::Vec3b>(j, i)[1];
            b = img.at<cv::Vec3b>(j, i)[0];

            change(r, 64);
            change(g, 64);
            change(b, 64);

            change(r, 128);
            change(g, 128);
            change(b, 128);

            change(r, 192);
            change(g, 192);
            change(b, 192);

            change(r, 256);
            change(g, 256);
            change(b, 256);

            img.at<cv::Vec3b>(j, i)[2] = r;
            img.at<cv::Vec3b>(j, i)[1] = g;
            img.at<cv::Vec3b>(j, i)[0] = b;    
        }
    }
    return img;
}