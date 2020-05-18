#include<opencv2/opencv.hpp>

int main() {

	double va[] = { 1,2,3 };
	double vb[] = { 0,0,1 };
	double vc[3];

	cv::Mat Va(3, 1, CV_64FC1, va);
	cv::Mat Vb(3, 1, CV_64FC1, vb);
	cv::Mat Vc(3, 1, CV_64FC1, vc);

	double res = Va.dot(Vb); //벡터 내적(두 벡터간의 각도)
	Vc = Va.cross(Vb); //벡터 외적(두 벡터간의 직교하는 새로운 벡터하나 생성)
	std::cout << res << "\n" << Vc << std::endl;

	//Single matrix operations
	
	cv::Mat Ma = cv::Mat::eye(3, 3, CV_64FC1); // eye : 3,3행렬에 대각선 1로 채워진 행렬
	std::cout << "Ma \n" << Ma << std::endl;
	double dm[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	cv::Mat Mb = cv::Mat(3, 3, CV_64F, dm);
	std::cout << Mb << "\n" << std::endl;
	cv::Mat Mc;
	Mc = Ma * Mb;

	
	Mc = Mb.t(); //.t() : transpose Mb행렬을 행과 열을 바꿔서 Mc에 대입
	std::cout << Mc << std::endl;
	cv::Scalar t = cv::trace(Ma); //trace : 대각선의 요소들을 다 더하는 것 (자료는 스칼라형)
	std::cout << t.val[0] << std::endl;
	double d = cv::determinant(Ma); //determinant : 행렬 식
	std::cout << d << std::endl;
	Mc = Ma.inv(); //inv : 역행렬
	cv::invert(Ma,Mc); //invert : 역행렬 위와 같음
	std::cout << Mc << std::endl;






}