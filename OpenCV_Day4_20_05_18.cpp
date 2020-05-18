#include<opencv2/opencv.hpp>

int main() {

	double va[] = { 1,2,3 };
	double vb[] = { 0,0,1 };
	double vc[3];

	cv::Mat Va(3, 1, CV_64FC1, va);
	cv::Mat Vb(3, 1, CV_64FC1, vb);
	cv::Mat Vc(3, 1, CV_64FC1, vc);

	double res = Va.dot(Vb); //���� ����(�� ���Ͱ��� ����)
	Vc = Va.cross(Vb); //���� ����(�� ���Ͱ��� �����ϴ� ���ο� �����ϳ� ����)
	std::cout << res << "\n" << Vc << std::endl;

	//Single matrix operations
	
	cv::Mat Ma = cv::Mat::eye(3, 3, CV_64FC1); // eye : 3,3��Ŀ� �밢�� 1�� ä���� ���
	std::cout << "Ma \n" << Ma << std::endl;
	double dm[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	cv::Mat Mb = cv::Mat(3, 3, CV_64F, dm);
	std::cout << Mb << "\n" << std::endl;
	cv::Mat Mc;
	Mc = Ma * Mb;

	
	Mc = Mb.t(); //.t() : transpose Mb����� ��� ���� �ٲ㼭 Mc�� ����
	std::cout << Mc << std::endl;
	cv::Scalar t = cv::trace(Ma); //trace : �밢���� ��ҵ��� �� ���ϴ� �� (�ڷ�� ��Į����)
	std::cout << t.val[0] << std::endl;
	double d = cv::determinant(Ma); //determinant : ��� ��
	std::cout << d << std::endl;
	Mc = Ma.inv(); //inv : �����
	cv::invert(Ma,Mc); //invert : ����� ���� ����
	std::cout << Mc << std::endl;






}