#include<iostream>
using namespace std;

double square(double a);
class complex
{
	double real;
	double imaginary;
public:
	complex();
	complex(const complex &B);
	~complex();
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