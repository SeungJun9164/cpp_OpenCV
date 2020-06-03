//Otsu method : 자동으로 임계값 지정
//threshold(Mat,0,255,THRESH_BINARY+THRESH_OTSU)

#include <opencv2/opencv.hpp>

int main() {
	cv::namedWindow("img", 0);
	cv::namedWindow("binary", 0);

	cv::Mat img = cv::imread("image2.jpg");

	cv::Mat gray, binary, binary_th, binary_ad;
	cv::cvtColor(img, gray, CV_RGB2GRAY);

	cv::threshold(gray, binary_th, 128, 255, CV_THRESH_BINARY);
	cv::adaptiveThreshold(gray, binary_ad, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 9, 5);
	cv::GaussianBlur(gray, gray, cv::Size(7, 7), 0);
	cv::threshold(gray, binary, 0, 255, CV_THRESH_BINARY + cv::THRESH_OTSU);

	cv::imshow("img", img);
	cv::imshow("otsu", binary);
	cv::imshow("binary_th", binary_th);
	cv::imshow("binary_ad", binary_ad);

	cv::waitKey(0);
}