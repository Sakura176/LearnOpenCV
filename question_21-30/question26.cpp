/*
 * @brief: 
 * @Autor: yc
 * @Date: 2022-07-13 20:50:23
 * @LastEditors: yc
 * @LastEditTime: 2022-07-14 11:19:23
 * @FilePath: /LearnOpenCV/question_21-30/question26.cpp
 */
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

cv::Mat bilinear_interpolation(cv::Mat image, double x_ratio, double y_ratio);

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

/**
 * @brief 双线性插值，相比最近邻速度更慢，但画质劣化情况要稍好
 * 
 * @param img 
 * @param x_ratio 
 * @param y_ratio 
 * @return cv::Mat 
 */
cv::Mat bilinear_interpolation(cv::Mat image, double x_ratio, double y_ratio){
	int width = image.cols;
    int height = image.rows;
    int channels = image.channels();

	// 定义输出图像变量
    int r_width = int(width * x_ratio);
    int r_height = int(height * y_ratio);
    int x, y;
	cv::Mat out = cv::Mat::zeros(r_height, r_width, CV_8UC3);

	for(int i = 0; i < r_height; i++){
		
		for(int j = 0; j < r_width; j++){

		}
	}
}