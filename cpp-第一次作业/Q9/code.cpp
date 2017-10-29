#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n)
{
	if (n == 1) return false;
	if (n == 2) return true;
	if (n == 4) return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0) return false;
	}
	return true;
}

int main()
{
	int n, m, sum = 0;
	cin >> n >> m; 

	for (int i = n; i <= m; i++)
	{
		if (isPrime(i)) sum += i;
	}
	
	cout << sum;
	cin.get();
	cin.get();
	return 0;
}