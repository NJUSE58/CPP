#include<iostream>
#include<string>
using namespace std;

int nums[100];

int main()
{
	int n, m;
	string cmd = "";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> cmd;
		if (cmd == "replace") {
			int a, b;
			cin >> a >> b;
			for (int j = 0; j < n; j++) {
				if (nums[j] == a){
					nums[j] = b;
				}
			}
		}

		else if (cmd == "move") {
			string place = "";
			int a, index = 0;
			int temp[100] = { 0 };
			cin >> place;
			cin >> a;
			if (place == "head") {
				for (int j = 0; j < n; j++) {
					if (nums[j] != a) {
						temp[index] = nums[j];
						index++;
					}
				}

				for (int j = 0; j < n-index; j++) {
					nums[j] = a;
				}
				for (int j = n - index; j < n; j++) {
					nums[j] = temp[j - n + index];
				}
			}

			else if (place == "tail") {
				for (int j = 0; j < n; j++) {
					if (nums[j] != a) {
						temp[index] = nums[j];
						index++;
					}
				}

				for (int j = 0; j < index; j++) {
					nums[j] = temp[j];
				}

				for (int j = index; j < n; j++) {
					nums[j] = a;
				}
			} 
		}

		else if (cmd == "translate") {
			string place = "";
			int a = 0;
			int temp[100] = { 0 };
			int temp2[100] = { 0 };
			cin >> place >> a;
			if (place == "head") {
				for (int j = 0; j < a; j++) {
					temp[j] = nums[j];
				}
				for (int j = a; j < n; j++) {
					nums[j - a] = nums[j];
				}
				for (int j = n - a; j < n; j++) {
					nums[j] = temp[j-n+a];
				}
			}

			else if(place == "tail") {
				for (int j = 0; j < n; j++) {
					temp2[j] = nums[j];
				}
				for (int j = n-a; j < n; j++) {
					temp[j - n + a] = nums[j];
				}
				for (int j = 0; j < n - a; j++) {
					nums[j + a] = temp2[j];
				}
				for (int j = 0; j < a; j++) {
					nums[j] = temp[j];
				}
			}
		}

		else if (cmd == "print"){
			for (int j = 0; j < n; j++) {
				cout << nums[j] << " ";
			}
			cout << endl;
		}
	}
}