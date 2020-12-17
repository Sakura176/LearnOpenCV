#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/**
 * Mat thresholding(const Mat &img)
 * @param img input image
 * 将图像用黑白两种颜色表示
*/
Mat thresholding(const Mat &img);

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cout << "请输入一张图像的路径！" << endl;
        return 0;
    }

    Mat img = imread(argv[1], 0);
    assert(img.data != nullptr);

    imshow("input", img);

    Mat out = thresholding(img);
    imshow("output", out);
    waitKey(0);
    return 0;
}

Mat thresholding(const Mat &img)
{
    // 获取宽和高
    int width = img.cols;
    int height = img.rows;

    // 准备输出
    Mat out = cv::Mat::zeros(height, width, CV_8UC1);

    // 遍历像素
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            if (img.at<uchar>(i, j) > 128)
                out.at<uchar>(i, j) = 255;
            else
                out.at<uchar>(i, j) = 0;
        }
    }
    return out;
}