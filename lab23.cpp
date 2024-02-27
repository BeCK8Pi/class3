#include<iostream>
#include<cmath>

using namespace std;



class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		friend ComplexNumber operator+(const ComplexNumber &,const ComplexNumber &);
		friend ComplexNumber operator-(const ComplexNumber &,const ComplexNumber &);
		friend ComplexNumber operator*(const ComplexNumber &,const ComplexNumber &);
		friend ComplexNumber operator/(const ComplexNumber &,const ComplexNumber &);
		friend bool operator==(const ComplexNumber &,const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber operator+(const ComplexNumber &z1,const ComplexNumber &z2){
	return ComplexNumber(z1.real+z2.real,z1.imag+z2.imag);
}

ComplexNumber operator-(const ComplexNumber &z1,const ComplexNumber &z2){
	return ComplexNumber(z1.real-z2.real,z1.imag-z2.imag);
}

ComplexNumber operator*(const ComplexNumber &z1,const ComplexNumber &z2){
	ComplexNumber a(z1),b(z2);
	double r = a.abs()*b.abs();
	double theta = a.angle()+b.angle();
	theta = theta*M_PI/180;
	return ComplexNumber(r*cos(theta),r*sin(theta));
}

ComplexNumber operator/(const ComplexNumber &z1,const ComplexNumber &z2){
	ComplexNumber a(z1),b(z2);
	double r = a.abs()/b.abs();
	double theta = a.angle()-b.angle();
	theta = theta*M_PI/180;
	return ComplexNumber(r*cos(theta),r*sin(theta));
}

bool operator==(const ComplexNumber &z1,const ComplexNumber &z2){
	if(z1.real == z2.real && z1.imag == z2.imag) return true;
	else return false;
}

double ComplexNumber::abs(){
	return sqrt(pow(real,2)+pow(imag,2));
}

double ComplexNumber::angle(){
	if(real>=0 && imag >= 0) return atan(imag/real)*180/M_PI;
	if(real<=0 && imag >= 0) return atan(imag/real)*180/M_PI+180;
	if(real<=0 && imag <= 0) return atan(imag/real)*180/M_PI-180;
	if(real>=0 && imag <= 0) return atan(imag/real)*180/M_PI;
	return 0;
}

ostream &operator<<(ostream &os, const ComplexNumber &z){
	if(z.real == 0 && z.imag == 0 ) return os << "0";
	if(z.imag == 0) return os << z.real;
	if(z.real == 0) return os << z.imag << "i";
	if(z.imag < 0) return os << z.real << z.imag << "i";
	else  return os << z.real << "+" << z.imag << "i";
}

//Write your code here

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





