/***
 * @description: 
 * @param {*}
 * @return {*}
 */


#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>


cv::Mat RGB2HSV(char const *img);
cv::Mat inverseHue(cv::Mat hsv);
cv::Mat HSV2RGB(cv::Mat hsv);

int main(int argc, char const *argv[])
{
    cv::Mat out = RGB2HSV(argv[1]);
    out = inverseHue(out);
    out = HSV2RGB(out);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
cv::Mat inverseHue(cv::Mat hsv)
{
    int height = hsv.rows;
    int width = hsv.cols;

    //cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            hsv.at<cv::Vec3b>(j, i)[0] = fmod(hsv.at<cv::Vec3b>(j, i)[0] + 180, 360);
        }
    }
    return hsv;
}

cv::Mat HSV2RGB(cv::Mat hsv)
{
    int height = hsv.rows;
    int width = hsv.cols;

    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

    float h, s, v;
    double c, _h, _x;
    double r, g, b;

    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            h = hsv.at<cv::Vec3b>(j, i)[0];
            s = hsv.at<cv::Vec3b>(j, i)[1];
            v = hsv.at<cv::Vec3b>(j, i)[2];

            c = s;
            _h = h / 60;
            _x = c * (1 - abs(fmod(_h, 2) - 1));

            r = g = b = v - c;
            if (_h < 1)
            {
                r += c;
                g += _x;
            }
            else if (_h < 2)
            {
                r += _x;
                g += c;
            }
            else if (_h < 3)
            {
                g += c;
                b += _x;
            }
            else if (_h < 4)
            {
                g += _x;
                b += c;
            }
            else if (_h < 5)
            {
                r += _x;
                b += c;
            }
            else if (_h < 6)
            {
                r += c;
                b += _x;
            }

            out.at<cv::Vec3b>(j, i)[0] = (uchar)b ;
            out.at<cv::Vec3b>(j, i)[1] = (uchar)g;
            out.at<cv::Vec3b>(j, i)[2] = (uchar)r;
        }
    }
    return out;
}

cv::Mat RGB2HSV(char const *input)
{
    cv::Mat img = imread(input, cv::IMREAD_COLOR);

    // 获取长和宽
    int height = img.rows;
    int width = img.cols;

    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

    //
    float max = 0, min = 0;
    float r, g, b;
    float h, s, v;
    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            r = (float)img.at<cv::Vec3b>(j, i)[2];
            g = (float)img.at<cv::Vec3b>(j, i)[1];
            b = (float)img.at<cv::Vec3b>(j, i)[0];
            max = b > g ? b : g;
            max = max > r ? max : r;

            min = b < g ? b : g;
            min = min < r ? min : r;

            if (min == max)
            {
                h = 0;
            }
            else if (min == b)
            {
                h = 60 * (g - r) / (max - min) + 60;
            }
            else if (min == r)
            {
                h = 60 * (b - g) / (max - min) + 180;
            }
            else
            {
                h = 60 * (r - b) / (max - min) + 300;
            }
            s = max - min;
            v = max;

            out.at<cv::Vec3b>(j, i)[0] = h;
            out.at<cv::Vec3b>(j, i)[1] = s;
            out.at<cv::Vec3b>(j, i)[2] = v;
        }
    }
    return out;
}