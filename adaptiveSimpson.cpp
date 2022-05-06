#include"mySimpson.h"
#include<vector>
#include<cmath>
#include<iostream>

double adaptiveSimpson(const double& a, const double& b, const double& eps)
{
	mySimpson Base(a, b, eps);
	std::vector<mySimpson> cutBuffer;
	std::vector<mySimpson> childBuffer;
	std::vector<mySimpson> solvedVec;
	double solvedValue = 0;

	cutBuffer.push_back(Base);
	while (!cutBuffer.empty()) {
		for (auto Iter : cutBuffer) 
		{
			double Eps = Iter.getEps();
			mySimpson L = Iter.LeftChild();
			mySimpson R = Iter.RightChild();
			if(abs(Iter - (L + R)) <Eps)
			{
				solvedValue+=L + R + 1 / 15 * (L + R - Iter);
				solvedVec.push_back(L);
				solvedVec.push_back(R);
			}
			else {
				childBuffer.push_back(L);
				childBuffer.push_back(R);
			}
		}
		cutBuffer.clear();
		childBuffer.swap(cutBuffer);
	}
	std::cout << "自适应辛普森积分最终选取区间：" << std::endl;
	for (auto Iter : solvedVec)
	{
		std::cout << Iter.getRange();
	}
	std::cout << std::endl;
	return solvedValue;
}