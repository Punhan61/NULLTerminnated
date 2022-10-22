#include<iostream>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

int StringLength(const char str[]);
void upper_case(char str[]);
void lower_case(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);
void remove_symbol(char str[], const char symbol);
bool is_number(const char str[]);

//#define EXAMPLE_1
#define EXAMPLE_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef EXAMPLE_1
	//char str[] = { 'H','e','1','1','o',0 };
	char str[] = "Hello";
	//str[] - строковая переменная
	//"Hello" - строковая константа
	cout << str << endl;
	cout << typeid(str).name() << endl;
	cout << typeid("Hello").name() << endl;
#endif // EXAMPLE_1

	const int SIZE = 256;
	char str[SIZE] = "Аргентина манит негра";
	cout << "Введение строку: ";
	//cin >> str;
	//SetConsoleCP(1251);
	cin.getline(str, SIZE);
	//SetConsoleCP(886);
	//cout << str << endl;
	/*cout << "Длина строки: " << StringLength(str) << endl;
	cout << "Длина строки: " << strlen(str) << endl;*/

	//lower_case(str);
	//cout << str << endl;

	//shrink(str);
	//cout << str << endl;
	
	//cout <<"Строка " <<(is_palindrome(str) ? "" : "НЕ ") << "является палиндромом";
	is_number(str);
	cout << str << endl;
}
int StringLength(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void upper_case(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
		if (str[i] >= 'а' && str[i] <= 'я') str[i] -= 32;
		if (str[i] == 'ё')str[i] = 'Ё';*/
		str[i] = toupper(str[i]);
	}
}
void lower_case(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = tolower(str[i]);
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while(str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
void remove_symbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
}
bool is_palindrome(char str[])
{
	char* buffer = new char[strlen(str) + 1]{};
	strcpy(buffer, str);
	lower_case(buffer);
	remove_symbol(buffer, ' ');
	int size = strlen(buffer);
	for (int i = 0; i < size; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[]buffer;
			return false;
		}
	}
	delete[]buffer;
	return true;
}
bool is_number(const char str[])
{
	char* buffer = new char[strlen(str)];
	for (int i = 0; str[i]; i++)
	{
		buffer[i]=str[i] % 2;
		delete[]buffer;
		return false;
	}
	delete[]buffer;
	return true;
}