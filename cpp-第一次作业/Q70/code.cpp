/*
����ѧ����Ϣ������������ѧ�ţ���Ŀ���ɼ�����ѧ��ΪΨһ���ɼ����ܷ������¡�
��������������course [coursename]��student [studentname]��course�����ӿγ����ƣ������Ӧ�Ŀγ̵�ƽ���֣�����2λС������student������ѧ�����ƣ������Ӧ��ѧ���Ŀ�Ŀƽ���֣�����2λС������
����n��n��ʾѧ����Ϣ��������������n��ѧ������Ϣ��0<n<100����Ȼ������m��m��ʾ�����������������������������ִ�н����

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