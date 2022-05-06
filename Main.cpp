#include<iostream>
#include"IntegralFunc.h"
#include"mySimpson.h"

int main()
{
	std::cout.precision(8);
	std::cout << "\n3�㸴������ɭ���֣�"<< CompoundSimpson(0, 1, 2) << std::endl;
	std::cout << "9�㸴������ɭ���֣�" << CompoundSimpson(0, 1, 8) << std::endl;
	std::cout << "10�㸴������ɭ���֣�" << CompoundSimpson(0, 1, 9) << std::endl;
	std::cout << "21�㸴������ɭ���֣�" << CompoundSimpson(0, 1, 20) << std::endl;
	std::cout << "51�㸴������ɭ���֣�" << CompoundSimpson(0, 1, 50) << std::endl;
	std::cout << "81�㸴������ɭ���֣�" << CompoundSimpson(0, 1, 80) << std::endl;
	std::cout << "161�㸴������ɭ���֣�" << CompoundSimpson(0, 1, 160) << std::endl;
	std::cout << "\n==================================================================================================================\n" << std::endl;
	double eps;
	std::cout << "**��������������ּ��㾫�ȣ�";
	std::cin >> eps;
	std::cout << "*���������(eps:"<<eps<<")��������" << Romberg(0, 1, eps) << std::endl<<std::endl;
	std::cout << "\n==================================================================================================================\n" << std::endl;
	std::cout << "**����������Ӧ���ּ��㾫�ȣ�";
	std::cin >> eps;
	std::cout << "\n*����Ӧ����ɭ����(eps:" << eps << ")������**��" << adaptiveSimpson(.0, 1, eps) << std::endl;
	std::cin >> eps;
}