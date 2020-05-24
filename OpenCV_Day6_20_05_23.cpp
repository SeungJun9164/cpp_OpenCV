#include <opencv2/opencv.hpp>

int main() {

	cv::Mat old_frame;
	cv::Mat sub_frame;

	cv::VideoCapture cap1("Video2.mp4");
	if (!cap1.isOpened()) {
		std::cout << "동영상 파일을 열 수 없습니다.\n";
	}

	cap1.set(cv::CAP_PROP_FRAME_WIDTH, 320);
	cap1.set(cv::CAP_PROP_FRAME_HEIGHT, 240);

	cv::Mat frame1;
	cv::namedWindow("video", 1);

	while (1) {
		cap1.read(frame1);

		if (old_frame.empty()) {
			old_frame = frame1.clone(); //old_frame에 현재 프레임 넣어주기
			continue;
		}

		cv::subtract(old_frame, frame1, sub_frame);
		//frame1에서 old_frame을 빼어 sub_frame에 넣어라

		cv::imshow("video", frame1);
		cv::imshow("sub_frame", sub_frame);

		old_frame = frame1.clone();
		//이 문장을 주석처리하면 배경차이로 움직임을 확인 할 수 있다.

		if (cv::waitKey(20) >= 0) break;
	}
	return 0;
}
