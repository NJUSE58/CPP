/*
输入一串数字n（0<n<2^31），每个数字代表多个可能的字母（数字与字母的对应关系参考手机九宫格），得到所有可能的字母组合，按字典序输出。
*/
#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
using namespace std;

const char ch[10][10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };  //数字代表的字符
const int total[10] = { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };  //数字代表的字符的个数
int numbers[20];
char result[20];

void Print(int index, int length)
{
	if (index == length)  //判断是否为最后一位
	{
		result[length] = '\0';
		cout << result << endl;
		return;
	}

	for (int i = 0; i < total[numbers[index]]; i++)
	{
		result[index] = ch[numbers[index]][i];
		Print(index + 1, length);
	}
}


int main()
{
	int number = 0	;
	cin >> number;
	string str = "";
	stringstream ss;
	ss << number;
	str = ss.str();
	int length = str.length();
	for (int i = 0; i < length; i++)
	{
		numbers[i] = str[i] - '0';  //char类型转int
	}
	Print(0, length); 
	cin.get();
	cin.get();
	return 0;
}