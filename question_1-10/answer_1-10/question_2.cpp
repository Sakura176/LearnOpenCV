#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/**
 * Mat RGB2Gray(const Mat &img)
 * @param img input image
 * comvert the RGB image to gray  
*/
Mat RGB2Gray(const Mat &img);

int main(int argc, char const *argv[])
{
    if(argc != 2)
    {
        cout << "请输入正确的图像路径！";
        return 0;
    }
    Mat img = imread(argv[1], cv::IMREAD_COLOR);

    Mat out = RGB2Gray(img);
    imshow("image", out);
    waitKey(0);
    return 0;
}

Mat RGB2Gray(const Mat &img)
{
    // 获取宽和高
    int width = img.cols;
    int height = img.rows;

    // 准备输出
    Mat out = cv::Mat::zeros(height, width, CV_8UC1);

    for(int i=0; i<width; ++i)
    {
        for(int j=0; j<height; ++j)
        {
            out.at<uchar>(i, j)= 0.2126 * img.at<cv::Vec3b>(i, j)[0]
                + 0.7152 * img.at<cv::Vec3b>(i, j)[1]
                + 0.0722 * img.at<cv::Vec3b>(i, j)[2];
        }
    }
    return out;
}
