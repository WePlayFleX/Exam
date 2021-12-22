#include <iostream>

using namespace std;

int mystrlen(const char *str);
char* mystrcpy(char *str1, const char *str2);
char* mystrcat(char *str1, const char *str2);
char* mystrchr(char *str, char s);
char* mystrstr(char *str1, char *str2);
int mystrcmp(const char *str1, const char *str2);
int stringToNumber(char *str);
char* numberToString(int number);
char* uppercase(char *str1);
char* lowercase(char *str1);
char* mystrrev(char *str);

int main()
{
	char *str1 = new char[1000]{ "1 Sherlock Holmes and I surveyed this curt announcement and the rueful face behind it, 2 until the comical side of the affair so completely overtopped every other consideration that we both burst out into a roar of laughter." };
	char *str2 = new char[1000]{ "I observe that there is a good deal of German music on the programme, which is rather more to my taste than Italian or French." };
	
	cout << "Hello. It is a small library of string functions. Let's go! " << endl;

	int choise = 0;

	do
	{
		system("pause");
		system("cls");

		cout << "Here are the features: " << endl;
		cout << "1 - Determining the length of the string " << endl;
		cout << "2 - Copy a string to a buffer pointed to by another string " << endl;
		cout << "3 - Joining the second line to the first " << endl;
		cout << "4 - Search for a character in a string " << endl;
		cout << "5 - Search for a substring in another string " << endl;
		cout << "6 - Comparing two strings " << endl;
		cout << "7 - Convert string to number " << endl;
		cout << "8 - Convert number to string " << endl;
		cout << "9 - Convert string to uppercase " << endl;
		cout << "10 - Convert string to lowercase " << endl;
		cout << "11 - Reverse line " << endl;
		cout << "12 - Exit " << endl;

		cin >> choise;

		switch (choise)
		{
		case 1:
		{
			int l = mystrlen(str1);
			cout << "The lenght of string " << l << endl;
		}
			break;
		case 2:
		{
			cout << "A string at once: " << endl << str2 << endl;
			str2 = mystrcpy(str2, str1);
			cout << "Line after: " << endl <<  str2 << endl;
		}
			break;
		case 3:
		{
			cout << "A string at once: " << str2 << endl;
			str2 = mystrcat(str2, str1);
			cout << "Line after: " << str2 << endl;
		}
			break;
		case 4:
		{
			char *strNew = new char[1000];
			cout << "Search line: " << endl << str1 << endl;
			char var = '\0';
			cout << "Enter a character to search: ";
			cin >> var;
			strNew = mystrchr(str1, var);
			cout << "First found character: " << strNew << endl;
			delete[] strNew;
		}
			break;
		case 5:
		{
			char *strNew = new char[1000];
			char *strNew1 = new char[1000];
			cout << "Search line: " << endl << str1 << endl;
			cout << "Enter your search text: ";
			cin >> strNew;
			strNew1 = mystrstr(str1, strNew);
			cout << "First found character: " << strNew1 << endl;
			delete[] strNew;
			delete[] strNew1;
		}
			break;
		case 6:
		{
			int cons = 0;
			cout << "First string: " << endl << str1 << endl;
			cout << "Second string: " << endl << str2 << endl;
			cons = mystrcmp(str1, str2);
			cout << "Compaire result: " << cons << endl;
		}
			break;
		case 7:
		{
			char *var = new char[1000];
			int num = 0;
			cout << "Enter the line: " << endl;
			cin >> var;
			num = stringToNumber(var);
			cout << "Convert result: " << num << endl;
			delete[] var;
		}
			break;
		case 8:
		{
			char *var = new char[1000];
			int num = 0;
			cout << "Enter a number: ";
			cin >> num;
			var = numberToString(num);
			cout << "Convert result: " << var << endl;
		}
			break;
		case 9:
		{
			cout << "String: " << endl << str1 << endl;
			str1 = uppercase(str1);
			cout << "Result: " << endl << str1 << endl;
		}
			break;
		case 10:
		{
			cout << "String: " << endl << str1 << endl;
			str1 = lowercase(str1);
			cout << "Result: " << endl << str1 << endl;
		}
			break;
		case 11:
		{
			char *strNew = new char[1000];
			cout << "String: " << endl << str1 << endl;
			strNew = mystrrev(str1);
			cout << "Result: " << endl << strNew << endl;
			delete[] strNew;
		}
			break;
		case 12:
			goto _EXIT;
			break;
		default:
			cerr << "Error. Re-enter (" << endl;
			break;
		}
	}
	while (choise);
	_EXIT:
	delete[] str1;
	delete[] str2;

	system("pause");
	return 0;
}

