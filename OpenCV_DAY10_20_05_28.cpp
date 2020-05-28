#include<opencv2/opencv.hpp>

int g_slider;
int g_slider_max;
void on_trackbar(int, void*) {
	//if (g_slider % 2 == 0)
		//g_slider += 1;
	std::cout << g_slider << "\n";
}
int main() {

	//Trackbar : 슬라이드바

	/* 
	cv::Mat T_img = cv::imread("Image2.jpg");
	cv::Mat img2;
	g_slider = 0;
	g_slider_max = 31;
	cv::namedWindow("My Window", 1);
	cv::createTrackbar("TrackbarName", "My Window", &g_slider, g_slider_max, on_trackbar);
	//createTrackbar(타이틀,작동할 이미지이름, 변화된 값을 받을 변수, max값, 콜백함수)
	
	while (1) {
		cv::Sobel(T_img, img2, CV_8U, 1, 0, g_slider);
		//Sobel : 외곽선(엣지 검출 함수)
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
	////Binary Image : 2가지 색상으로 이루어진 이미지(흑,백)
	////threshold(임계값) 이용 임계값보다 작으면 0, 크면 255
	////Histogram : 이미지의 밝기 값에 대해 빈도수를 나타낸 그래프
	//
	////threshold(입력이미지, 출력이미지, 임계값, 최대값(임계값보다 클경우 이값으로 표현), 타입)

	//cv::namedWindow("img", 0);
	//cv::namedWindow("binary", 0);

	//cv::Mat img = cv::imread("Image7.jpg");
	//cv::Mat gray, binary;
	//cv::cvtColor(img, gray, CV_RGB2GRAY); //색상이 3채널이니 흑과백으로 이루게 하기위해 흑백처리하여 2채널로 변경
	//cv::threshold(gray, binary, 128, 255, CV_THRESH_BINARY);

	//cv::imshow("img", img);
	//cv::imshow("binary", binary);

	//cv::waitKey(0);


	////타입 1 : THRESH_BINARY : 임계값보다 작으면 0, 크면 maxvalue
	////타입 2 : THRESH_BINARY_INV : 임계값보다 작으면 maxvalue, 크면 0
	////타입 3 : THRESH_TRUNC: 임계값보다 작으면 원본값, 크면 임계값
	////타입 4 : THRESH_TOZERO : 임계값보다 작으면 0, 크면 원본값
	////타입 5 : THRESH_TOZERO_INV : 임계값보다 작으면 원본값, 크면 0
	return 0;
}