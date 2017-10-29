/*
对于一个数组，定义命令add，sub，mul， pow，sqa，print六种命令。  
add命令将数组中所有的元素增加数字a，命令格式add a。  
sub命令将数组中所有的元素减少数字b，命令格式sub b。  
mul命令将数组中所有的元素乘以c，命令格式mul c。  
pow命令计算数组中所有元素的n次方。命令格式为pow，n为正整数。  
sqa命令计算数组中所有的元素的平方和并输出。命令格式为sqa。  
print命令打印数组中所有的元素，以空格隔开。  
输入n表示数组大小（0<n<100），接着输入数组中每个元素。输入m表示命令条数，接着输入m条命令。给出对大小为n的输入数组的m次操作的输出。
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