#include<iostream>
#include"IntegralFunc.h"
#include"mySimpson.h"

int main()
{
	std::cout.precision(8);
	std::cout << "\n3点复合辛普森积分："<< CompoundSimpson(0, 1, 2) << std::endl;
	std::cout << "9点复合辛普森积分：" << CompoundSimpson(0, 1, 8) << std::endl;
	std::cout << "10点复合辛普森积分：" << CompoundSimpson(0, 1, 9) << std::endl;
	std::cout << "21点复合辛普森积分：" << CompoundSimpson(0, 1, 20) << std::endl;
	std::cout << "51点复合辛普森积分：" << CompoundSimpson(0, 1, 50) << std::endl;
	std::cout << "81点复合辛普森积分：" << CompoundSimpson(0, 1, 80) << std::endl;
	std::cout << "161点复合辛普森积分：" << CompoundSimpson(0, 1, 160) << std::endl;
	std::cout << "\n==================================================================================================================\n" << std::endl;
	double eps;
	std::cout << "**请输入龙贝格积分计算精度：";
	std::cin >> eps;
	std::cout << "*龙贝格积分(eps:"<<eps<<")计算结果：" << Romberg(0, 1, eps) << std::endl<<std::endl;
	std::cout << "\n==================================================================================================================\n" << std::endl;
	std::cout << "**请输入自适应积分计算精度：";
	std::cin >> eps;
	std::cout << "\n*自适应辛普森积分(eps:" << eps << ")计算结果**：" << adaptiveSimpson(.0, 1, eps) << std::endl;
	std::cin >> eps;
}