#include<opencv2/opencv.hpp>

int main() {
	//Ÿ�� �׸���
	cv::Mat img(500, 500, CV_8UC3);
	img.setTo(255);
	cv::ellipse(img, cv::Point(100, 100), cv::Size(100, 50), 0, 0, 360, CV_RGB(255, 0, 0));
	cv::ellipse(img, cv::Point(100, 100), cv::Size(100, 50), 30, 0, 360, CV_RGB(0, 255, 0));
	cv::ellipse(img, cv::Point(100, 100), cv::Size(100, 50), 60, 0, 360, CV_RGB(0, 0, 255));
	//mat,���� �߽���ǥ,(Ÿ���� ����, ����),Ÿ���� ȸ�� ��ų ����, Ÿ���� �׷��� ���� ����, Ÿ���� ���� ����, ����

	cv::ellipse(img, cv::Point(100, 100), cv::Size(100, 50), 0, 0, 180, CV_RGB(255, 0, 0));
	cv::ellipse(img, cv::Point(100, 100), cv::Size(100, 50), 30, 0, 270, CV_RGB(0, 255, 0));
	cv::ellipse(img, cv::Point(100, 100), cv::Size(100, 50), 60, 0, 360, CV_RGB(0, 0, 255));

	imshow("show2", img);
	cv::waitKey(0);

	//Ÿ���׸���2
	cv::RotatedRect rRect = cv::RotatedRect(cv::Point2f(300, 300), cv::Size2f(300, 100), 30);
	//RotatedRect : �簢���� ȸ�� /�簢�� �߽���ǥ,������,ȸ������
	cv::ellipse(img, rRect, CV_RGB(255, 0, 0));
	//�簢���ȿ� ���ִ� Ÿ����

	cv::Point2f vertices[4];
	rRect.points(vertices);
	for (int i = 0; i < 4; i++)
		cv::line(img, vertices[i], vertices[(i + 1) % 4], cv::Scalar(0, 255, 0));

	cv::Rect brect = rRect.boundingRect();//boundingRect : ȸ���� �簢���� ���δ� �簢��
	cv::rectangle(img, brect, cv::Scalar(255, 0, 0));

	imshow("show2", img);
	cv::waitKey(0);
}