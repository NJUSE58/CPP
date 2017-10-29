/*
输入学生信息（包括姓名，学号，科目，成绩），学号为唯一，成绩可能发生更新。
定义两种输出命令：course [coursename]和student [studentname]。course命令后接课程名称，输出对应的课程的平均分（保留2位小数）。student命令后接学生名称，输出对应的学生的科目平均分（保留2位小数）。
输入n，n表示学生信息数量，接着输入n条学生的信息（0<n<100）。然后输入m，m表示命令条数，接着输入命令。输出命令的执行结果。

Input:
3
simaqian 000001 cpp 80
simaqian 000001 java 90
baijuyi 000002 cpp 70
2
course cpp
student simaqian

Output:
cpp 75.00
simaqian 85.00
*/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

struct Student
{
	string Name;
	string ID;
	string Subject;
	double Score;
};

int main()
{
	int n, m;
	cin >> n;
	
	Student student[10000];
	for (int i = 0; i < n; i++)
	{
		cin >> student[i].Name >> student[i].ID 
			>> student[i].Subject >> student[i].Score;
	}

	cin >> m;
	string cmd, obj;
	for (int i = 0; i < m; i++)
	{
		cin >> cmd >> obj;
		if (cmd == "course")
		{
			double sum = 0;
			int count = 0;
			for (int j = 0; j < n; j++)
			{
				if (student[j].Subject == obj)
				{
					count++;
					sum += student[j].Score;
				}
			}
			cout << obj << " ";
			printf_s("%.2f\n", sum / count);
		}

		else if (cmd == "student")
		{
			int count = 0;
			double sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (student[j].Name == obj)
				{
					count++;
					sum += student[j].Score;
				}
			}
			cout << obj << " ";
			printf_s("%.2f\n", sum / count);
		}
	}
}