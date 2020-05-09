//Mat : Matrix class 
//Matrix : ��� 
//#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(int, char) {
	Mat mtx(3, 3, CV_32F);//(��,��, ����� �� Ÿ�� 32(32bit) F(float))
	Mat cmtx(10, 1, CV_64FC2); //C2 : ä�� �� (10,1)����� 2�� �����
	Mat img(Size(5, 3), CV_8UC3); //size(����, ����) U(unsigned) C3 : ä��3��

	Mat mtx2;
	mtx2 = Mat(3, 3, CV_32F);
	Mat cmtx2;
	cmtx2 = Mat(10, 1, CV_64FC1);

	Mat* mtx3 = new Mat(3, 3, CV_32F); //�������� Mat����
	delete mtx3;

	mtx.setTo(10); //setTo() : mtx�� �ִ� ��� ���� 10���� �����ϴ� �Լ�
	std::cout << mtx << std::endl;

	cmtx2.setTo(11);
	std::cout << cmtx2 << std::endl;
	std::cout << std::endl;


	Mat m = Mat::ones(3, 3, CV_64F); //ones : Mat�� �����ʰ� ���ÿ� 1�� �ʱ�ȭ(zeros : 0���� �ʱ�ȭ)
	m = m * 3;
	std::cout << m << std::endl;

	double dm[3][3] = { {1,2,1},{0,1,1},{1,0,0} };
	Mat m2 = Mat(3, 3, CV_64F, dm); //dm�� �ִ� ����� mat����
	std::cout << m2 << std::endl;
	std::cout << m + m2 << std::endl;
	std::cout << m - m2 << std::endl;
	std::cout << m * m2 << std::endl; //��İ�
	std::cout << m / m2 << std::endl; //��� ������
	std::cout << m2.inv() << std::endl; //m2��� ����ķ� ��ȯ ������� �������(��� ���� ������ ����)�� ����
	std::cout << m2.t() << std::endl; //��� ���� �ٲ� (3,2)->(2,3)


	

	return 0;
}