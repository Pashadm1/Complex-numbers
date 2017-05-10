#include"complex.h"

double square(double a)
{
	return a*a;
}

complex::complex()
{
	real = 0;
	imaginary = 0;
	cout << "Constructor\n";
}

complex::complex(double a, double b)
{
	real = a;
	imaginary = b;
	cout << "Constructor\n";
}

complex::complex(const complex &B)
{
	real = B.getReal();
	imaginary = B.getImaginary();
	cout << "Constructor\n";
}

complex::~complex()
{
	cout << "Destructor\n";
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
	if (real)
		cout << real;
	if (real&&imaginary)
		if (imaginary >= 0)
			cout << '+';
		else
		{
			cout << '-' << -imaginary << 'i';
			return;
		}
	if (imaginary)
		cout << imaginary << 'i';
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