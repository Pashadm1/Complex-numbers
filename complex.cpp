#include<iostream>
using namespace std;

double square(double a)
{
	return a*a;
}

class complex
{
	double real;
	double imaginary;
public:
	complex();
	double getReal() const;
	double getImaginary() const;
	void setReal(double value);
	void setImaginary(double value);
	void show() const;
	complex multiply(const complex &B) const;
	complex sum(const complex &B) const;
	complex sub(const complex &B) const;
	complex div(const complex &B) const;
};

complex::complex()
{
	real = 0;
	imaginary = 0;
}

double complex::getReal() const
{
	return real;
}

double complex::getImaginary() const
{
	return imaginary;
}

void complex::setReal(double value)
{
	real = value;
}

void complex::setImaginary(double value)
{
	imaginary = value;
}

void complex::show() const
{
	cout << real << '+' << imaginary << 'i' << endl;
}

complex complex::multiply(const complex &B) const
{
	complex C;
	C.setReal(real*B.getReal() - imaginary*B.getImaginary());
	C.setImaginary(imaginary*B.getReal() + real*B.getImaginary());
	return C;
}

complex complex::sum(const complex &B) const
{
	complex C;
	C.setReal(real + B.getReal());
	C.setReal(imaginary + B.getImaginary());
	return C;
}

complex complex::sub(const complex &B) const
{
	complex C;
	C.setReal(real - B.getReal());
	C.setImaginary(imaginary - B.getImaginary());
	return C;
}

complex complex::div(const complex &B) const
{
	complex C;
	C.setReal((real*B.getReal() + imaginary*B.getImaginary()) / (square(B.getReal()) + square(B.getImaginary())));
	C.setImaginary((imaginary*B.getReal() - real*B.getImaginary()) / (square(B.getReal()) + square(B.getImaginary())));
	return C;
}

void main()
{
	complex A;
	A.setReal(2);
	A.setImaginary(4);
	cout << "A=";
	A.show();
	complex B;
	B.setReal(3);
	B.setImaginary(6);
	cout << "B=";
	B.show();
	complex C;
	C = A.multiply(B);
	cout << "A*B=";
	C.show();
	C = A.sum(B);
	cout << "A+B=";
	C.show();
	C = A.sub(B);
	cout << "A-B=";
	C.show();
	C = A.div(B);
	cout << "A/B=";
	C.show();
	system("pause");
}