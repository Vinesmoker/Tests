#include<iostream>
using namespace std;

void Rand(int arr[], const int n, int min = 0, int max = 9);
void Print(int arr[], const int n);
int ShiftLeft(int arr[], const int n, int cycle, int numOfShifts);

void main ()
{
	const int n = 10;
	int arr[n] = {};
	int cycle = 10, numOfShifts;
	Rand(arr, n);
	Print(arr, n);
	cout << "Enter the number of shifts of the array: "; cin >> numOfShifts;
	ShiftLeft(arr, n, cycle, numOfShifts);
	Print(arr, n);
}

void Rand(int arr[], const int n, int min, int max) 
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = min + rand() % (max - min);
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int ShiftLeft(int arr[], const int n, int cycle, int numOfShifts)
{
	for (int i = 0; i < cycle; i++)
	{
		for (int i = 0; i < numOfShifts; i++)
		{
			int buff = arr[0];
			for (int i = 0; i < n; i++)
			{
				arr[i] = arr[i + 1];
			}
			arr[n - 1] = buff;
		}
		return arr[i];
	}
}