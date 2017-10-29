#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;

int ThirteenToTen(string str)
{
	int num = 0;
	int index = 0;
	if (str[0] == '-')
	{
		for (int i = str.size() - 1; i > 0; i--)
		{
			if (str[i] < 58)  num += (str[i] - 48)*pow(13, index);
			else  num += (str[i] - 55)*pow(13, index);
			index++;
		}
		num = -num;
	}
	else
	{
		for (int i = str.size() - 1; i >= 0; i--)
		{
			if (str[i] < 58)  num += (str[i] - 48)*pow(13, index);
			else  num += (str[i] - 55)*pow(13, index);
			index++;
		}
	}
	return num;
}

string TenToThirteen(int num)
{
	string result = "";
	bool isNegative = false;
	if (num == 0) return "0";
	else if (num < 0)
	{
		isNegative = true;
		num = -num;
	}

	while (num>0)
	{
		int remainder = num % 13;
		string current = "";
		switch (remainder)
		{
		case 10: current = "A"; break;
		case 11: current = "B"; break;
		case 12: current = "C"; break;
		default:
			stringstream ss;
			ss << remainder;
			current = ss.str();
			break;
		}
		result = current + result;
		num /= 13;
	}
	if (isNegative) result = "-" + result;
	return result;
}

int main()
{
	string cmd, num1, num2;
	cin >> cmd >> num1 >> num2;
	if (cmd == "add")
		cout << TenToThirteen(ThirteenToTen(num1) + ThirteenToTen(num2));
	if (cmd == "sub")
		cout << TenToThirteen(ThirteenToTen(num1) - ThirteenToTen(num2));
	if (cmd == "mul")
		cout << TenToThirteen(ThirteenToTen(num1)*ThirteenToTen(num2));

}