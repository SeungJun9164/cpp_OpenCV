#include <opencv2/opencv.hpp>

int main() {
	//Look Up Table
	//Look Up Table : 한 픽셀에는 0~255의 값이 들어가게 되는데 이것을 미리 테이블에 저장해놓아 
	//연산을 빠르게 처리하기 위한 테이블
	/*
	unsigned long AAtime = 0, BBtime = 0;
	unsigned char O[1000][1000] = { 1,2, };

	AAtime = cv::getTickCount();
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			int t = O[i][j] * 1.14;
			t = (t > 255) ? 255 : t;
			O[i][j] = t;
		}
	}
	BBtime = cv::getTickCount();
	std::cout << "just loop " << ((BBtime - AAtime) / cv::getTickFrequency()) << "sec\n";

	unsigned char LUT[256];
	//0~255개 : 256개
	AAtime = cv::getTickCount();
	for (int i = 0; i < 256; i++) {
		int t = i * 1.14;
		t = (t > 255) ? 255 : t;
		LUT[i] = t;
	}
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			O[i][j] = LUT[O[i][j]];
		}
	}

	BBtime = cv::getTickCount();
	std::cout << "just loop " << ((BBtime - AAtime) / cv::getTickFrequency()) << "sec\n";
	*/
	
	/*
	//Look Up Table을 활용한 applyColorMap
	//applyColorMap : 이미지를 원하는 색상으로 변환
	//applyColorMap(이미지 입력, 이미지 출력, 원하는 색상 표)
	cv::Mat img = cv::imread("Image2.jpg");
	cv::namedWindow("img", 1);
	cv::imshow("img", img);

	cv::Mat im_color;
	cv::applyColorMap(img, im_color, cv::COLORMAP_COOL);
	cv::namedWindow("img_color", 1);
	cv::imshow("img_color",im_color);

	cv::Mat img_gray;
	cv::cvtColor(img, img_gray, CV_RGB2GRAY);
	cv::Mat img_color2;
	cv::applyColorMap(img_gray, img_color2, cv::COLORMAP_AUTUMN);
	cv::namedWindow("im_color2", 1);
	cv::imshow("im_color2", img_color2);

	//흑백처리를 한것과 상관없이 동일한 색상으로 나온다
	cv::waitKey(0);
	*/
	cv::Mat img = cv::imread("Image3.jpg");
	cv::Mat lookUpTable(1, 256, CV_8U);
	uchar* p = lookUpTable.data;
	int factor = 256 / 10; // 0~255의 수를 10단계로 나누어서 색 표현
	for (int i = 0; i < 256; i++) {
		p[i] = factor * (i / factor);
		std::cout << i << " = " << p[i] << "\n";
	}

	cv::Mat reduced;
	cv::LUT(img, lookUpTable, reduced);

	cv::namedWindow("img", 1);
	cv::imshow("img", img);
	cv::namedWindow("reduced", 1);
	cv::imshow("reduced", reduced);

	//우리가 만든 lookUpTable은 1채널짜리이기 때문에 흑백과는 다른 색상으로 나온다.
}