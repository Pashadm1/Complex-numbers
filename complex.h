#include<iostream>
#include<fstream>
using namespace std;

double square(double a);
class complex
{
	double real;
	double imaginary;
public:
	complex();
	complex(double a, double b);
	complex(const complex &B);
	complex(double val);
	~complex();
	double getReal() const;
	double getImaginary() const;
	void setReal(double value);
	void setImaginary(double value);
	complex operator*(const complex &B) const;
	complex operator*(const double &B) const;
	friend complex operator*(const double &A, const complex &B);
	complex operator+(const complex &B) const;
	complex operator+(const double &B) const;
	friend complex operator+(const double &A, const complex &B);
	complex operator-(const complex &B) const;
	complex operator-(const double &B) const;
	friend complex operator-(const double &A, const complex &B);
	complex operator-() const;
	complex operator/(const complex &B) const;
	complex operator/(const double &B) const;
	friend complex operator/(const double &A, const complex &B);
	friend ostream &operator<<(ostream &out, complex &obj);
	friend istream &operator>>(istream &in, complex &obj);
	friend ofstream &operator<<(ofstream &ofs, complex &obj);
	friend ifstream &operator>>(ifstream &ifs, complex &obj);
	bool operator==(const complex &B) const;
	friend bool operator==(const complex &A, const double &B);
	friend bool operator==(const double &A, const complex &B);
	bool operator!=(const complex &B) const;
	friend bool operator!=(const complex &A, const double &B);
	friend bool operator!=(const double &A, const complex &B);
	operator double();
	complex &operator=(const complex &B);
	complex &complex::operator++();
	complex complex::operator++(int);
};