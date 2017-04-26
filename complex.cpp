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
	complex() { real = 0; imaginary = 0; }
	double getReal();
	double getImaginary();
	void setReal(double value);
	void setImaginary(double value);
	void show();
	complex multiply(complex B);
	complex sum(complex B);
	complex sub(complex B);
	complex div(complex B);
};

double complex::getReal()
{
	return real;
}

double complex::getImaginary()
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

void complex::show()
{
	cout << real << '+' << imaginary << 'i' << endl;
}

complex complex::multiply(complex B)
{
	complex C;
	C.setReal(real*B.getReal() - imaginary*B.getImaginary());
	C.setImaginary(imaginary*B.getReal() + real*B.getImaginary());
	return C;
}

complex complex::sum(complex B)
{
	complex C;
	C.setReal(real + B.getReal());
	C.setReal(imaginary + B.getImaginary());
	return C;
}

complex complex::sub(complex B)
{
	complex C;
	C.setReal(real - B.getReal());
	C.setImaginary(imaginary - B.getImaginary());
	return C;
}

complex complex::div(complex B)
{
	complex C;
	C.setReal((real*B.getReal() + imaginary*B.getImaginary()) / (square(B.getReal()) + square(B.getImaginary())));
	C.setImaginary((imaginary*B.getReal() - real*B.getImaginary()) / (square(B.getReal()) + square(B.getImaginary())));
	return C;
}

void main()
{
	complex A;
	double temp;
	cout << "Enter real part:" << endl;
	cin >> temp;
	A.setReal(temp);
	cout << "Enter imaginary part:" << endl;
	cin >> temp;
	A.setImaginary(temp);
	cout << "Complex number:" << endl;
	A.show();
	system("pause");
}