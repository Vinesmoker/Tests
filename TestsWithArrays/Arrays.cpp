#include<iostream>
using namespace std;

void main()
{
	int const n = 10;
	int arr[n]{}; int arr2[n]{};
	int min = 0; int max = 9;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (max - min) + min; cout << arr[i] << "\t";
	}
	cout << "\n\n";
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min) + min;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        arr2[i] = count;
        count = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr2[i] != 0)cout << arr[i] << '\t' << arr2[i] << endl;
    }
}