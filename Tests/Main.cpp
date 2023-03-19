#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define Lesson

int StringLength(const char str[]);
void ToUpper(char str[]);
void ToLower(char str[]);
void Shrink(char str[]);
bool Polindrome(const char str[]);
void RemoveSymbol(const char str[], char symbol);
bool IsIntNumber(const char str[]);

void main()
{
	setlocale(LC_ALL, "");
#ifdef Lesson
	cout << "Hello Strings!";
	char str[] = { 'H', 'e', 'l', 'l', 'o', '\0' }; //����� ������ 0 - ���� int, �� ������� �� 1 ���� � ����� char.
	char str[] = "Hello";
	cout << str << endl;
	cout << sizeof(str) << endl;

	const int n = 20;
	char str[n] = {};
	cout << "������� ������: ";
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866); // - ��� �� ����������� � ��������� ������ ������.
	cout << str << endl;
#endif // Lesson

	const int n = 256;
	
	char str[n] = { "1"};
	//cout << "������� ������: ";
	SetConsoleCP(1251);
	//cin.getline(str, n);
	SetConsoleCP(866); // - ��� �� ����������� � ��������� ������ ������.
	cout << "�� ����� ������:\n" << str << " ������ " << StringLength(str) << " ��������" << endl;
	ToUpper(str);
	ToLower(str);
	Shrink(str);
	cout << str << endl;
	cout << "������ " << (Polindrome(str) ? "" : " �� ") << "���������: ";
	cout << str << endl;
	cout << IsIntNumber(str);
}


int StringLength(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void ToUpper(char str[])
{

	for (int i = 0; i < str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';
		if (str[i] >= '�' && str[i] <= '�')str[i] -= ' ';
		cout << str[i];
	}
	cout << endl;

	//for (int i = 0; str[i]; i++)str[i] = toupper(str[i]);
}
void ToLower(char str[])
{
	for (int i = 0; str[i]; i++)str[i] = tolower(str[i]);
}
void Shrink(char str[])
{
	for (int i = 0; i < str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; j < str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
void RemoveSymbol(char str[], char symbol)
{
	for (int i = 0; i < str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
}
bool Polindrome(const char str[])
{
	char* buffer = new char[strlen(str) + 1] {};
	for (int i = 0; i < strlen(str); i++)buffer[i] = str[i];
	ToLower(buffer);
	RemoveSymbol(buffer, ' ');
	int n = strlen(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}
bool IsIntNumber(const char str[])
{
	return 0;
}