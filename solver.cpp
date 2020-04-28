/*
 * solver.cpp
 *
 *  Created on: 24 Apr 2020
 *      Author: zohar
 */
#include "solver.hpp"
#include <iostream>
#include <complex>
using namespace std;
using solver::RealVariable, solver::ComplexVariable, solver::solve;

RealVariable &RealVariable::operator*(double t){
	return *this;
}

RealVariable &RealVariable::operator*(const RealVariable &x){
	return *this;
}

RealVariable &solver::operator*(double t, const RealVariable &x){
	RealVariable *ans= new RealVariable();
	return *ans;
}

RealVariable &RealVariable::operator+(double t){
	return *this;
}

RealVariable &RealVariable::operator+(const RealVariable &x){
	return *this;
}

RealVariable &solver::operator+(double t, const RealVariable &x){
	RealVariable *ans= new RealVariable();
	return *ans;
}

RealVariable &RealVariable::operator-(double t){
	return *this;
}

RealVariable &RealVariable::operator-(const RealVariable &x){
	return *this;
}

RealVariable &solver::operator-(double t, const RealVariable &x){
	RealVariable *ans= new RealVariable();
	return *ans;
}

RealVariable &RealVariable::operator/(double t){
	return *this;
}

RealVariable &RealVariable::operator/(const RealVariable &x){
	return *this;
}

RealVariable &solver::operator/(double t, const RealVariable &x){
	RealVariable *ans= new RealVariable();
	return *ans;
}

RealVariable &RealVariable::operator==(double t){
	return *this;
}

RealVariable &RealVariable::operator==(const RealVariable &x){
	return *this;
}

RealVariable &solver::operator==(double t, const RealVariable &x){
	RealVariable *ans= new RealVariable();
	return *ans;
}

RealVariable &RealVariable::operator^(int t){
	return *this;
}

ComplexVariable &ComplexVariable::operator*(const ComplexVariable &x){
	return *this;
}

ComplexVariable &ComplexVariable::operator*(double t){
	return *this;
}

ComplexVariable &ComplexVariable::operator*(std::complex<double>x){
	return *this;
}

ComplexVariable &solver::operator*(double t, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable();
	return *ans;
}

ComplexVariable &solver::operator*(std::complex<double> y, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable();
	return *ans;
}

ComplexVariable &ComplexVariable::operator+(const ComplexVariable &x){
	return *this;
}

ComplexVariable &ComplexVariable::operator+(double t){
	return *this;
}

ComplexVariable &ComplexVariable::operator+(std::complex<double>x){
	return *this;
}

ComplexVariable &solver::operator+(double t, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable();
	return *ans;
}

ComplexVariable &solver::operator+(std::complex<double> y, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable();
	return *ans;
}

ComplexVariable &ComplexVariable::operator-(const ComplexVariable &x){
	return *this;
}

ComplexVariable &ComplexVariable::operator-(double t){
	return *this;
}

ComplexVariable &ComplexVariable::operator-(std::complex<double>x){
	return *this;
}

ComplexVariable &solver::operator-(double t, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable();
	return *ans;
}

ComplexVariable &solver::operator-(std::complex<double> y, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable();
	return *ans;
}

ComplexVariable &ComplexVariable::operator/(const ComplexVariable &x){
	return *this;
}

ComplexVariable &ComplexVariable::operator/(double t){
	return *this;
}

ComplexVariable &ComplexVariable::operator/(std::complex<double>x){
	return *this;
}

ComplexVariable &solver::operator/(double t, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable();
	return *ans;
}

ComplexVariable &solver::operator/(std::complex<double> y, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable();
	return *ans;
}

ComplexVariable &ComplexVariable::operator==(const ComplexVariable &x){
	return *this;
}

ComplexVariable &ComplexVariable::operator==(double t){
	return *this;
}

ComplexVariable &ComplexVariable::operator==(std::complex<double>x){
	return *this;
}

ComplexVariable &solver::operator==(double t, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable();
	return *ans;
}

ComplexVariable &solver::operator==(std::complex<double> y, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable();
	return *ans;
}

ComplexVariable &ComplexVariable::operator^(int t){
	return *this;
}

double solver::solve(RealVariable &x){
	double ans;
	return ans;
}

std::complex<double> solver::solve(ComplexVariable &y){
	std::complex<double> ans;
	return ans;
}