int mystrlen(const char *str1)
{
	int i = 0;

	while (str1[i] != '\0')
	{
		i++;
	}
	return i;
}
char* mystrcpy(char *str1, const char *str2)
{
	int i = 0;

	while (str2[i] != '\0')
	{
		str1[i] = str2[i];
		i++;
	}
	return str1;
}
char* mystrcat(char *str1, const char *str2)
{
	int i = mystrlen(str1);
	int j = 0;

	while (str2[j] != '\0')
	{
		str1[i] = str2[j];
		j++;
		i++;
	}
	return str1;
}
char* mystrchr(char *str1, char s)
{
	int i = 0;

	while (str1[i] != '\0')
	{
		if (str1[i] == s)
		{
			return &(str1[i]);
		}
		i++;
	}
	return nullptr;
}
char* mystrstr(char *str1, char *str2)
{
	int size = mystrlen(str1), size2 = mystrlen(str2);
	char *res;
	bool equ = false;

	for (size_t i = 0; i < size; i++)
	{
		if (str1[i] == str2[0])
		{
			res = &(str1[i]);

			for (size_t j = 0; j < size2; j++)
			{
				if (str1[i + j] == str2[j])
				{
					equ = true;
				}
				else
				{
					equ = false;
				}
			}
			if (equ)
			{
				return res;
			}
		}
	}
	return nullptr;
}
int mystrcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (true)
	{
		if (mystrlen(str1) < mystrlen(str2))
		{
			return -1;
		}
		else if (mystrlen(str1) > mystrlen(str2))
		{
			return 1;
		}
		else
		{
			if (str1[i] == str2[i])
			{
				i++;

				if (str1[i] == '\0' && str2[i] == '\0')
				{
					return 0;
				}
			}
			else
			{
				if (str1[i] > str2[i])
				{
					return 1;
				}
				else
				{
					return -1;
				}
			}
		}
	}
}
int stringToNumber(char *str1)
{
	int num = 0;
	int i = 0;

	while (str1[i] >= 48 && str1[i] <= 57)
	{
		num += str1[i] - 48;
		num *= 10;
		i++;
	}
	num /= 10;

	return num;
}
char* numberToString(int num)
{
	char s[24], t, *temp;
	int i = 0, k = num;
	i = 0;

	do {
		t = k % 10;
		k /= 10;
		s[i] = t + 48;
		i++;
	} while (k > 0);

	temp = new char[i];
	k = 0;
	i--;

	while (i >= 0)
	{
		temp[k] = s[i];
		i--;
		k++;
	}
	temp[k] = '\0';

	return temp;
}
char* uppercase(char *str1)
{
	char *res = str1;
	int i = 0;

	while (res[i] != '\0')
	{
		if (res[i] >= 97 && res[i] <= 122)
		{
			res[i] -= 32;
		}
		i++;
	}
	return res;
}
char* lowercase(char *str1)
{
	char *res = str1;
	int i = 0;

	while (res[i] != '\0')
	{
		if (res[i] >= 65 && res[i] <= 90)
		{
			res[i] += 32;
		}
		i++;
	}
	return res;
}
char* mystrrev(char *str1)
{
	int i = 0;

	while (str1[i] != '\0')
	{
		if (str1[i] >= 97 && str1[i] <= 122)
		{
			str1[i] -= 32;
		}
		else if (str1[i] >= 65 && str1[i] <= 90)
		{
			str1[i] += 32;
		}
		i++;
	}
	return str1;
}