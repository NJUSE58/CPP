/*
����һ�����У����������־�Ϊ��������ȡÿ�����ֵĶ����Ƹ���λ�γ��µ����У�����������֮��
*/
#include<iostream>

using namespace std;

int tobinary(long long n)
{
	if (n <= 4) return n;
	int binary[100000];
	int index = 0;
	int result = 0;
	while (n > 0)
	{
		binary[index] = n % 2;
		n /= 2;
		index++;
	}
	result = binary[index - 3]*pow(2, 0) + binary[index - 2] * pow(2,1) + binary[index - 1] * pow(2, 2);
	return result;
	
}

int main()
{
	long long n;
	cin >> n;
	long long *num = new long long[n];
	long long sum = 0;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n; i++)
		sum += tobinary(num[i]);
	cout << sum;
	delete [] num;
	cin.get();
	cin.get();
	return 0;
	
}