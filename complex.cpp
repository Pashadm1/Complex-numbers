#include"complex.h"

double square(double a)
{
	return a*a;
}

ostream &operator<<(ostream &out, complex &obj)
{
	if (obj.real)
		cout << obj.real;
	if (obj.real&&obj.imaginary)
		if (obj.imaginary >= 0)
			cout << '+';
		else
		{
			cout << '-' << -obj.imaginary << 'i';
			return out;
		}
	if (obj.imaginary)
		cout << obj.imaginary << 'i';
	if (!obj.real && !obj.imaginary)
		cout << '0';
	return out;
}

istream &operator>>(istream &in, complex &obj)
{
	in >> obj.real;
	in >> obj.imaginary;
	return in;
}

ofstream &operator<<(ofstream &ofs, complex &obj)
{
	ofs << obj.real << " " << obj.imaginary;
	return ofs;
}

ifstream &operator>>(ifstream &ifs, complex &obj)
{
	ifs >> obj.real >> obj.imaginary;
	return ifs;
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

complex::complex(double val)
{
	real = val;
	imaginary = 0;
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

complex complex::operator*(const complex &B) const
{
	return complex(real*B.getReal() - imaginary*B.getImaginary(), imaginary*B.getReal() + real*B.getImaginary());
}

complex complex::operator*(const double &B) const
{
	return complex(real*B, imaginary*B);
}

complex operator*(const double &A, const complex &B)
{
	return complex(A*B.real, A*B.imaginary);
}

complex complex::operator+(const complex &B) const
{
	return complex(real + B.getReal(), imaginary + B.getImaginary());
}

complex complex::operator+(const double &B) const
{
	return complex(real + B, imaginary);
}

complex operator+(const double &A, const complex &B)
{
	return complex(A + B.real, B.imaginary);
}

complex complex::operator-(const complex &B) const
{
	return complex(real-B.getReal(),imaginary-B.getImaginary());
}

complex complex::operator-(const double &B) const
{
	return complex(real-B, imaginary);
}

complex operator-(const double &A, const complex &B)
{
	return complex(A - B.real, -B.imaginary);
}

complex complex::operator-() const
{
	return complex(-real, -imaginary);
}

complex complex::operator/(const complex &B) const
{
	if (!B.getReal() || !B.getImaginary())
	{
		throw(exception("Error: Division by 0"));
	}
	double a = square(B.getReal()) + square(B.getImaginary());
	return complex((real*B.getReal() + imaginary*B.getImaginary()) / a,
		(imaginary*B.getReal() - real*B.getImaginary()) / a);
}

complex complex::operator/(const double &B) const
{
	if (!B)
	{
		throw(exception("Error: Division by 0"));
	}
	double a = square(B);
	return complex((real*B) / a, (imaginary*B) / a);
}

complex operator/(const double &A, const complex &B)
{
	if (!B.real || !B.imaginary)
	{
		throw(exception("Error: Division by 0"));
	}
	double a = square(B.real) + square(B.imaginary);
	return complex((A*B.real) / a, (-A*B.imaginary) / a);
}

bool complex::operator==(const complex &B) const
{
	return (real == B.getReal() && imaginary == B.getImaginary());
}

bool operator==(const complex &A, const double &B)
{
	return (A.real == B && A.imaginary == 0);
}

bool operator==(const double &A, const complex &B)
{
	return (A == B.real && B.imaginary == 0);
}

bool complex::operator!=(const complex &B) const
{
	return !(*this == B);
}

bool operator!=(const complex &A, const double &B)
{
	return !(A == B);
}

bool operator!=(const double &A, const complex &B)
{
	return !(A == B);
}

complex &complex::operator=(const complex &B)
{
	real = B.getReal();
	imaginary = B.getImaginary();
	return *this;
}

complex::operator double()
{
	return real;
}

complex &complex::operator++()
{
	real++;
	imaginary++;
	return *this;
}

complex complex::operator++(int)
{
	complex tmp(*this);
	real++;
	imaginary++;
	return tmp;
}