/*
����һ������n��0<n<2^31����ÿ�����ִ��������ܵ���ĸ����������ĸ�Ķ�Ӧ��ϵ�ο��ֻ��Ź��񣩣��õ����п��ܵ���ĸ��ϣ����ֵ��������
*/
#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
using namespace std;

const char ch[10][10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };  //���ִ�����ַ�
const int total[10] = { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };  //���ִ�����ַ��ĸ���
int numbers[20];
char result[20];

void Print(int index, int length)
{
	if (index == length)  //�ж��Ƿ�Ϊ���һλ
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
		numbers[i] = str[i] - '0';  //char����תint
	}
	Print(0, length); 
	cin.get();
	cin.get();
	return 0;
}