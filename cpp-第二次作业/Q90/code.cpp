#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> nums;

int main() 
{
	int n;
	string cmd;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> cmd;
		if (cmd == "ADD") 
		{
			cin >> value;
			nums.emplace_back(value);
		}

		else if (cmd == "REVERSE")
		{
			reverse(nums.begin(), nums.end());
		}

		else if (cmd == "REMOVEREPEAT")
		{
			cin >> value;
			int index = 0;
			for (int i = 0;i < nums.size(); i++) {
				if (nums[i] == value) index++;
			}

			vector<int> temp;
			if (index != 0) {
				temp.clear();
				for (int i = 0; i < nums.size(); i++) {
					if (nums[i] != value || index == 1) {
						temp.emplace_back(nums[i]);
					}
					else {
						if (nums[i] == value) index--;
					}
				}
			}
			nums = temp;
		}

		else if (cmd == "DEL")
		{
			cin >> value;
			int index = 0;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] == value) index++;
			}

			vector<int> temp;
			temp.clear();
			if (index != 0) {
				for (int i = 0; i < nums.size(); i++) {
					if (nums[i] != value) {
						temp.emplace_back(nums[i]);
					}
				}
			}
			nums = temp;
		}

		else if (cmd == "PRINT")
		{
			if (nums.size() == 0) {
				cout << "NULL" << endl;
			}
			else {
				for (int i = 0; i < nums.size(); i++) {
					cout << nums[i] << " ";
				}
				cout << endl;
			}
		}

		else
		{
			cout << nums.size() << endl;
		}
	}
	
}

