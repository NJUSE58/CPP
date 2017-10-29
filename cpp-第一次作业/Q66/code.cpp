/*
给定一串原始数据串n，数据串由01组成。计算添加海明校验位之后的编码数据。题目采用偶校验方式。最终编码长度不超过100。s
*/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

const int max = 101;
char number[max];
bool isPowOfTow(int n)
{
	return !(n&(n - 1));
}

int main()
{
	string str;
	cin >> str;
	stringstream ss;
	char ch = '#';
	int length = 1;
	ss << str;
	while (ss >> ch)
	{
		for (; isPowOfTow(length); length++)
			number[length] = '#';
		number[length] = ch;
		length++;
	}

	for (int i = 1; i < length; i++)
	{
		if (!isPowOfTow(i))
		{
			int temp = i;
			int haming = 0;
			while (temp)
			{
				if ((temp & 1) == 1)
				{
					int power = (int)pow(2, haming);
					if (number[power] == '#')
						number[power] = number[i];
					else
						number[power] = (number[power] - '0') ^ (number[i] - '0') + '0';
				}
				temp >>= 1;
				haming++;
			}

		}
	}

	for (int i = 1; i < length; i++)
		putchar(number[i]);
	return 0;
}