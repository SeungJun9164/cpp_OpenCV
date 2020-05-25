#include<opencv2/opencv.hpp>
#include<ctime>
using namespace cv;
int main() {

	Mat Gnoise = Mat(5, 5, CV_8SC1);
	randn(Gnoise, 5, 10); // low,high //정규분포
	std::cout << Gnoise << std::endl << std::endl;

	Mat Unoise = Mat(5, 5, CV_8SC1);
	randu(Unoise, 5, 10);
	std::cout << Unoise << std::endl << std::endl;

	Mat img = imread("image2.jpg");
	namedWindow("img",0);
	imshow("img", img);


	//노이즈 방법 1

	Mat Gaussian_noise = Mat(img.size(),img.type());
	double mean = 0;
	double std = 10;
	randn(Gaussian_noise, mean, std); 
	Mat colorNoise = img + Gaussian_noise; //이미지에 노이즈를 추가

	namedWindow("img",0);
	imshow("img", img);

	namedWindow("ColorNoise",0);
	imshow("ColorNoise", colorNoise);

	waitKey(0);

	//노이즈 방법2
	Mat img2 = imread("image2.jpg");
	int rsize = 100;
	srand(time(0));

	Mat imgD = img2.clone();
	for (int i = 0; i < rsize; i++) {
		int x = rand() % img2.cols;
		int y = rand() % img2.rows;

		imgD.at<Vec3b>(x, y)[0] = 255;
		imgD.at<Vec3b>(x, y)[1] = 255;
		imgD.at<Vec3b>(x, y)[2] = 255;
	}
	namedWindow("img2", 0);
	imshow("img2", img2);

	namedWindow("imgD", 0);
	imshow("imgD", imgD);

	waitKey(0);

	return 0;
}