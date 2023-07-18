#pragma once
#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>

/**
 * @brief 图像旋转函数
 * 
 * @param img 输入图像
 * @param rotate_angle 图像旋转角度
 * @return cv::Mat 旋转后的图像
 */
cv::Mat ImgRotate(const cv::Mat img, const int rotate_angle, cv::Mat& rotate_matrix);

cv::Point CalWrapAffine(const cv::Point point, const cv::Mat rotate_matrix);

std::vector<cv::Point> CalCorners(const cv::Mat img, const cv::Mat rotate_matrix);

/**
 * @brief 计算旋转后空白区域的掩码
 * TODO 使用更优的方法计算掩码
 * @param img 输入图像
 * @return cv::Mat 输出的掩码mask
 */
cv::Mat CalMask(const cv::Mat img);


/**
 * @brief 修补图像的空白区域
 * TODO 优化速度
 * @param img 输入图像
 * @param mask 需要修补的区域
 * @return cv::Mat 修补后的图像
 */
cv::Mat ImgInPaint(const cv::Mat img, const cv::Mat mask, const int radiu);

cv::Mat thresholding(const cv::Mat img);

int MyIpaint(const char* path, int radiu) {

	std::cout << path << std::endl;
	cv::Mat img = cv::imread(path);

	if (img.empty())
	{
		std::cout << "请输入正确的图片路径！！！" << std::endl;
		return -1;
	}
	cv::Mat rotate_matrix;
	cv::Mat rotate_img = ImgRotate(img, 5, rotate_matrix);

	cv::imwrite("./output/rotate_img.jpg", rotate_img);

	cv::Mat mask = CalMask(rotate_img);

	cv::imwrite("./output/mask.jpg", mask);

	cv::Mat inpaint = ImgInPaint(rotate_img, mask, radiu);

	cv::imwrite("./output/inpaint.jpg", inpaint);

	return 0;
}

int MyIpaint_fast(const char* path, int radiu) {

	std::cout << path << std::endl;
	cv::Mat img = cv::imread(path);

	if (img.empty())
	{
		std::cout << "请输入正确的图片路径！！！" << std::endl;
		return -1;
	}
	cv::Mat rotate_matrix;

	cv::Mat rotate_img = ImgRotate(img, 5, rotate_matrix);
	cv::imwrite("./output/rotate_img.jpg", rotate_img);



	// cv::Mat mask = CalMask(rotate_img);

	// cv::imwrite("./output/mask.jpg", mask);

	// cv::Mat inpaint = ImgInPaint(rotate_img, mask, radiu);

	// cv::imwrite("./output/inpaint.jpg", inpaint);

	return 0;
}

cv::Mat ImgRotate(const cv::Mat img, const int rotate_angle, cv::Mat& rotate_matrix) {

	// 获取图像中心
	cv::Point center((img.cols - 1) / 2.0, (img.rows - 1) / 2.0);

	// 创建旋转矩阵
	rotate_matrix = cv::getRotationMatrix2D(center, rotate_angle, 1.0);

	// 图片旋转
	cv::Mat rotate_img;
	cv::warpAffine(img, rotate_img, rotate_matrix, img.size(), cv::BORDER_REFLECT);

	return rotate_img;
}

cv::Point CalWrapAffine(const cv::Point point, const cv::Mat rotate_matrix)
{
	int x = rotate_matrix.at<uchar>(0, 0) * point.x 
			+ rotate_matrix.at<uchar>(1, 0) * point.y 
			+ rotate_matrix.at<uchar>(2, 0);
	int y = rotate_matrix.at<uchar>(0, 1) * point.x 
			+ rotate_matrix.at<uchar>(1, 1) * point.y 
			+ rotate_matrix.at<uchar>(2, 1);

	return cv::Point(x, y);
}

std::vector<cv::Point> CalCorners(const cv::Mat img, const cv::Mat rotate_matrix) {
	int width = img.cols;
	int height = img.rows;

	std::vector<cv::Point> corners;
	cv::Point left_up = CalWrapAffine(cv::Point(0, 0), rotate_matrix);
	corners.emplace_back(left_up);
	cv::Point right_up = CalWrapAffine(cv::Point(0, width - 1), rotate_matrix);
	corners.emplace_back(right_up);
	cv::Point left_bottom = CalWrapAffine(cv::Point(height - 1, 0), rotate_matrix);
	corners.emplace_back(left_bottom);
	cv::Point right_bottom = CalWrapAffine(cv::Point(height - 1, width - 1), rotate_matrix);
	corners.emplace_back(right_bottom);

	return corners;
}

cv::Mat CalMask(const cv::Mat img) {

	// 二值化图像
	cv::Mat img_out = cv::Mat::zeros(img.cols, img.rows, CV_8UC1);

	cv::cvtColor(img, img_out, cv::COLOR_BGR2GRAY);

	cv::Mat mask = thresholding(img_out);

	// cv::cvtColor(mask, mask, cv::COLOR_BGR2GRAY);

	return mask;
}

cv::Mat ImgInPaint(const cv::Mat img, const cv::Mat mask, const int radiu) {

	cv::Mat inpaint_img;
	cv::inpaint(img, mask, inpaint_img, radiu, cv::INPAINT_NS);

	return inpaint_img;
}

cv::Mat thresholding(const cv::Mat img)
{
    // 获取宽和高
    int width = img.cols;
    int height = img.rows;

    // 准备输出
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

    // 遍历像素
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
			// 大于128则设置为255
            if (img.at<uchar>(j, i) > 0)
                out.at<uchar>(j, i) = 0;
            else
                out.at<uchar>(j, i) = 255;
        }
    }
    return out;
}