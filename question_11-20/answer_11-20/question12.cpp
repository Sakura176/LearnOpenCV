#include <iostream> 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

cv::Mat motion_filter(cv::Mat img, cv::Size ksize);

int main(int argc, const char* argv[])
{ 
    cv::Mat image = imread(argv[1], cv::IMREAD_COLOR);
    cv::Mat out = motion_filter(image, cv::Size(3, 3));
    imshow("image", image);
    imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

cv::Mat motion_filter(cv::Mat img , cv::Size ksize)
{
    int width = img.cols;
    int height = img.rows;
    int channel = img.channels();

    int center = (ksize.width - 1) / 2;
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            for (int c = 0; c < channel; c++)
            {
                int motion_mean = 0;
                for (int _j = -center; _j < center + 1; _j++)
                {
                    for (int _i = -center; _i <center + 1; _i++)
                    {
                        if (((j + _j) >= 0) && ((i + _i) >= 0) && (_j == _i))
                        {
                            motion_mean += int(img.at<cv::Vec3b>(j + _j, i + _i)[c]); 
                        }
                    }
                }
                motion_mean /= 3;
                out.at<cv::Vec3b>(j, i)[c] = uchar(motion_mean);
            }
        }
    }
    return out;
}