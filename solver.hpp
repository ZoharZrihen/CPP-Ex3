/*
 * solver.hpp
 *
 *  Created on: 24 Apr 2020
 *      Author: zohar
 */

#include <iostream>
#include <complex>
using namespace std;

namespace solver{

class RealVariable{
private:
	double c1;
	double c2;
	double c3;

public:
	RealVariable(): c1(0),c2(1),c3(0){};
	RealVariable(double x, double y,double z): c1(x),c2(y),c3(z){};
	double getc1() const {return c1;}
	double getc2() const {return c2;}
	double getc3() const {return c3;}
	RealVariable &operator*(double t);
	RealVariable &operator*(const RealVariable &x);
	friend RealVariable &operator*(double t, const RealVariable &x);

	RealVariable &operator+(double t);
	RealVariable &operator+(const RealVariable &x);
	friend RealVariable &operator+(double t, const RealVariable &x);

	RealVariable &operator-(double t);
	RealVariable &operator-(const RealVariable &x);
	friend RealVariable &operator-(double t, const RealVariable &x);

	RealVariable &operator/(double t);
	friend RealVariable &operator/(double t, const RealVariable &x);

	RealVariable &operator==(double t);
	RealVariable &operator==(const RealVariable &x);
	friend RealVariable &operator==(double t, const RealVariable &x);

	RealVariable &operator^(int t);
}; //End of Real Variable

class ComplexVariable{
private:
	std::complex<double> c1,c2,c3;
public:
	ComplexVariable(): c1(std::complex<double>(0,0)),c2(std::complex<double>(1,0)),c3(std::complex<double>(0,0)){};
	ComplexVariable(std::complex<double> x,std::complex<double>y,std::complex<double> z): c1(x),c2(y),c3(z){};

	ComplexVariable &operator*(const ComplexVariable &x);
	ComplexVariable &operator*(double t);
	ComplexVariable &operator*(std::complex<double> x);
	friend ComplexVariable &operator*(double t, const ComplexVariable &x);
	friend ComplexVariable &operator*(std::complex<double>y,const ComplexVariable &x);

	ComplexVariable &operator+(const ComplexVariable &x);
	ComplexVariable &operator+(double t);
	ComplexVariable &operator+(std::complex<double> x);
	friend ComplexVariable &operator+(double t, const ComplexVariable &x);
	friend ComplexVariable &operator+(std::complex<double>y,const ComplexVariable &x);

	ComplexVariable &operator-(const ComplexVariable &x);
	ComplexVariable &operator-(double t);
	ComplexVariable &operator-(std::complex<double> x);
	friend ComplexVariable &operator-(double t, const ComplexVariable &x);
	friend ComplexVariable &operator-(std::complex<double>y,const ComplexVariable &x);

	ComplexVariable &operator/(const ComplexVariable &x);
	ComplexVariable &operator/(double t);
	ComplexVariable &operator/(std::complex<double> x);
	friend ComplexVariable &operator/(double t, const ComplexVariable &x);
	friend ComplexVariable &operator/(std::complex<double>y,const ComplexVariable &x);

	ComplexVariable &operator==(const ComplexVariable &x);
	ComplexVariable &operator==(double t);
	ComplexVariable &operator==(std::complex<double> x);
	friend ComplexVariable &operator==(double t, const ComplexVariable &x);
	friend ComplexVariable &operator==(std::complex<double>y,const ComplexVariable &x);

	ComplexVariable &operator^(int t);
}; // End of Complex Variable

double solve(RealVariable &x);
std::complex<double> solve(ComplexVariable &y);

} // End of Namespace solver
