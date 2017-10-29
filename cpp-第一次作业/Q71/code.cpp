/*
*给定一个数n，将数字翻转。(0<n<2^31) 
*/
#include<iostream>
using namespace std;

const int Base = 10;

long long reverse(long long n)
{
	long long result = 0;
	while (n)
	{
		result *= Base;
		result += n % Base;
		n /= Base;
	}
	return result;
}

int main()
{
	long long n;
	cin >> n;
	cout << reverse(n) << endl;
	cin.get();
	cin.get();
	return 0;
}