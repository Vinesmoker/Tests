#include<iostream>
using namespace std;

void Rand(int arr[], const int n, int min = 0, int max = 9);
void Print(int arr[], const int n);
void ShiftLeft(int arr[], const int n, int numOfShifts);
void ShiftRight(int arr[], const int n, int numOfShifts);
void Unique(int arr[], const int n);

void main ()
{
	const int n = 10;
	int arr[n] = {};
	int numOfShifts;
	Rand(arr, n);
	Print(arr, n);
	cout << "Enter the number of shifts of the array: "; cin >> numOfShifts;
	ShiftLeft(arr, n, numOfShifts);
	cout << endl;
	ShiftRight(arr, n, numOfShifts);
	Unique(arr, n);
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
void ShiftLeft(int arr[], const int n, int numOfShifts)
{
	for (int i = 0; i < numOfShifts; i++)
	{
		int buff = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buff;
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << "\t";
		}
	}
	cout << endl;
}
void ShiftRight(int arr[], const int n, int numOfShifts)
{
	for (int i = 0; i < numOfShifts; i++)
	{
		int buff = arr[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			arr[i + 1] = arr[i];
		}
		arr[0] = buff;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void Unique(int arr[], const int n)
{
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	bool random;
	for (int i = 0; i < n;)
	{
		random = false;
		int ranVal = min + rand() % (max - min);
		for (int j = 0; j < i; j++)
		{
			if (arr[j] == ranVal)
			{
				random = true;
				break;
			}
		}
		if (random == false)
		{
			arr[i] = ranVal; i++;
		}
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << "\t";
		}
	}
	
}