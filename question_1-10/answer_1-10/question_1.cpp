#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <chrono>

using namespace std;
using namespace cv;

/**
 * Mat RGB2BGR(const Mat img)
 * @param img input image
*/
Mat RGB2BGR(const char* image)
{
    Mat img = imread(image, cv::IMREAD_COLOR);
    Mat imgs[3];
    cv::split(img, imgs);

    Mat temp = imgs[0];
    imgs[0] = imgs[2];
    imgs[2] = temp;

    cv::merge(imgs, 3, img);
    return img;
}

Mat channelSwap(const char* image)
{
    Mat img = imread(image, cv::IMREAD_COLOR);

    // 获取宽和高
    int width = img.cols;
    int height = img.rows;

    // 准备输出
    Mat out = cv::Mat::zeros(height, width, CV_8UC3);

    // 遍历像素
    for(int y=0; y < height; ++y)
    {
        for(int x=0; x < width; ++x)
        {
            out.at<cv::Vec3b>(y, x)[0] = img.at<cv::Vec3b>(y, x)[2];
            out.at<cv::Vec3b>(y, x)[2] = img.at<cv::Vec3b>(y, x)[0];
            out.at<cv::Vec3b>(y, x)[1] = img.at<cv::Vec3b>(y, x)[1];
        }
    }
    return out;
}

int main(int argc, char const *argv[])
{
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    Mat img = RGB2BGR(argv[1]);
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>(t2 -t1);
    cout << "using " << time_used.count() << " second." << endl;

    imshow("BGR img", img);
    waitKey(0);

    return 0;
}
