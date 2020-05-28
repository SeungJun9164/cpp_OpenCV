#include<opencv2/opencv.hpp>

int g_slider;
int g_slider_max;
void on_trackbar(int, void*) {
	//if (g_slider % 2 == 0)
		//g_slider += 1;
	std::cout << g_slider << "\n";
}
int main() {

	//Trackbar : �����̵��

	/* 
	cv::Mat T_img = cv::imread("Image2.jpg");
	cv::Mat img2;
	g_slider = 0;
	g_slider_max = 31;
	cv::namedWindow("My Window", 1);
	cv::createTrackbar("TrackbarName", "My Window", &g_slider, g_slider_max, on_trackbar);
	//createTrackbar(Ÿ��Ʋ,�۵��� �̹����̸�, ��ȭ�� ���� ���� ����, max��, �ݹ��Լ�)
	
	while (1) {
		cv::Sobel(T_img, img2, CV_8U, 1, 0, g_slider);
		//Sobel : �ܰ���(���� ���� �Լ�)
		cv::imshow("My Window", img2);

		int r = cv::waitKey(10);

		if (r > 0)
			break;
	}
	*/

	cv::Mat edges;
	cv::VideoCapture cap("Video2.mp4");


	if (!cap.isOpened()) return -1;

	g_slider = 0;
	g_slider_max = 255;
	cv::namedWindow("edges", 0);
	

	cv::createTrackbar("TrackbarName", "edges", &g_slider, g_slider_max, on_trackbar);

	cv::Mat frame;
	while (1) {
		cap.read(frame);
		cv::cvtColor(frame, edges, CV_BGR2GRAY);
		cv::GaussianBlur(edges, edges, cv::Size(7, 7), 1.5, 1.5);
		cv::Canny(edges, edges, g_slider, 30, 3);


		cv::imshow("edges",edges);
		if (cv::waitKey(30) >= 0)
			break;
	}


	////Binary Processing
	////Binary Image : 2���� �������� �̷���� �̹���(��,��)
	////threshold(�Ӱ谪) �̿� �Ӱ谪���� ������ 0, ũ�� 255
	////Histogram : �̹����� ��� ���� ���� �󵵼��� ��Ÿ�� �׷���
	//
	////threshold(�Է��̹���, ����̹���, �Ӱ谪, �ִ밪(�Ӱ谪���� Ŭ��� �̰����� ǥ��), Ÿ��)

	//cv::namedWindow("img", 0);
	//cv::namedWindow("binary", 0);

	//cv::Mat img = cv::imread("Image7.jpg");
	//cv::Mat gray, binary;
	//cv::cvtColor(img, gray, CV_RGB2GRAY); //������ 3ä���̴� ��������� �̷�� �ϱ����� ���ó���Ͽ� 2ä�η� ����
	//cv::threshold(gray, binary, 128, 255, CV_THRESH_BINARY);

	//cv::imshow("img", img);
	//cv::imshow("binary", binary);

	//cv::waitKey(0);


	////Ÿ�� 1 : THRESH_BINARY : �Ӱ谪���� ������ 0, ũ�� maxvalue
	////Ÿ�� 2 : THRESH_BINARY_INV : �Ӱ谪���� ������ maxvalue, ũ�� 0
	////Ÿ�� 3 : THRESH_TRUNC: �Ӱ谪���� ������ ������, ũ�� �Ӱ谪
	////Ÿ�� 4 : THRESH_TOZERO : �Ӱ谪���� ������ 0, ũ�� ������
	////Ÿ�� 5 : THRESH_TOZERO_INV : �Ӱ谪���� ������ ������, ũ�� 0
	return 0;
}