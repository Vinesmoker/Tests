#include<iostream>
using namespace std;

void main()
{
	int x = 10;
	int* p = &x;
	int y = *p;
	*p = 45;
	cout << p << "\t" << *p << "\t" << &x << "\t" << x << "\t" << y << endl;
	cout << &y;
}