/*
����һ�����飬��������add��sub��mul�� pow��sqa��print�������  
add������������е�Ԫ����������a�������ʽadd a��  
sub������������е�Ԫ�ؼ�������b�������ʽsub b��  
mul������������е�Ԫ�س���c�������ʽmul c��  
pow�����������������Ԫ�ص�n�η��������ʽΪpow��nΪ��������  
sqa����������������е�Ԫ�ص�ƽ���Ͳ�����������ʽΪsqa��  
print�����ӡ���������е�Ԫ�أ��Կո������  
����n��ʾ�����С��0<n<100������������������ÿ��Ԫ�ء�����m��ʾ������������������m����������Դ�СΪn�����������m�β����������
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>

int main()
{
	using namespace std;
	int n, m;
	string str, str1, str2;
	int num[100] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];                       
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		getline(cin, str);
		int index = str.find(" ");
		str1 = str.substr(0, index);
		str2 = str.substr(index+1);
		
		stringstream ss(str2);
		int temp;
		ss >> temp;
		if (str1 == "add")
			for (int i = 0; i < n; i++)
				num[i] += temp;
		else if (str1 == "sub")
			for (int i = 0; i < n; i++)
				num[i] -= temp;
		else if (str1 == "mul")
			for (int i = 0; i < n; i++)
				num[i] *= temp;
		else if (str1 == "pow")
			for (int i = 0; i < n; i++)
				pow(num[i], n);
		else if (str1 == "print")
		{
			for (int i = 0; i < n; i++)
				cout << num[i] << " ";
			cout << endl;
		}
		else if (str1 == "sqa")
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
				sum += num[i] * num[i];
			cout << sum << endl;
		}
	}

	
	return 0;
}