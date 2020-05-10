#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

/*int main() {
	Mat img = imread("Image3.jpg");//(" ",0)을 입력하면 흑백으로 처리
	namedWindow("Wimg", 1);//nameWindow가 없어도 출력은 되지만 사이즈 크기를 조절할 수 없다
	imshow("Wimg", img); //imshow가 없어도 창은 만들어 지지만 사진은 없다
	waitKey(0);

	VideoCapture cap("Video1.mp4");
	if (!cap.isOpened())
		return -1;
	namedWindow("video", 1);
	while (1) {
		Mat frame;
		cap >> frame;
		imshow("video", frame);
		if (waitKey(5) >= 0)
			break;
	}
	return 0;
}*/

//이미지 복사하는 방법
/*int main() {
	Mat img = imread("Image2.jpg");

	Rect r(img.cols / 4, img.rows / 4, img.cols / 4 * 2, img.rows / 4 * 2); //Rect (x, y, 너비, 높이) : x,y에서 너비,높이만큼 사각형을 그려라 

	Mat img2 = img.clone();
	//bitwise_not(img2, img2);//bitwise_not : 색 반전
	imshow("img2", img2);
	waitKey(0);

	Mat img5 = img(r).clone(); //img의 r영역 만큼의 크기만 복사
	imshow("img5", img5);


	Mat cimg;
	img.copyTo(cimg); //원본.copyTo(복사할 Mat객체)
	imshow("cimg", img);


	Mat cimg2;
	img(r).copyTo(cimg2);
	imshow("cimg2", cimg2);


	Mat cimg3(Size(img.cols * 2, img.rows), img.type()); //img의 가로사이즈 2배를 크게 만들겠다. 타입은 img와 동일하게
	cimg3.setTo(255); //cimg3를 흰색으로 초기화
	img.copyTo(cimg3(Range::all(), Range(0, img.cols))); //행은 모든범위, 열은 0에서부터 이미지의 가로크기만큼->창의 반만
	bitwise_not(cimg3, cimg3);
	img2.copyTo(cimg3(Range::all(), Range(img2.cols, img2.cols * 2)));
	imshow("cimg3", cimg3);
	

	Mat roi(img, r); //img에서 r영역만큼을 복사. 하지만 img를 참조하는 것이기 때문에 원본이 변하면 같이 변한다.

	bitwise_not(roi, roi);
	waitKey(0);
}*/

//Mat안의 데이터 접근 방법
//영상에서는 pixel은 0~255사이(검~흰)
//영상은 실제로는 1차원으로 표현되기 때문에 x,y를 가져오고 싶으면 [y * width + x]로 표현된다.
//color일때는 RGB의 값도 있기 때문에, 실제 표현될 때에는 BGR순서대로 표현된다. [y * width * 3 + x * 3 + (0~2)]로 표현 (*3을 하는 이유는 RGB의 색상을 나타내기위해)(0~2는 0 : B, 1 : G, 2 : R)
int main() {
	Mat img = imread("Image2.jpg");
	namedWindow("img", 1);
	imshow("img", img);
	waitKey(0);

	std::cout << img.elemSize() << "\n"; //한 픽셀의 실제 사이즈
	std::cout << img.channels() << "\n"; //몇개의 채널을 가지고 있는지(rgb,alpha)
	std::cout << img.rows << "\n"; // 행의 갯수
	std::cout << img.cols << "\n"; //열의 갯수
	std::cout << img.step << "\n"; //가로의 실제 바이트 수


		//at방법 : 가장 안정적이지만 가장 느림
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			unsigned char b = img.at<Vec3b>(i, j)[0]; //<Vec3b> : 벡터타입의 숫자를 3개의 채널과 크기(b : unsigned를 지정해줄 때 사용)
			unsigned char g = img.at<Vec3b>(i, j)[1];
			unsigned char r = img.at<Vec3b>(i, j)[2];

			img.at<Vec3b>(i, j)[0] = unsigned char(255 - b);
			img.at<Vec3b>(i, j)[1] = unsigned char(255 - g);
			img.at<Vec3b>(i, j)[2] = unsigned char(255 - r);
		}
	}
	imshow("at", img); //색상 반전되어 출력

		//ptr방법 : at보다는 빠르고 안정적이지만 data보다 느림
	for (int i = 0; i < img.rows; i++) {
		Vec3b* ptr = img.ptr<Vec3b>(i);
		for (int j = 0; j < img.cols; j++) {
			//2가지 방법(2가지 중 편한 것 사용)
			unsigned char b = (ptr[j][0]);
			unsigned char g = (ptr[j][1]);
			unsigned char r = (ptr[j][2]);

			Vec3b bgr = ptr[j];
			unsigned char b = (bgr[0]);
			unsigned char g = (bgr[1]);
			unsigned char r = (bgr[2]);

			ptr[j] = Vec3b(255 - b, 255 - g, 255 - r);
		}
	}

		//data방법 : 가장 빠르지만 index계산을 잘못할 경우 프로그램이 죽을수 있기 때문에 안정적이지 않다
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			unsigned char r, g, b;
			b = img.data[i * img.step + j * img.elemSize() + 0]; //인덱스를 계산하여 하나의 색상 값을 가져올 수 있다. .step : 행렬의 한 행이 차지하는 바이트 수 .elemsize() : 행렬 요소 하나의 바이트 크기
			g = img.data[i * img.step + j * img.elemSize() + 1];
			r = img.data[i * img.step + j * img.elemSize() + 2];

			img.data[i * img.step + j * img.elemSize() + 0] = unsigned char(255 - b); //반전 처리하는 문장
			img.data[i * img.step + j * img.elemSize() + 1] = unsigned char(255 - g);
			img.data[i * img.step + j * img.elemSize() + 2] = unsigned char(255 - r);
		}
	}
	imshow("data", img);
	waitKey(0);

		//iterator방법 : ptr과 유사하다.
	MatIterator_<Vec3b> itd = img.begin<Vec3b>(), itd_end = img.end<Vec3b>();
	for (int i = 0; itd != itd_end; itd++, i++) {
		Vec3b bgr = (*itd);
		(*itd)[0] = 255 - bgr[0];
		(*itd)[1] = 255 - bgr[1];
		(*itd)[2] = 255 - bgr[2];
	}
}