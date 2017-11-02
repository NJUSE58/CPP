#include<iostream>
#include<string>
using namespace std;

bool compare(string str1, string str2);

int main()
{
	int n;
	cin >> n;
	string * str = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (compare(str[i], str[j])) {
				string temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << str[i];
		if (i != n - 1)
			cout << endl;
	}

	delete[] str;
	
	return 0;
}

bool compare(string str1, string str2)
{
	if (str1.length() > str2.length()) {
		return true;
	}
	else if (str1.length() < str2.length()) {
		return false;
	}

	int len = str1.length();
	for (int i = 0; i < len; i++) {
		char ch1 = str1[i], ch2 = str2[i];
		if (tolower(ch1) > tolower(ch2)) return true;
		else if (tolower(ch1) < tolower(ch2)) return false;

		else {
			if (isupper(str1[i]) && islower(str2[i])) return true;
			else if (islower(str1[i]) && isupper(str2[i])) return false;
		}
	}

	return false;
}

