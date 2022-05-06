#pragma once

double CompoundSimpson(const double& x0,const double& xn,const int& n);
double CompoundSimpson_x2_test(const double& x0, const double& xn, const int& n);
double compound_T(const double& a, const double& b, const int& k);
double Romberg(const double& x0,const double& xn, const double& eps);
double adaptiveSimpson(const double& a, const double& b, const double& eps);

double MathFunction_1(const double& x);
double MathFunction_x2(const double& x);

double recursion_T(const double& a, const double& b, const double& Tn, const int& n);
