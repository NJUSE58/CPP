#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int index = 1, sum = 0;
	while (true)
	{
		sum += index;
		index++; 
		if (sum >= n) break;
	}
	if (index % 2 == 0)
		cout << (sum - n + 1) << "/" << (index - (sum - n + 1)) << endl;
	else
		cout << (index - (sum - n + 1)) << "/" << (sum - n + 1) << endl;
	cin.get();
	cin.get();
}