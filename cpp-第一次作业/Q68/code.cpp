/*
��ʼ��һ�����ַ���s��ʵ��һϵ���ַ����������append��replace��reverse��changecase��length��print��
append�����ʾ���ַ���sĩβ���ָ���ַ�������ʽΪappend abc��
replace����Ҫ���滻�ַ���s�����еı��滻�ַ���aΪ�滻�ַ���b����ʽΪreplace a b��
reverse�����ʾ��ת�����ַ�������ʽΪreverse��
changecase�����ʾת���ַ���s�еĴ�Сд����ʽΪchangecase low(up)��length������㵱ǰ�ַ���s�ĳ��Ȳ������
print����ַ���s�����
����m����ʾ������������������m�������������ִ�н����
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