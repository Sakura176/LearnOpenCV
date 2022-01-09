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
    cv::Mat image = imread("./imori.jpg", cv::IMREAD_COLOR);
    // std::cout << image << std::endl;
    cv::Mat out = nn_interpolation(image, 1.5, 1.5);
    imshow("image", image);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
    return 0;
}

cv::Mat nn_interpolation(cv::Mat image, double ratio_x, double ratio_y)
{
    int width = image.cols;
    int height = image.rows;
    int channels = image.channels();

    int r_width = int(width * ratio_x) + 1;
    int r_height = int(height * ratio_y) + 1;
    int x, y;

    // std::cout << image.at<cv::Vec3d>(79, 127);
    cv::Mat out = cv::Mat::zeros(r_height, r_width, CV_8UC3);

    for (int j = 0; j < r_width; j++)
    {
        y = (int)round(j / ratio_y);
        y = fmin(y, width);

        for (int i = 0; i < r_height; i++)
        {
            x = (int)round(i / ratio_x);
            x = fmin(x, height);

            for (int c = 0; c < channels; c++)
            {
                std::cout << x << " " << y << std::endl;
                char temp = image.at<cv::Vec3d>(x, y)[c];
                out.at<cv::Vec3d>(i, j)[c] = temp;
            }
        }
    }
    return out;
}