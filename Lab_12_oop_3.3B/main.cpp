#include <iostream>
#include "Rational.h"
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Rational r{ 14, 2 }, r1{7};
	cout << r << endl;
	Pair p = r;
	cout << p << endl;
	cout << r / r1 << endl;
	cin >> r;

	return 0;
}