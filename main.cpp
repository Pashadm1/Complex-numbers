#include"complex.h"

void main()
{
	complex A(3,4);
	cout << "A=";
	A.show();
	complex B(2,4);
	cout << "B=";
	B.show();
	complex *C = new complex(A.multiply(B));
	cout << "A*B=";
	C->show();
	delete C;
	C = new complex(A.sum(B));
	cout << "A+B=";
	C->show();
	delete C;
	C = new complex(A.sub(B));
	cout << "A-B=";
	C->show();
	delete C;
	C = new complex(A.div(B));
	cout << "A/B=";
	C->show();
	system("pause");
}