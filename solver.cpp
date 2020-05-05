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
	RealVariable *ans=new RealVariable(c1*t, c2*t, c3*t);
	return *ans;
}

RealVariable &RealVariable::operator*(const RealVariable &x){
	if(c1*x.c1 !=0 || (c1*x.c2+c2*x.c1)!=0){ //checking if the power is greather than 2
		throw runtime_error("Max power is 2");
	}
	double a=c1*x.c3+c2*x.c2+c3*x.c1;
	double b=c2*x.c3+c3*x.c2;
	double c= c3*x.c3;
	RealVariable *ans=new RealVariable(a,b,c);
	return *ans;
}

RealVariable &solver::operator*(double t, const RealVariable &x){
	RealVariable *ans= new RealVariable(t*x.c1,t*x.c2,t*x.c3);
	return *ans;
}

RealVariable &RealVariable::operator+(double t){
	RealVariable *ans= new RealVariable(c1,c2,c3+t);
	return *ans;
}

RealVariable &RealVariable::operator+(const RealVariable &x){
	RealVariable *ans= new RealVariable(c1+x.c1,c2+x.c2,c3+x.c3);
	return *ans;
}

RealVariable &solver::operator+(double t, const RealVariable &x){
	RealVariable *ans= new RealVariable(x.c1,x.c2,x.c3+t);
	return *ans;
}

RealVariable &RealVariable::operator-(double t){
	RealVariable *ans= new RealVariable(c1,c2,c3-t);
	return *ans;
}

RealVariable &RealVariable::operator-(const RealVariable &x){
	RealVariable *ans=new RealVariable(c1-x.c1,c2-x.c2,c3-x.c3);
	return *ans;
}

RealVariable &solver::operator-(double t, const RealVariable &x){
	RealVariable *ans= new RealVariable(-x.c1,-x.c2,t-x.c3);
	return *ans;
}

RealVariable &RealVariable::operator/(double t){
	if(t==0){
		throw runtime_error("Cant divide by zero!!");
	}
	RealVariable *ans= new RealVariable(c1/t,c2/t,c3/t);
	return *ans;
}

RealVariable &solver::operator/(double t, const RealVariable &x){
	if(x.c1==0 ||x.c2==0 ||x.c3==0){
		throw runtime_error("Cant divide by zero!!");
	}
	RealVariable *ans= new RealVariable(t/x.c1, t/x.c2, t/x.c3);
	return *ans;
}

RealVariable &RealVariable::operator==(double t){
	RealVariable *ans=new RealVariable(c1,c2,c3-t);
	return *ans;
}

RealVariable &RealVariable::operator==(const RealVariable &x){
	RealVariable *ans=new RealVariable(c1-x.c1, c2-x.c2, c3-x.c3);
	return *ans;
}

RealVariable &solver::operator==(double t, const RealVariable &x){
	RealVariable *ans= new RealVariable(x.c1, x.c2, x.c3-t);
	return *ans;
}

RealVariable &RealVariable::operator^(int t){
	RealVariable *ans;
	if(t<0 || t<2 ||(c1 != 0 && t>1)){
		throw runtime_error( "Wrong pow input");
	}
	if (t==0){
		ans= new RealVariable(0,0,1);
	}
	else if(t ==1){
		ans=new RealVariable(c1,c2,c3);
	}
	else{
		RealVariable x(c1, c2, c3);
		RealVariable y(c1, c2, c3);
		ans=&(x*y);
	}
	return *ans;
}

double solver::solve(RealVariable &x){
	if(x.getc1() ==0 && x.getc2()==0 && x.getc3()==0){
		throw runtime_error ("There are infinite solutions");
	}
	if(x.getc1()==0){
		if(x.getc2()==0){
			throw runtime_error("There is no solution for this");
		}
		return (-x.getc3()/x.getc2());
	}
	double d=pow(x.getc2(),2)-4*x.getc1()*x.getc3();
	if(d<0){
		throw runtime_error("There is no solution for this");
	}
	return ((-x.getc2())+sqrt(d))/(2*x.getc1());
}
////////////////////Complex////////////////////////////////////
ComplexVariable &ComplexVariable::operator*(const ComplexVariable &x){
	
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


std::complex<double> solver::solve(ComplexVariable &y){
	std::complex<double> ans;
	return ans;
}

