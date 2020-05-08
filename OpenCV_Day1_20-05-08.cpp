#include <opencv2/core.hpp> //이미지 저장시 사용되는 Mat클래스와 opencv에서 사용하는 기본적인 자료구조 포함
#include <opencv2/imgcodecs.hpp>//이미지파일 불러오기or저장함수
#include <opencv2/highgui.hpp>//인터페이스를 구현해놓은 모듈(사용자의 입력을 받기위해 대기, 이미지를 화면에 보여주기 위한 함수)
#include <opencv2/imgproc.hpp> //canny함수를 사용하기 위한 파일

//#include <opencv2/opencv.hpp> //하나로도 가능

#include <iostream>

using namespace cv; //라이브러리끼리 충돌나는지 확인

int main() {

	Mat image; //이미지 저장할 Mat객체
	image = imread("Image1.jpg", IMREAD_COLOR);
	//imread(const String& filename, int flags = )
	//IMREAD_UNCHANGED : 이미지를 원본 그대로 처리, 투명도 까지 처리(-1로 대체 가능)
	//IMREAD_COLOR : 이미지를 칼라로 처리. 투명도가 무시됨(1로 대체 가능, 기본값임)
	//IMREAD_GRAYSCALE : 이미지를 흑백으로 처리(0으로 대체 가능)
	if (image.empty()) {
		std::cout << "Could not open or find the image!\n";
		return -1;
	}
	namedWindow("Original", WINDOW_NORMAL);
	//이미지를 보여줄 윈도우 설정
	//(윈도우 식별자 && 윈도우 타이틀 이름, 이미지 크기)
	//WINDOW_AUTOSIZE : 이미지 크기 자동조절(사용자가 조절 불가)
	//WINDOW_NORMAL : 화면 해상도에 맞춰 윈도우 크기 조절(사용자가 조절 가능)
	
	/*
	namedWindow("Original", WND_PROP_FULLSCREEN);
	setWindowProperty("Original", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
	이미지를 전체크기 사이즈로 조절
	*/
	
	//Canny(image, image, 50, 150);
	//(입력영상, 결과 영상이 저장될 Mat형식, 낮은 경계값, 높은 경계값, 커널크기, 정교하게 작동여부)
	//경계선을 찾는 방법
	
	imshow("Original", image);
	//(윈도우 식별자 이름, Mat객체)

	waitKey(0); //활성화된 윈도우 창을 키를 입력받을 때까지 대기,단위 : ms

	//실행하면 윈도우창과 프롬포트 창이 같이뜸

}