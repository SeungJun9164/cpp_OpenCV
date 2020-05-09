//Mat : Matrix class 
//Matrix : 행렬 
//#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(int, char) {
	Mat mtx(3, 3, CV_32F);//(행,열, 행렬의 값 타입 32(32bit) F(float))
	Mat cmtx(10, 1, CV_64FC2); //C2 : 채널 수 (10,1)행렬이 2개 생긴다
	Mat img(Size(5, 3), CV_8UC3); //size(가로, 세로) U(unsigned) C3 : 채널3개

	Mat mtx2;
	mtx2 = Mat(3, 3, CV_32F);
	Mat cmtx2;
	cmtx2 = Mat(10, 1, CV_64FC1);

	Mat* mtx3 = new Mat(3, 3, CV_32F); //동적으로 Mat생성
	delete mtx3;

	mtx.setTo(10); //setTo() : mtx에 있는 모든 값을 10으로 설정하는 함수
	std::cout << mtx << std::endl;

	cmtx2.setTo(11);
	std::cout << cmtx2 << std::endl;
	std::cout << std::endl;


	Mat m = Mat::ones(3, 3, CV_64F); //ones : Mat가 생성됨과 동시에 1로 초기화(zeros : 0으로 초기화)
	m = m * 3;
	std::cout << m << std::endl;

	double dm[3][3] = { {1,2,1},{0,1,1},{1,0,0} };
	Mat m2 = Mat(3, 3, CV_64F, dm); //dm에 있는 값들로 mat생성
	std::cout << m2 << std::endl;
	std::cout << m + m2 << std::endl;
	std::cout << m - m2 << std::endl;
	std::cout << m * m2 << std::endl; //행렬곱
	std::cout << m / m2 << std::endl; //행렬 나누기
	std::cout << m2.inv() << std::endl; //m2행렬 역행렬로 변환 역행렬은 정방행렬(행과 열의 갯수가 같다)만 가능
	std::cout << m2.t() << std::endl; //행과 열을 바꿈 (3,2)->(2,3)


	

	return 0;
}