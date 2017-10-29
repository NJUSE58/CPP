#include<iostream>

using namespace std;

long long func(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	long long x0 = 0, x1 = 1, x2 = 0;
	for (int i = 2; i <= n; i++)
	{
		x2 = x0 + x1;
		x0 = x1;
		x1 = x2;
	}
	return x2;

}

int main()
{
	int n;
	cin >> n;
	cout << func(n);
	cin.get();
	cin.get();
	return 0;
}