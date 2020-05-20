#include<opencv2/opencv.hpp>
#include<vector>

int main() {
	//타원 그리기
	cv::Mat img(500, 500, CV_8UC3);
	img.setTo(255);
	/*
	cv::ellipse(img, cv::Point(100, 100), cv::Size(100, 50), 0, 0, 360, CV_RGB(255, 0, 0));
	cv::ellipse(img, cv::Point(100, 100), cv::Size(100, 50), 30, 0, 360, CV_RGB(0, 255, 0));
	cv::ellipse(img, cv::Point(100, 100), cv::Size(100, 50), 60, 0, 360, CV_RGB(0, 0, 255));
	//mat,원의 중심좌표,(타원의 장축, 단축),타원을 회전 시킬 각도, 타원이 그려질 시작 각도, 타원이 끝날 각도, 색상

	cv::ellipse(img, cv::Point(100, 100), cv::Size(100, 50), 0, 0, 180, CV_RGB(255, 0, 0));
	cv::ellipse(img, cv::Point(100, 100), cv::Size(100, 50), 30, 0, 270, CV_RGB(0, 255, 0));
	cv::ellipse(img, cv::Point(100, 100), cv::Size(100, 50), 60, 0, 360, CV_RGB(0, 0, 255));

	imshow("show2", img);
	cv::waitKey(0);

	//타원그리기2
	cv::RotatedRect rRect = cv::RotatedRect(cv::Point2f(300, 300), cv::Size2f(300, 100), 30);
	//RotatedRect : 사각형을 회전 /사각형 중심좌표,사이즈,회전각도
	cv::ellipse(img, rRect, CV_RGB(255, 0, 0));
	//사각형안에 들어가있는 타원형

	cv::Point2f vertices[4];
	rRect.points(vertices);
	for (int i = 0; i < 4; i++)
		cv::line(img, vertices[i], vertices[(i + 1) % 4], cv::Scalar(0, 255, 0));

	cv::Rect brect = rRect.boundingRect();//boundingRect : 회전된 사각형을 감싸는 사각형
	cv::rectangle(img, brect, cv::Scalar(255, 0, 0));

	imshow("show2", img);
	cv::waitKey(0);*/

	//polyline : 여러개의 점들을 이어서 선을 긋는것

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
	//&npts : 점의 갯수 / 1 : 그린 폴리라인 갯수 /false,true : 끝과 시작점을 이을 것인지
	cv::polylines(img, &pts, &npts, 1, false, cv::Scalar(0, 255, 0));

	imshow("show2", img);
	cv::waitKey(0);
	
	//fillconvexPoly : 안에가 채워진 폴리라인
	cv::Point pt[4];
	pt[0] = cv::Point(100, 100);
	pt[1] = cv::Point(150, 200);
	pt[2] = cv::Point(300, 300);
	pt[3] = cv::Point(400, 100);

	cv::fillConvexPoly(img, pt, 4, cv::Scalar(0, 0, 200));
	imshow("show2", img);
	cv::waitKey(0);
}