#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

/*int main() {
	Mat img = imread("Image3.jpg");//(" ",0)�� �Է��ϸ� ������� ó��
	namedWindow("Wimg", 1);//nameWindow�� ��� ����� ������ ������ ũ�⸦ ������ �� ����
	imshow("Wimg", img); //imshow�� ��� â�� ����� ������ ������ ����
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

//�̹��� �����ϴ� ���
/*int main() {
	Mat img = imread("Image2.jpg");

	Rect r(img.cols / 4, img.rows / 4, img.cols / 4 * 2, img.rows / 4 * 2); //Rect (x, y, �ʺ�, ����) : x,y���� �ʺ�,���̸�ŭ �簢���� �׷��� 

	Mat img2 = img.clone();
	//bitwise_not(img2, img2);//bitwise_not : �� ����
	imshow("img2", img2);
	waitKey(0);

	Mat img5 = img(r).clone(); //img�� r���� ��ŭ�� ũ�⸸ ����
	imshow("img5", img5);


	Mat cimg;
	img.copyTo(cimg); //����.copyTo(������ Mat��ü)
	imshow("cimg", img);


	Mat cimg2;
	img(r).copyTo(cimg2);
	imshow("cimg2", cimg2);


	Mat cimg3(Size(img.cols * 2, img.rows), img.type()); //img�� ���λ����� 2�踦 ũ�� ����ڴ�. Ÿ���� img�� �����ϰ�
	cimg3.setTo(255); //cimg3�� ������� �ʱ�ȭ
	img.copyTo(cimg3(Range::all(), Range(0, img.cols))); //���� ������, ���� 0�������� �̹����� ����ũ�⸸ŭ->â�� �ݸ�
	bitwise_not(cimg3, cimg3);
	img2.copyTo(cimg3(Range::all(), Range(img2.cols, img2.cols * 2)));
	imshow("cimg3", cimg3);
	

	Mat roi(img, r); //img���� r������ŭ�� ����. ������ img�� �����ϴ� ���̱� ������ ������ ���ϸ� ���� ���Ѵ�.

	bitwise_not(roi, roi);
	waitKey(0);
}*/

//Mat���� ������ ���� ���
//���󿡼��� pixel�� 0~255����(��~��)
//������ �����δ� 1�������� ǥ���Ǳ� ������ x,y�� �������� ������ [y * width + x]�� ǥ���ȴ�.
//color�϶��� RGB�� ���� �ֱ� ������, ���� ǥ���� ������ BGR������� ǥ���ȴ�. [y * width * 3 + x * 3 + (0~2)]�� ǥ�� (*3�� �ϴ� ������ RGB�� ������ ��Ÿ��������)(0~2�� 0 : B, 1 : G, 2 : R)
int main() {
	Mat img = imread("Image2.jpg");
	namedWindow("img", 1);
	imshow("img", img);
	waitKey(0);

	std::cout << img.elemSize() << "\n"; //�� �ȼ��� ���� ������
	std::cout << img.channels() << "\n"; //��� ä���� ������ �ִ���(rgb,alpha)
	std::cout << img.rows << "\n"; // ���� ����
	std::cout << img.cols << "\n"; //���� ����
	std::cout << img.step << "\n"; //������ ���� ����Ʈ ��


		//at��� : ���� ������������ ���� ����
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			unsigned char b = img.at<Vec3b>(i, j)[0]; //<Vec3b> : ����Ÿ���� ���ڸ� 3���� ä�ΰ� ũ��(b : unsigned�� �������� �� ���)
			unsigned char g = img.at<Vec3b>(i, j)[1];
			unsigned char r = img.at<Vec3b>(i, j)[2];

			img.at<Vec3b>(i, j)[0] = unsigned char(255 - b);
			img.at<Vec3b>(i, j)[1] = unsigned char(255 - g);
			img.at<Vec3b>(i, j)[2] = unsigned char(255 - r);
		}
	}
	imshow("at", img); //���� �����Ǿ� ���

		//ptr��� : at���ٴ� ������ ������������ data���� ����
	for (int i = 0; i < img.rows; i++) {
		Vec3b* ptr = img.ptr<Vec3b>(i);
		for (int j = 0; j < img.cols; j++) {
			//2���� ���(2���� �� ���� �� ���)
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

		//data��� : ���� �������� index����� �߸��� ��� ���α׷��� ������ �ֱ� ������ ���������� �ʴ�
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			unsigned char r, g, b;
			b = img.data[i * img.step + j * img.elemSize() + 0]; //�ε����� ����Ͽ� �ϳ��� ���� ���� ������ �� �ִ�. .step : ����� �� ���� �����ϴ� ����Ʈ �� .elemsize() : ��� ��� �ϳ��� ����Ʈ ũ��
			g = img.data[i * img.step + j * img.elemSize() + 1];
			r = img.data[i * img.step + j * img.elemSize() + 2];

			img.data[i * img.step + j * img.elemSize() + 0] = unsigned char(255 - b); //���� ó���ϴ� ����
			img.data[i * img.step + j * img.elemSize() + 1] = unsigned char(255 - g);
			img.data[i * img.step + j * img.elemSize() + 2] = unsigned char(255 - r);
		}
	}
	imshow("data", img);
	waitKey(0);

		//iterator��� : ptr�� �����ϴ�.
	MatIterator_<Vec3b> itd = img.begin<Vec3b>(), itd_end = img.end<Vec3b>();
	for (int i = 0; itd != itd_end; itd++, i++) {
		Vec3b bgr = (*itd);
		(*itd)[0] = 255 - bgr[0];
		(*itd)[1] = 255 - bgr[1];
		(*itd)[2] = 255 - bgr[2];
	}
}