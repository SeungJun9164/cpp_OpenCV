#include<opencv2/opencv.hpp>

int main() {
	cv::Mat img(500, 500, CV_8UC3);
	img.setTo(255); //����� ��� ����

	cv::Point pt(300, 300);
	line(img, cv::Point(10, 10), pt, CV_RGB(255, 0, 0), 2); // 10,10���� �����Ͽ� 300,300���� ���� ���� / CV_RGB(��), ���� ����
	line(img, cv::Point(300, 10), cv::Point(30,300), cv::Scalar(255, 0, 0), 2); // 300,10���� 30,300���� / Scalar : ����(B,G,R)

	imshow("show2", img);
	cv::waitKey(0);

	circle(img, cv::Point(250, 250), 100, CV_RGB(0, 255, 0), 3);
	cv::Point center(400, 400);
	circle(img, center, 300, cv::Scalar(255, 255, 0), 10);
	circle(img, cv::Point(40, 40), 10, cv::Scalar(200, 0, 0), -1); // -1 : ���� ���� ���� ä���ֱ� 

	imshow("show2", img);
	cv::waitKey(0);

	cv::rectangle(img, cv::Rect(10, 10, 200, 200), CV_RGB(255, 0, 0), 2); // x,y,width,height
	cv::rectangle(img, cv::Rect(cv::Point(40, 40), cv::Point(400, 400)), cv::Scalar(255, 0, 0), 10);

	imshow("show2", img);
	cv::waitKey(0);
}

