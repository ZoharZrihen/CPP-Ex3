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
	double re_v;

public:
	RealVariable(): re_v(0){};
	RealVariable(double x): re_v(x){};
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
	RealVariable &operator/(const RealVariable &x);
	friend RealVariable &operator/(double t, const RealVariable &x);

	RealVariable &operator==(double t);
	RealVariable &operator==(const RealVariable &x);
	friend RealVariable &operator==(double t, const RealVariable &x);

	RealVariable &operator^(int t);
}; //End of Real Variable

class ComplexVariable{
private:
	double _re;
	double _im;
public:
	ComplexVariable(): _re(0),_im(0){};
	ComplexVariable(double re, double im): _re(re), _im(im){};

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
