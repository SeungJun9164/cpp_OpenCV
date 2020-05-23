#include <opencv2/opencv.hpp>

#include <iostream>

int main() {

	cv::Mat frame;
	cv::Mat old_frame;
	cv::Mat sub_frame;
	cv::VideoCapture cap(0);
	int width = cap.get(cv::CAP_PROP_FRAME_WIDTH); //������ ũ��
	int height = cap.get(cv::CAP_PROP_FRAME_HEIGHT); //������ ũ��
	int fourcc = cv::VideoWriter::fourcc('X', 'V', 'I', 'D');
	int fps = cap.get(cv::CAP_PROP_FPS);

	//cv::VideoCapture stream1(1); //��ķ

	cv::VideoWriter outputVideo;
	outputVideo.open("output.avi", -1, fps, cv::Size(width, height), true);
	while (1) {
		cap.read(frame); //ī�޶�κ��� �̹��� ���� ��������
		if (frame.empty()) {
			std::cerr << "ĸ�� ����\n";
			break;
		}

		cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
		//1��° �μ��� ������ �̹����� 3��° �μ��������� �ٲ� �� �̹����� 2��° �μ��� ������

		imshow("Live", frame);

		//outputVideo.write(frame);


		int wait = int(1.0 / fps * 1000);//�̹����� �������� ������ ���ð�
		if (cv::waitKey(wait) >= 0)
			break;
	}
	return 0;
}
