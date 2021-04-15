#include <iostream>
#include <../polinom_lib/Monom.h>
#include <../polinom_lib/Polinom.h>
using namespace std;
int main()
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;

	TMonom a(data, 3, 1);

	double* data1 = new double[3];
	data1[0] = 1;
	data1[1] = 0;
	data1[2] = 4;
	TMonom b(data1, 3, 2);

	TMonom c;
	c = a * b;

	cout << a << endl << b << endl <<c << endl;

	TPolinom p1, p2;
	p1 += c;
	p1 += a;
	cout << "p1 = " << p1 << endl;

	p2 += a;
	p2 += a;
	cout << "p2 = " << p2 << endl;

	TPolinom p3 = p1 + p2;
	cout << "p1 + p2 = " << p3 << endl;

	TPolinom p4 = p1 - p2;
	cout << "p1 - p2 = " << p4 << endl;

	TPolinom p5 = p1 * p2;
	cout << "p1 * p2 = " << p5 << endl;

	return 0;
}
