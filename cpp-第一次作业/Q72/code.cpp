/*
罗马数字规则：若干个罗马数字写成一列，它表示的数等于各个数字所表示的数相加的和。当符号 I、X 或 C 位于大数的后面时就作为加数；位于大数的前面就作为减数。
罗马数字符号：I（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）
*/
#include<iostream>
#include<string>
using namespace std;

int number[400];

int main()
{
	number['I'] = 1;
	number['V'] = 5;
	number['X'] = 10;
	number['L'] = 50;
	number['C'] = 100;
	number['D'] = 500;
	number['M'] = 1000;
	string str;
	cin >> str;
	int sum = number[str[0]];
	for (int i = 0; i<str.length(); i++)
	{
		if (number[str[i + 1]] <= number[str[i]])
			sum += number[str[i + 1]];
		else
			sum += number[str[i + 1]] - 2 * number[str[i]];
	}
	cout << sum << endl;
	return 0;
	
}