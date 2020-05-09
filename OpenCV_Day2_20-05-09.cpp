#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp> //������ �����Ͽ� ������ �������� ���� ���
#include <opencv2/highgui.hpp> //�������̽��� ���� ���
#include <opencv2/imgproc.hpp> //cvtColor�Լ��� ����ϱ� ���� ���

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

//ī�޶󿡼� ������ �����, ������ �����ϱ�
/*
int main() {
	Mat frame;

	VideoCapture cap("Video1.mp4");//���� ���� �̸�
	//VideoCapture cap(0); //ī�޶� ����� ī�޶��� ù��°�� ����
	if (!cap.isOpened()) {
		std::cerr << "ī�޶� �� �� �����ϴ�.\n";
		return -1;
	}

	int fps = cap.get(CAP_PROP_FPS); //ī�޶�� ���� �ʴ� ������ ��������
	
	// ������ ó���� ���� �Լ���
	//int width = cap.get(CAP_PROP_FRAME_WIDTH); //������ ũ��
	//int height = cap.get(CAP_PROP_FRAME_HEIGHT); //������ ũ��
	//int fourcc = VideoWriter::fourcc('X', 'V', 'I', 'D');
	////������ ������ �ڵ�����

	//VideoWriter outputVideo;
	//outputVideo.open("output.avi", -1, fps, Size(width, height), true);
	//if (!outputVideo.isOpened()) {
	//	std::cerr << "������ ������ ���� �ʱ�ȭ�� ����\n";
	//	return -1;
	//}
	
	
	
	while (1) {
		cap.read(frame); //ī�޶�κ��� �̹��� ���� ��������
		if (frame.empty()) {
			std::cerr << "ĸ�� ����\n";
			break;
		}

		cvtColor(frame, frame, COLOR_BGR2GRAY);
		//1��° �μ��� ������ �̹����� 3��° �μ��������� �ٲ� �� �̹����� 2��° �μ��� ������

		imshow("Live", frame);
		
		//outputVideo.write(frame);
		
		
		int wait = int(1.0 / fps * 1000);//�̹����� �������� ������ ���ð�
		if (waitKey(wait) >= 0)
			break;
	}
	return 0;
}*/

int main() {
	Mat image = imread("Image2.jpg", IMREAD_COLOR);

	imshow("image", image);
	waitKey(0);

	Mat image_color = image.clone();
	//image�� �����Ͽ� image_color�� ����
	//.clone() : �����ϴ� �Լ�

	int num_down = 1; //��ŭ �����ϴٿ��� �� ������ ����(Ƚ��)
	int num_bilateral = 5; //����� �������� ������(Ƚ��) - ���� �ϸ� �̹����� ��������

	for (int i = 0; i < num_down; i++) 
		pyrDown(image_color, image_color);
	//pyrDown(����, ���, ����) : �̹��� ũ�⸦ �۰� ����� ���� �Լ�
	//pyrUp : �̹��� ũ�⸦ ũ�� ����� ���� �Լ�

	Mat dst;
	for (int i = 0; i < num_bilateral; i++) {
		bilateralFilter(image_color, dst, 9, 9, 7);
		//bilateralFilter() : �̹����� �ε巴�� ����� �ִ� �Լ�
		//bilateralFilter(����, ���, ���͸��� �̿��ϴ� �̿��� �ȼ��� ����, �÷������� �ñ׸� ���� ����(���� ũ�� ���ػ��� ���� Ŀ��), 
		//�ñ׸���������(���� ũ�� ����ϰ� �ֺ� �ȼ��� ������ ��ħ. 3��°�� 0���� ũ�� ����x, 0���� �������� d���� ���) 

		//���͸��� �̿��ϴ� �̿��� �ȼ��� ���� : ���� Ŀ���� ����� �� �����Ͽ� �̹����� ��������
		//�÷������� �ñ׸� ���� ���� : �̹����� ������?(���� ũ�� �̹����� ��������)

		image_color = dst.clone();
	}
	imshow("image_color", image_color);
	waitKey(0);

	for (int i = 0; i < num_down; i++) {
		pyrUp(image_color, image_color);
	}
	
	Mat blur, gray;

	cvtColor(image_color, gray, COLOR_RGB2GRAY);
	medianBlur(gray, blur, 5);
	//medianBlur() : ������ ���͸�
	//medianBlur(����, ���, Ŀ�λ�����)

	/*
	threshold(�̹���, �Ӱ谪, �Ӱ谪�� �Ѿ��� �� ������ ��, type)
	�̹����� ��/������ ����� ó��. �Ӱ谪���� ũ�� ��(��), ������ 0(��)
	type ���� : 
	THRESH_BINARY : �ȼ� ���� �Ӱ谪���� ũ�� ��,������ 0
	THRESH_BINARY_INV : �ȼ� ���� �Ӱ谪���� ũ�� 0,������ ��
	THRESH_TRUNC : �ȼ� ���� �Ӱ谪���� ũ�� ��, ������ �״��(���� �״��)
	THRESH_TOZERO : �ȼ� ���� �Ӱ谪���� ũ�� �״��, ������ 0
	THRESH_TOZERO_INV : �ȼ� ���� �Ӱ谪���� ũ�� 0, ������ �״��
	*/

	Mat edge;
	adaptiveThreshold(blur, edge, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 3, 1.5);
	//adaptiveThreshold() : �̹����� ��/������ ����� ó��
	//adaptiveThreshold(����, ���, �Ӱ谪, thresholding value�� �����ϴ� ��� ���(�޼ҵ�), threshold type, thresholding�� ������ ���� ������(���� ����?), ����̳� ������տ��� ������ ��)  
	//�޼ҵ� ���� : CV_ADAPTIVE_THRESH_MEAN_C : �ֺ������� ��� ������ ����
	//			   ADAPTIVE_THRESH_GAUSSIAN_C
	//Ÿ�� ���� : THRESH_BINARY / THRESH_BINARY_INV / THRESH_TRUNC / THRESH_TOZERO / THRESH_TOZERO_INV
	cvtColor(edge, edge, COLOR_GRAY2BGR);

	imshow("edge", edge);
	waitKey(0);

	Mat cartoon;
	bitwise_and(image_color, edge, cartoon);
	//bitwise_and() : �̹����� ��Ʈand ����
	//bitwise_and(�̹���1, �̹���2, ���)

	imshow("cartoon", cartoon);
	waitKey(0);
}
