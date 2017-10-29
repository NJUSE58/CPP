#include<iostream>

int main()
{
	using namespace std;
	int x, y;
    long long  product = 1;
	cin >> x >> y;
	if (x == 0) {
		cout << 0;
	}
	else if (y == 0) {
		cout << 1;
	}
	else if (y < 0) {
		for (int i = 0; i < abs(y); i++)
			product *= x;
		cout << 1 / product;
	}
	else {
		for (int i = 0; i < y; i++)
			product *= x;
		cout << product;
	}
	cin.get();
	cin.get();
	
	return 0;
}