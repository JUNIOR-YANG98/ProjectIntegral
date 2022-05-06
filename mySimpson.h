#pragma once
#include<cmath>
#include<iostream>

struct BinarySimpson {
	double a;
	double b;
	double eps;
	double Ivalue;
};
struct Range {
	double a;
	double b;
};

class mySimpson
{
public:
	mySimpson(const BinarySimpson& temp) :Initial(temp) {}          //输入完整的value构造Simpson
	mySimpson(const double& a, const double& b, const double& eps); //输入区间值构造Simpson
	mySimpson LeftChild() const;
	mySimpson RightChild() const;

	double getValue_1() const { return Initial.a; }
	double getValue_2() const { return Initial.b; }
	Range getRange()const { return { Initial.a,Initial.b }; }
	double getEps() const { return Initial.eps; }
	double getIvalue() const { return Initial.Ivalue; }

	double operator + (const mySimpson& rightValue);
	double operator - (const mySimpson& rightValue);
	double operator - (const double& rightValue);
	mySimpson& operator += (const mySimpson& rightValue);
	bool operator < (const mySimpson& rightValue) const;
	bool operator < (const double& rightValue) const;
	bool operator > (const mySimpson& rightValue) const;
	bool operator > (const double& rightValue) const;

private:
	BinarySimpson Initial;

	virtual double SimpsonFunction(const double& x) const{ return (log(x) > -1.7e308) ? sqrt(x)*log(x) : 0; }
	double BaseSimpson(const double& a, const double& b)const {
		//基础Simpson公式计算
		return (b - a) / 6 * (this->SimpsonFunction(a) + 4 * this->SimpsonFunction((a + b) / 2) + this->SimpsonFunction(b));
	}
};

double operator - (const double& temp,const mySimpson& rightValue);
std::ostream&  operator <<(std::ostream& os,const Range& range);