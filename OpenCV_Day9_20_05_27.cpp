#include <opencv2/opencv.hpp>

int main() {
	//Look Up Table
	//Look Up Table : �� �ȼ����� 0~255�� ���� ���� �Ǵµ� �̰��� �̸� ���̺� �����س��� 
	//������ ������ ó���ϱ� ���� ���̺�
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
	//0~255�� : 256��
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
	//Look Up Table�� Ȱ���� applyColorMap
	//applyColorMap : �̹����� ���ϴ� �������� ��ȯ
	//applyColorMap(�̹��� �Է�, �̹��� ���, ���ϴ� ���� ǥ)
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

	//���ó���� �ѰͰ� ������� ������ �������� ���´�
	cv::waitKey(0);
	*/
	cv::Mat img = cv::imread("Image3.jpg");
	cv::Mat lookUpTable(1, 256, CV_8U);
	uchar* p = lookUpTable.data;
	int factor = 256 / 10; // 0~255�� ���� 10�ܰ�� ����� �� ǥ��
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

	//�츮�� ���� lookUpTable�� 1ä��¥���̱� ������ ������ �ٸ� �������� ���´�.
}