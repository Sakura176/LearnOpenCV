#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

cv::Mat nn_interpolation(cv::Mat image, double ratio_x, double ratio_y);

int main(int argc, char const *argv[])
{
    // if (argc != 2)
    // {
    //     std::cout << "请输入正确的图像路径！";
    //     return 0;
    // }
    cv::Mat img = imread("../imori.jpg", cv::IMREAD_COLOR);
    // std::cout << image << std::endl;
    cv::Mat out = nn_interpolation(img, 1.5, 1.5);
    imshow("image", img);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
    return 0;
}


/**
 * @brief 最近邻插值，用于对图像进行上采样，速度较快，但画质会明显的劣化
 * 
 * @param image 输入图像
 * @param ratio_x x轴放大倍率
 * @param ratio_y y轴放大倍率
 * @return cv::Mat 放大后的图像
 */
cv::Mat nn_interpolation(cv::Mat image, double ratio_x, double ratio_y)
{
    int width = image.cols;
    int height = image.rows;
    int channels = image.channels();

    int r_width = int(width * ratio_x);
    int r_height = int(height * ratio_y);
    int x, y;

    // std::cout << r_width << "\t \t" << r_height << std::endl;
    // std::cout << image.at<cv::Vec3d>(79, 127);
    cv::Mat out = cv::Mat::zeros(r_height, r_width, CV_8UC3);

    for (int j = 0; j < r_width; j++)
    {
        y = (int)round(j / ratio_y);
        y = fmin(y, width-1);

        for (int i = 0; i < r_height; i++)
        {
            x = (int)round(i / ratio_x);
            x = fmin(x, height-1);

            for (int c = 0; c < channels; c++)
            {
                // std::cout << i << "\t \t" << j << std::endl;
                // std::cout << x << "\t \t" << y << std::endl;
                // char temp = image.at<cv::Vec3d>(x, y)[c];
                // std::cout << "temp: " << temp << std::endl;
                out.at<cv::Vec3b>(i, j)[c] = image.at<cv::Vec3b>(x, y)[c];
            }
        }
    }
    return out;
}