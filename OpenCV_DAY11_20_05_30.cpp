#include <opencv2/opencv.hpp>

int main() {

	//adaptive threshold : ������ ���� �������ϴ� ���
	//adaptive threshold(�Է�, ���, maxValue, �ɼ�(���, ����þ� ���Ժ���), Ÿ��, ����ũ��(Ȧ��), �����)

	cv::namedWindow("img", 0);
	cv::namedWindow("threshold", 0);
	cv::namedWindow("mean_thres", 0);
	cv::namedWindow("gauss_thres", 0);

	cv::Mat img = cv::imread("Image7.jpg");
	cv::Mat gray, binary, binary1, binary2;
	
	cv::cvtColor(img, gray, CV_RGB2GRAY);

	cv::threshold(gray, binary, 128, 255, CV_THRESH_BINARY);
	cv::adaptiveThreshold(gray, binary1, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 15, 5);
	cv::adaptiveThreshold(gray, binary2, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 15, 5);

	cv::imshow("img", img);
	cv::imshow("threshold", binary);
	cv::imshow("mean_thres", binary1);
	cv::imshow("gauss_thres", binary2);

	cv::waitKey(0);
	return 0;
}