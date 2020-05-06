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
	std::complex<double> zero= std::complex<double>(0,0);
	if(c1*x.c1!= zero||(c1*x.c2+c2*x.c1)!=zero){
		throw runtime_error ("Power cant be higher than 2");
	}
	std::complex<double> a=c1*x.c3+c2*x.c2+c3*x.c1;
	std::complex<double> b=c2*x.c3+c3*x.c2;
	std::complex<double> c=c3*x.c3;
	ComplexVariable *ans= new ComplexVariable(a,b,c);
	return *ans;
}

ComplexVariable &ComplexVariable::operator*(double t){
	std::complex<double> complexT=std::complex<double>(t,0);
	ComplexVariable temp(c1,c2,c3);
	ComplexVariable *ans=&(temp*complexT);
	return *ans;
}

ComplexVariable &ComplexVariable::operator*(std::complex<double>x){
	ComplexVariable *ans=new ComplexVariable(c1*x,c2*x,c3*x);
	return *ans;
}

ComplexVariable &solver::operator*(double t, const ComplexVariable &x){
	std::complex<double> complexT=std::complex<double>(t,0);
	ComplexVariable temp(x.c1,x.c2,x.c3);
	ComplexVariable *ans=&(temp*complexT);
	return *ans;
}

ComplexVariable &solver::operator*(std::complex<double> y, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable(x.c1*y,x.c2*y,x.c3*y);
	return *ans;
}

ComplexVariable &ComplexVariable::operator+(const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable(c1+x.c1,c2+x.c2,c3+x.c3);
	return *ans;
}

ComplexVariable &ComplexVariable::operator+(double t){
	ComplexVariable *ans=new ComplexVariable(c1,c2,c3+t);
	return *ans;
}

ComplexVariable &ComplexVariable::operator+(std::complex<double>x){
	ComplexVariable *ans=new ComplexVariable(c1,c2,c3+x);
	return *ans;
}

ComplexVariable &solver::operator+(double t, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable(x.c1,x.c2,x.c3+t);
	return *ans;
}

ComplexVariable &solver::operator+(std::complex<double> y, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable(x.c1,x.c2,x.c3+y);
	return *ans;
}

ComplexVariable &ComplexVariable::operator-(const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable(c1-x.c1,c2-x.c2,c3-x.c3);
	return *ans;
}

ComplexVariable &ComplexVariable::operator-(double t){
	ComplexVariable *ans=new ComplexVariable(c1,c2,c3-t);
	return *ans;
}

ComplexVariable &ComplexVariable::operator-(std::complex<double>x){
	ComplexVariable *ans=new ComplexVariable(c1,c2,c3-x);
	return *ans;
}

ComplexVariable &solver::operator-(double t, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable(-x.c1,-x.c2,t-x.c3);
	return *ans;
}

ComplexVariable &solver::operator-(std::complex<double> y, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable(-x.c1,-x.c2,y-x.c3);
	return *ans;
}

ComplexVariable &ComplexVariable::operator/(double t){
	if(t==0){
		throw runtime_error("cant divide by zero");
	}
	ComplexVariable *ans=new ComplexVariable(c1/t,c2/t,c3/t);
	return *ans;
}

ComplexVariable &ComplexVariable::operator/(std::complex<double>x){
	std::complex<double> zero = std::complex<double>(0, 0);
	if(x==zero){
		throw runtime_error("cant divide by zero");
	}
	ComplexVariable *ans=new ComplexVariable(c1/x,c2/x,c3/x);
	return *ans;
}

ComplexVariable &solver::operator/(double t, const ComplexVariable &x){
	std::complex<double> zero = std::complex<double>(0,0);
	if(x.c1==zero ||x.c2==zero || x.c3 == zero){
		throw runtime_error("cant divide by zero");
	}
	ComplexVariable *ans=new ComplexVariable(t/x.c1,t/x.c2,t/x.c3);
	return *ans;
}

ComplexVariable &solver::operator/(std::complex<double> y, const ComplexVariable &x){
	std::complex<double> zero = std::complex<double>(0,0);
	if(x.c1==zero ||x.c2==zero || x.c3 == zero){
		throw runtime_error("cant divide by zero");
	}
	ComplexVariable *ans=new ComplexVariable(y/x.c1,y/x.c2,y/x.c3);
	return *ans;
}

ComplexVariable &ComplexVariable::operator==(const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable(c1-x.c1,c2-x.c2,c3-x.c3);
	return *ans;
}

ComplexVariable &ComplexVariable::operator==(double t){
	ComplexVariable *ans=new ComplexVariable(c1,c2,c3-t);
	return *ans;
}

ComplexVariable &ComplexVariable::operator==(std::complex<double>x){
	ComplexVariable *ans=new ComplexVariable(c1,c2,c3-x);
	return *ans;
}

ComplexVariable &solver::operator==(double t, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable(x.c1,x.c2,x.c3-t);
	return *ans;
}

ComplexVariable &solver::operator==(std::complex<double> y, const ComplexVariable &x){
	ComplexVariable *ans=new ComplexVariable(x.c1,x.c2,x.c3-y);
	return *ans;
}

ComplexVariable &ComplexVariable::operator^(int t){
	ComplexVariable *ans;
	std::complex<double> zero = std::complex<double>(0,0);
	if(t<0 || t>2 || (c1!=zero && t>1)){
		throw runtime_error("power cant be higher than 2 or negative");
	}
	if(t==0){
		ans=new ComplexVariable(0,0,1);
		return *ans;
	} else if(t==1){
		ans=new ComplexVariable(c1,c2,c3);
		return *ans;
	}
	else{
		ComplexVariable y(c1,c2,c3);
		ComplexVariable z(c1,c2,c3);
		ans=&(y*z);
		return *ans;
	}
}


std::complex<double> solver::solve(ComplexVariable &y){
	std::complex<double> zero = std::complex<double>(0,0);
	if(y.getc1()==zero && y.getc2()==zero && y.getc3()==zero){
		throw runtime_error ("there are infinite solutions");
	}
	if(y.getc1()==zero){
		if(y.getc2()==zero){
			throw runtime_error ("no solutions for this");
		}
		return (-y.getc3()/y.getc2());
	}
	std::complex<double> d=pow(y.getc2(),2)-4.0*y.getc1()*y.getc3();
	return ((-y.getc2())+sqrt(d))/(2.0*y.getc1());
}

