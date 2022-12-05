#include<iostream>
using namespace std;

void Rand(int arr[], const int n, int min = 70, int max = 80);
void Print(int arr[], const int n);
int minValueIn(int arr[], const int n);
int maxValueIn(int arr[], const int n);
void ShiftLeft(int arr[], const int n, int numOfShifts);
void ShiftRight(int arr[], const int n, int numOfShifts);
void Search(int arr[], int arr2[], const int n);
int Unique(int arr[], const int n);

void main ()
{
	const int n = 10;
	int arr[n] = {}; int arr2[n]{};
	int numOfShifts;
	Rand(arr, n);
	Print(arr, n);
	cout << "Min value: " << minValueIn(arr, n) << endl;
	cout << "Max value: " << maxValueIn(arr, n) << endl;
	cout << "Enter the number of shifts of the array: "; cin >> numOfShifts;
	ShiftLeft(arr, n, numOfShifts);
	cout << endl;
	ShiftRight(arr, n, numOfShifts);
	cout << "Searching of repetitions: " << endl;
	Search(arr, arr2, n); 
	cout << endl;
	cout << "Unique numbers: " << endl;
	Unique(arr, n); Print(arr, n);
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
int minValueIn(int arr[], const int n)
{
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}
int maxValueIn(int arr[], const int n)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
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
		Print(arr, n);
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
		Print(arr, n);
	}
	cout << endl;
}
void Search(int arr[], int arr2[], const int n)
{
	
	int min = minValueIn(arr, n);
	int max = maxValueIn(arr, n);
	int count = 0;
	while (max - min < n)max++;
	for (int i = 0; i < n; i++)
	{
		arr[i] = min + rand() % (max - min);
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])count++;
		}
		arr2[i] = count; 
		count = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (arr2[i] != 0)cout << arr[i] << "\t" << arr2[i] << endl;
	}
}
int Unique(int arr[], const int n)
{
	bool random = false;
	for (int i = 0; i < n;)
	{
		int min = minValueIn(arr, n);
		int max = maxValueIn(arr, n);
		while (max - min < n)max++;
		bool random;
		for (int i = 0; i < n;)
		{
			random = false;
			int ranVal = rand() % (max - min) + (min);
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
		}
		return arr[n];
	}
}