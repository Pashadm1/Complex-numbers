#include"complex.h"

void main()
{
	complex A(3,4);
	cout << "A=";
	A.show();
	cout << endl;
	complex B(2,4);
	cout << "B=";
	B.show();
	cout << endl;
	complex *C = new complex(A.multiply(B));
	cout << "A*B=";
	C->show();
	cout << endl;
	delete C;
	C = new complex(A.sum(B));
	cout << "A+B=";
	C->show();
	cout << endl;
	delete C;
	C = new complex(A.sub(B));
	cout << "A-B=";
	C->show();
	cout << endl;
	delete C;
	C = new complex(A.div(B));
	cout << "A/B=";
	C->show();
	cout << endl;
	delete C;
	system("pause");
}