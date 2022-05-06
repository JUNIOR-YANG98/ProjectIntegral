#include<iostream>
#include<vector>
#include<cmath>
#include"IntegralFunc.h"


double CompoundSimpson(const double& x0, const double& xn, const int& n)
{
	float h = (xn - x0) / n;
	float s = 0;
	for (int k = 0; k < n; k++)
	s += MathFunction_1(x0+k*h)+4*MathFunction_1(x0+(k+0.5)*h)+MathFunction_1(x0+(k+1)*h);
	return s * h / 6;
}

double CompoundSimpson_x2_test(const double& x0, const double& xn, const int& n)
{
	float h = (xn - x0) / n;
	float s = 0;
	for (int k = 0; k < n; k++)
	s += MathFunction_x2(x0 + k * h) + 4 * MathFunction_x2(x0 + (k + 0.5)*h) + MathFunction_x2(x0 + (k + 1)*h);
	return s * h / 6;
}

double Romberg(const double& x0, const double& xn, const double& eps)
{
	unsigned int s = 1,k = 0, h = xn - x0;
	std::vector<double> TBufferVec;
	TBufferVec.push_back(h / 2 * (MathFunction_1(x0) + MathFunction_1(xn)));
	std::cout << "第0次二分后计算结果：" << TBufferVec[0]<< std::endl;
	do {
		k++;
		s += k + 1;
		TBufferVec.resize(s);
		TBufferVec[s-1-k] = recursion_T(x0, xn, TBufferVec[s-2*k-1], pow(2, k - 1));//求二分后的梯形值
		std::cout << "第" << k << "次二分后计算结果：" << TBufferVec[s - 1 - k];
		for (int j = 1; j < k + 1; j++)
		{
			TBufferVec[s-1-k+j] = (pow(4, j)*TBufferVec.at(s-k +j-2) - TBufferVec.at(s-k-2)) / (pow(4, j) - 1);
			std::cout << " " << TBufferVec[s - 1 - k + j];
		}
		std::cout << std::endl;
	} while (abs(TBufferVec.at(s-1)-TBufferVec.at(s-2-k))>eps);
	return TBufferVec.back();
}


/****************************************求积函数********************************************************/
double MathFunction_1(const double& x)
{
	return (log(x)> -1.7e308) ? sqrt(x)*log(x):0;
}

double MathFunction_x2(const double& x)
{
	return x*x;
}

/****************************************Romberg求积梯形公式**********************************************/
double compound_T(const double& a, const double& b, const int& k)
{
	//复合梯形求积公式
	//k：区间[a,b]二分次数

	double h = (b - a) / pow(2,k);
	double s_1 = 0, s_2 = 0;
	for (int i = 0; i <pow(2,k); i++)s_1 += MathFunction_1(a + i * h);
	for (int i = 1; i <= pow(2, k); i++)s_2 += MathFunction_1(a + i * h);
	return h / 2 * (s_1+s_2);
}

double recursion_T(const double& a, const double& b, const double& Tn, const int& n)
{
	//梯形二分递推公式，n表示二分前的分段数
	double h = (b - a) / n;
	double s = 0;
	for (int k = 0; k < n; k++)s += MathFunction_1(a + (k + 0.5)*h);
	return 0.5*(Tn+h*s);
}



