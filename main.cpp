#include"complex.h"

void main()
{
	complex A, B;
	cout << "1. Load from files" << endl << "2. Type" << endl;
	int i;
	cin >> i;
	if (i == 1)
	{
		ifstream a("A.txt", ios::in);
		ifstream b("B.txt", ios::in);
		a >> A;
		b >> B;
	}
	if (i == 2)
	{
		cout << "A=";
		cin >> A;
		cout << "B=";
		cin >> B;
	}
	cout << "A=" << A << endl;
	cout << "B=" << B << endl;
	if (A == B)
	{
		cout << "A=B" << endl;
	}
	else
	{
		cout << "A=/=B" << endl;
	}
	complex *C = new complex(A*B);
	cout << "A*B=" << *C << endl;
	delete C;
	C = new complex(A * 2.0);
	cout << "A*2=" << *C << endl;
	delete C;
	C = new complex(A + B);
	cout << "A+B=" << *C << endl;
	delete C;
	C = new complex(A + 1.0);
	cout << "A+1=" << *C << endl;
	delete C;
	C = new complex(A - B);
	cout << "A-B=" << *C << endl;
	delete C;
	C = new complex(A - 1.0);
	cout << "A-1=" << *C << endl;
	delete C;
	try
	{
		C = new complex(A / B);
		cout << "A/B=" << *C << endl;
		delete C;
	}
	catch (exception ex)
	{
		cerr << ex.what() << endl;
	}
	ofstream a("A.txt", ios::out);
	ofstream b("B.txt", ios::out);
	a << A;
	b << B;
	system("pause");
}