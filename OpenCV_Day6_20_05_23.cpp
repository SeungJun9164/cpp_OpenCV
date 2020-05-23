#include <opencv2/opencv.hpp>

#include <iostream>

int main() {

	cv::Mat frame;
	cv::Mat old_frame;
	cv::Mat sub_frame;
	cv::VideoCapture cap(0);
	int width = cap.get(cv::CAP_PROP_FRAME_WIDTH); //프레임 크기
	int height = cap.get(cv::CAP_PROP_FRAME_HEIGHT); //프레임 크기
	int fourcc = cv::VideoWriter::fourcc('X', 'V', 'I', 'D');
	int fps = cap.get(cv::CAP_PROP_FPS);

	//cv::VideoCapture stream1(1); //웹캠

	cv::VideoWriter outputVideo;
	outputVideo.open("output.avi", -1, fps, cv::Size(width, height), true);
	while (1) {
		cap.read(frame); //카메라로부터 이미지 한장 가져오기
		if (frame.empty()) {
			std::cerr << "캡쳐 실패\n";
			break;
		}

		cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
		//1번째 인수로 지정된 이미지를 3번째 인수형식으로 바꾼 후 이미지를 2번째 인수로 돌려줌

		imshow("Live", frame);

		//outputVideo.write(frame);


		int wait = int(1.0 / fps * 1000);//이미지를 가져오는 사이의 대기시간
		if (cv::waitKey(wait) >= 0)
			break;
	}
	return 0;
}
