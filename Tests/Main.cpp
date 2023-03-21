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
bool IsIntNumber(const std::string& str);
int OutputIntNumber(int arg1, char* arg2[]);


void main()
{
	setlocale(LC_ALL, "");
#ifdef Lesson
	cout << "Hello Strings!";
	char str[] = { 'H', 'e', 'l', 'l', 'o', '\0' }; //Можно просто 0 - типа int, он ужмется до 1 бита и будет char.
	char str[] = "Hello";
	cout << str << endl;
	cout << sizeof(str) << endl;

	const int n = 20;
	char str[n] = {};
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866); // - это не обязательно в последней версии студии.
	cout << str << endl;
#endif // Lesson

	const int n = 256;
	int arg1; int arg2[size];
	char str[n] = { "sdfsdfsdf"};
	//cout << "Введите строку: ";
	SetConsoleCP(1251);
	//cin.getline(str, n);
	SetConsoleCP(866); // - это не обязательно в последней версии студии.
	cout << "Вы ввели строку:\n" << str << " длиной " << StringLength(str) << " символов" << endl;
	ToUpper(str);
	ToLower(str);
	Shrink(str);
	cout << str << endl;
	cout << "Строка " << (Polindrome(str) ? "" : " не ") << "палиндром: ";
	cout << str << endl;
	cout << IsIntNumber(str) << endl; cout << OutputIntNumber(arg1, arg2[size]);
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
		if (str[i] >= 'а' && str[i] <= 'я')str[i] -= ' ';
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
bool IsIntNumber(const std::string& str)
{
	if (str.empty())
	{
		return false;
	}
	for (char c: str)
	{
		if (!isdigit(c))return false;
	}
	return true;
}
int OutputIntNumber(int arg1, char* arg2[])
{
	if (arg1 <= 1) {
		std::cout << "Usage: " << arg2[0] << " number\n";
		return 1;
	}

	std::string str = arg2[1];

	if (IsIntNumber(str)) {
		int num = std::atoi(str.c_str());
		std::cout << "The number is: " << num << '\n';
	}
	else {
		std::cout << "Invalid input: " << str << " is not a decimal number\n";
	}

	return 0;
}