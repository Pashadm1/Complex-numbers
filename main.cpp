#include"complex.h"

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