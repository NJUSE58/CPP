#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 101

int main()
{
	int n;
	int num[MAX][MAX], sum[MAX][MAX];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> num[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		sum[n][i] = num[n][i];
	}

	for (int i = n; i > 1; i--) {	
		for (int j = 1; j < i; j++) {
			if (sum[i][j] < sum[i][j + 1]) {
				sum[i - 1][j] = sum[i][j] + num[i - 1][j];
			}
			else {
				sum[i - 1][j] = sum[i][j + 1] + num[i - 1][j];
			}
		}
	}

	cout << sum[1][1];
	
	cin.get();
	cin.get();
	return 0;
}
