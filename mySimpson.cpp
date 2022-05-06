#include "mySimpson.h"
#include<cmath>

mySimpson::mySimpson(const double& a, const double& b, const double& eps) 
{
	Initial.a = a;
	Initial.b = b;
	Initial.eps = eps;
	Initial.Ivalue = (b - a) / 6 * (this->SimpsonFunction(a) + 4 * this->SimpsonFunction((a + b) / 2) + this->SimpsonFunction(b));
}

inline bool mySimpson::operator < (const mySimpson& rightValue) const {
	return Initial.Ivalue < rightValue.getIvalue() ? true : false;
}
inline bool mySimpson::operator < (const double& rightValue) const {
	return Initial.Ivalue < rightValue ? true : false;
}

inline bool mySimpson::operator > (const mySimpson& rightValue) const {
	return Initial.Ivalue > rightValue.getIvalue() ? true : false;
}
inline bool mySimpson::operator > (const double& rightValue) const {
	return Initial.Ivalue > rightValue ? true : false;
}

double mySimpson::operator + (const mySimpson& rightValue) {
	return  Initial.Ivalue+rightValue.getIvalue();
}
double mySimpson::operator - (const mySimpson& rightValue) {
	return Initial.Ivalue - rightValue.getIvalue();
}
double mySimpson::operator - (const double& rightValue) {
	return Initial.Ivalue - rightValue;
}

inline mySimpson& mySimpson::operator +=(const mySimpson& rightValue) {
	Initial.a += rightValue.getValue_1();
	Initial.b += rightValue.getValue_2();
	Initial.eps += rightValue.getEps();
	Initial.Ivalue += rightValue.getIvalue();
	return *this;
}

mySimpson mySimpson::LeftChild() const
{
	double Ivalue = this->BaseSimpson(Initial.a, (Initial.a + Initial.b) / 2);
	return mySimpson({Initial.a, (Initial.a + Initial.b) / 2, Initial.eps/2, Ivalue});
}
mySimpson mySimpson::RightChild() const
{
	double Ivalue = this->BaseSimpson((Initial.a + Initial.b) / 2, Initial.b);
	return mySimpson({ (Initial.a + Initial.b) / 2, Initial.b, Initial.eps / 2, Ivalue });
}

double operator - (const double& temp, const mySimpson& rightValue) {
	return temp - rightValue.getIvalue();
}
std::ostream&  operator <<(std::ostream& os, const Range& range) {
	return os << "[" << range.a << "," << range.b << "] ";
}