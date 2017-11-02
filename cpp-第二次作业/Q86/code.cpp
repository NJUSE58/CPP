#include<iostream>
using namespace std;

int main()
{
	int m, n, x, index = 0;
	int matrix[100][100] = { 0 };
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	cin >> x;
	for (int i = 0; i <= m/2; i++)
	{
		for (int j = i; j <= n - i - 1; j++) {
			if (x == index) {
				cout << matrix[i][j];
			}
			index++;
		}
		

		for (int j = i + 1; j <= m - i - 1; j++) {
			if (x == index) {
				cout << matrix[j][n - i - 1];
			}
			index++;
		}
		
		for (int j = n - i - 2; j >= i; j--) {
			if (x == index) {
				cout << matrix[m - i - 1][j];
			}
			index++;
		}


		for (int j = m - i - 2; j >= i + 1; j--) {
			if (x == index) {
				cout << matrix[j][i];
			}
			index++;
		}

		
	}
	
	return 0;
}