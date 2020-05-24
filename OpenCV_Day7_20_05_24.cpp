#include <opencv2/opencv.hpp>

int main() {
	//채널이 같아야 한다.
	/*cv::Mat leftCircle = cv::Mat(500, 1000, CV_8UC1);
	cv::Mat rightCircle = cv::Mat(500, 1000, CV_8UC1);
	leftCircle.setTo(0);
	rightCircle.setTo(0);

	cv::circle(leftCircle, cv::Point(1000 / 5 * 2, 500 / 2), 250, CV_RGB(255, 255, 255), CV_FILLED);
	cv::circle(rightCircle, cv::Point(1000 / 5 * 3, 500 / 2), 250, CV_RGB(255, 255, 255), CV_FILLED);
	
	cv::Mat res;
	cv::bitwise_and(leftCircle, rightCircle, res);	cv::imshow("AND", res);
	cv::bitwise_or(leftCircle, rightCircle, res);	cv::imshow("OR", res);
	cv::bitwise_xor(leftCircle, rightCircle, res);	cv::imshow("XOR", res);
	cv::bitwise_not(leftCircle, res);	cv::imshow("NOT", res);
	
	cv::imshow("leftCircle", leftCircle);
	cv::imshow("rightCircle", rightCircle);
	*/
	cv::Mat img = cv::imread("image2.jpg");
	cv::Mat img_Mask = cv::Mat(img.rows, img.cols, img.type()); //img의 행,열,타입을 모두 같게 설정
	img_Mask.setTo(0);
	circle(img_Mask, cv::Point(600 / 5 * 2, 500 / 2), 250, CV_RGB(255, 255, 255), CV_FILLED);

	cv::Mat res;
	cv::bitwise_and(img, img_Mask, res);	cv::imshow("AND", res);
	cv::bitwise_or(img, img_Mask, res);	cv::imshow("OR", res);
	cv::bitwise_xor(img, img_Mask, res);	cv::imshow("XOR", res);
	cv::bitwise_not(img, res);	cv::imshow("NOT", res);




	cv::imshow("img_Mask", img_Mask);
	cv::imshow("img", img);

	cv::waitKey(0);
	return 0;
}