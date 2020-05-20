#include<opencv2/opencv.hpp>
#include<vector>

int main() {
	//Ÿ�� �׸���
	cv::Mat img(500, 500, CV_8UC3);
	img.setTo(255);
	/*
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
	cv::waitKey(0);*/

	//polyline : �������� ������ �̾ ���� �ߴ°�

	std::vector<cv::Point> contour;
	contour.push_back(cv::Point(50, 50));
	contour.push_back(cv::Point(300, 50));
	contour.push_back(cv::Point(350, 200));
	contour.push_back(cv::Point(300, 150));
	contour.push_back(cv::Point(150, 350));
	contour.push_back(cv::Point(100, 100));

	const cv::Point* pts = (const cv::Point*) cv::Mat(contour).data;
	int npts = cv::Mat(contour).rows;

	std::cout << "Number of polygon vertices : " << npts << std::endl;
	//&npts : ���� ���� / 1 : �׸� �������� ���� /false,true : ���� �������� ���� ������
	cv::polylines(img, &pts, &npts, 1, false, cv::Scalar(0, 255, 0));

	imshow("show2", img);
	cv::waitKey(0);
	
	//fillconvexPoly : �ȿ��� ä���� ��������
	cv::Point pt[4];
	pt[0] = cv::Point(100, 100);
	pt[1] = cv::Point(150, 200);
	pt[2] = cv::Point(300, 300);
	pt[3] = cv::Point(400, 100);

	cv::fillConvexPoly(img, pt, 4, cv::Scalar(0, 0, 200));
	imshow("show2", img);
	cv::waitKey(0);
}