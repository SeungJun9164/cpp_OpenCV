#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp> //비디오에 접근하여 영상을 가져오기 위한 헤더
#include <opencv2/highgui.hpp> //인터페이스를 위한 헤더
#include <opencv2/imgproc.hpp> //cvtColor함수를 사용하기 위한 헤더

#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <ctime>

#define DEBUG 1


#include <iostream>


using namespace cv;
using namespace std;

//카메라에서 동영상 만들기, 동영상 실행하기
/*
int main() {
	Mat frame;

	VideoCapture cap("Video1.mp4");//비디오 파일 이름
	//VideoCapture cap(0); //카메라에 연결된 카메라의 첫번째에 접근
	if (!cap.isOpened()) {
		std::cerr << "카메라를 열 수 없습니다.\n";
		return -1;
	}

	int fps = cap.get(CAP_PROP_FPS); //카메라로 부터 초당 프레임 가져오기
	
	// 동영상 처리를 위한 함수들
	//int width = cap.get(CAP_PROP_FRAME_WIDTH); //프레임 크기
	//int height = cap.get(CAP_PROP_FRAME_HEIGHT); //프레임 크기
	//int fourcc = VideoWriter::fourcc('X', 'V', 'I', 'D');
	////비디오를 저장할 코덱설정

	//VideoWriter outputVideo;
	//outputVideo.open("output.avi", -1, fps, Size(width, height), true);
	//if (!outputVideo.isOpened()) {
	//	std::cerr << "동영상 저장을 위한 초기화중 에러\n";
	//	return -1;
	//}
	
	
	
	while (1) {
		cap.read(frame); //카메라로부터 이미지 한장 가져오기
		if (frame.empty()) {
			std::cerr << "캡쳐 실패\n";
			break;
		}

		cvtColor(frame, frame, COLOR_BGR2GRAY);
		//1번째 인수로 지정된 이미지를 3번째 인수형식으로 바꾼 후 이미지를 2번째 인수로 돌려줌

		imshow("Live", frame);
		
		//outputVideo.write(frame);
		
		
		int wait = int(1.0 / fps * 1000);//이미지를 가져오는 사이의 대기시간
		if (waitKey(wait) >= 0)
			break;
	}
	return 0;
}*/


//이미지를 그림처럼 만들기
/*int main() {
	Mat image = imread("Image2.jpg", IMREAD_COLOR);

	imshow("image", image);
	waitKey(0);

	Mat image_color = image.clone();
	//image를 복사하여 image_color를 만듬
	//.clone() : 복사하는 함수

	int num_down = 1; //얼만큼 스케일다운을 할 것인지 설정(횟수)
	int num_bilateral = 5; //노이즈를 제거해줄 것인지(횟수) - 많이 하면 이미지가 평평해짐

	for (int i = 0; i < num_down; i++)
		pyrDown(image_color, image_color);
	//pyrDown(원본, 결과, 필터) : 이미지 크기를 작게 만들기 위한 함수
	//pyrUp : 이미지 크기를 크게 만들기 위한 함수

	Mat dst;
	for (int i = 0; i < num_bilateral; i++) {
		bilateralFilter(image_color, dst, 9, 9, 7);
		//bilateralFilter() : 이미지를 부드럽게 만들어 주는 함수
		//bilateralFilter(원본, 결과, 필터링에 이용하는 이웃한 픽셀의 지름, 컬러공간의 시그마 공간 정의(값이 크면 기준색상 영향 커짐), 
		//시그마필터조정(값이 크면 긴밀하게 주변 픽셀에 영향을 미침. 3번째가 0보다 크면 영향x, 0보다 작을때만 d값에 비례) 

		//필터링에 이용하는 이웃한 픽셀의 지름 : 값이 커지면 노이즈를 더 제거하여 이미지가 평평해짐
		//컬러공간의 시그마 공간 정의 : 이미지의 선명함?(값이 크면 이미지가 평평해짐)

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
	//medianBlur() : 노이즈 필터링
	//medianBlur(원본, 결과, 커널사이즈)


	//threshold(이미지, 임계값, 임계값을 넘었을 때 적용할 값, type)
	//이미지를 흑/백으로 나누어서 처리. 임계값보다 크면 값(백), 작으면 0(흑)
	//type 종류 :
	//THRESH_BINARY : 픽셀 값이 임계값보다 크면 값,작으면 0
	//THRESH_BINARY_INV : 픽셀 값이 임계값보다 크면 0,작으면 값
	//THRESH_TRUNC : 픽셀 값이 임계값보다 크면 값, 작으면 그대로(원본 그대로)
	//THRESH_TOZERO : 픽셀 값이 임계값보다 크면 그대로, 작으면 0
	//THRESH_TOZERO_INV : 픽셀 값이 임계값보다 크면 0, 작으면 그대로


	Mat edge;
	adaptiveThreshold(blur, edge, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 3, 1.5);
	//adaptiveThreshold() : 이미지를 흑/백으로 나누어서 처리
	//adaptiveThreshold(원본, 결과, 임계값, thresholding value를 결정하는 계산 방법(메소드), threshold type, thresholding을 적용할 영역 사이즈(선의 굵기?), 평균이나 가중평균에서 차감할 값)  
	//메소드 종류 : CV_ADAPTIVE_THRESH_MEAN_C : 주변영역의 평균 값으로 결정
	//			   ADAPTIVE_THRESH_GAUSSIAN_C
	//타입 종류 : THRESH_BINARY / THRESH_BINARY_INV / THRESH_TRUNC / THRESH_TOZERO / THRESH_TOZERO_INV
	cvtColor(edge, edge, COLOR_GRAY2BGR);

	imshow("edge", edge);
	waitKey(0);

	Mat cartoon;
	bitwise_and(image_color, edge, cartoon);
	//bitwise_and() : 이미지를 비트and 연산
	//bitwise_and(이미지1, 이미지2, 결과)

	imshow("cartoon", cartoon);
	waitKey(0);
}*/

//Sobel() : 이미지의 가장자리를 검출하는 함수
//Sobel(이미지, 정밀도, x방향 미분, y방향 미분, 커널, 배율, 델타(추가값), 픽셀 외삽법(이미지를 가장자리 처리할 경우, 영역 밖의 픽셀은 추정해서))
