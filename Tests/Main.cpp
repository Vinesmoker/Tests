#include<iostream>
using namespace std;

void Unique(float arr[], const int n, int min = 0, int max = 9);

void main ()
{
	const int n = 10;
	float arr[n]{};
	Unique(arr, n); cout << endl;
}

void Unique (float arr[], const int n, int min, int max)
{
	int c = n;
	for (int i = 0; i < c; i++)
	{
		while ((max - min) < n)max++;
		bool ran = false;
		arr[i] =  min + rand() % (max - min); arr[i] /= 100;
		float buff = arr[i];
		for (int j = 0; j < i; j++)
		{
			if (i == j)continue;
			if (buff == arr[j] && i != j)ran = true; c++;
		}
		if (!ran)cout << buff << "\t"; 
	}
}