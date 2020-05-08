#include <opencv2/core.hpp> //�̹��� ����� ���Ǵ� MatŬ������ opencv���� ����ϴ� �⺻���� �ڷᱸ�� ����
#include <opencv2/imgcodecs.hpp>//�̹������� �ҷ�����or�����Լ�
#include <opencv2/highgui.hpp>//�������̽��� �����س��� ���(������� �Է��� �ޱ����� ���, �̹����� ȭ�鿡 �����ֱ� ���� �Լ�)
#include <opencv2/imgproc.hpp> //canny�Լ��� ����ϱ� ���� ����

//#include <opencv2/opencv.hpp> //�ϳ��ε� ����

#include <iostream>

using namespace cv; //���̺귯������ �浹������ Ȯ��

int main() {

	Mat image; //�̹��� ������ Mat��ü
	image = imread("Image1.jpg", IMREAD_COLOR);
	//imread(const String& filename, int flags = )
	//IMREAD_UNCHANGED : �̹����� ���� �״�� ó��, ���� ���� ó��(-1�� ��ü ����)
	//IMREAD_COLOR : �̹����� Į��� ó��. ������ ���õ�(1�� ��ü ����, �⺻����)
	//IMREAD_GRAYSCALE : �̹����� ������� ó��(0���� ��ü ����)
	if (image.empty()) {
		std::cout << "Could not open or find the image!\n";
		return -1;
	}
	namedWindow("Original", WINDOW_NORMAL);
	//�̹����� ������ ������ ����
	//(������ �ĺ��� && ������ Ÿ��Ʋ �̸�, �̹��� ũ��)
	//WINDOW_AUTOSIZE : �̹��� ũ�� �ڵ�����(����ڰ� ���� �Ұ�)
	//WINDOW_NORMAL : ȭ�� �ػ󵵿� ���� ������ ũ�� ����(����ڰ� ���� ����)
	
	/*
	namedWindow("Original", WND_PROP_FULLSCREEN);
	setWindowProperty("Original", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
	�̹����� ��üũ�� ������� ����
	*/
	
	//Canny(image, image, 50, 150);
	//(�Է¿���, ��� ������ ����� Mat����, ���� ��谪, ���� ��谪, Ŀ��ũ��, �����ϰ� �۵�����)
	//��輱�� ã�� ���
	
	imshow("Original", image);
	//(������ �ĺ��� �̸�, Mat��ü)

	waitKey(0); //Ȱ��ȭ�� ������ â�� Ű�� �Է¹��� ������ ���,���� : ms

	//�����ϸ� ������â�� ������Ʈ â�� ���̶�

}