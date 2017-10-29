/*
初始化一个空字符串s。实现一系列字符串操作命令：append，replace，reverse，changecase，length，print。
append命令表示在字符串s末尾添加指定字符串，格式为append abc。
replace命令要求替换字符串s中所有的被替换字符串a为替换字符串b，格式为replace a b。
reverse命令表示翻转整个字符串，格式为reverse。
changecase命令表示转换字符串s中的大小写，格式为changecase low(up)。length命令计算当前字符串s的长度并输出。
print命令将字符串s输出。
输入m，表示命令条数，接着输入m条命令，输出命令的执行结果。
*/
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>

using namespace std;

int main()
{
	string Str = "";
	string cmd = "";
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> cmd;
		if (cmd == "append")
		{
			string newStr;
			cin >> newStr;
			Str += newStr;
		}

		else if (cmd == "replace")
		{
			string str1, str2;
			cin >> str1 >> str2;
			int length = Str.size();
			int pos = Str.find(str1);
			while (pos != Str.npos)
			{
				Str.replace(pos, str1.size(), str2);
				pos = Str.find(str1);
			}

		}

		else if (cmd == "reverse")
		{
			reverse(Str.begin(), Str.end());
		}

		else if (cmd == "changecase")
		{
			string str;
			cin >> str;
			if (str == "low")
			{
				transform(Str.begin(), Str.end(), Str.begin(), tolower);
			}
			else
			{
				transform(Str.begin(), Str.end(), Str.begin(), toupper);
			}
		}

		else if (cmd == "length")
		{
			cout << Str.length() << endl;
		}

		else if (cmd == "print")
		{
			cout << Str << endl;
		}
	}

}