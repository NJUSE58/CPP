/*
* Calculate the length of the last word in the sentence 
*/
#include<iostream>
#include<string>
int main()
{
	using namespace std;
	string line;
	int n = 0;
	getline(cin, line);
	int index = line.length() - 1;

	while (index >= 0)
	{
		if (line[index] == ' ')
		{
			index--;
			continue;
		}
		else break;
	}

	while (line[index] != ' ')
	{
		index--;
		n++;
		if (index < 0) break;
	}
	cout << n;
	cin.get();
	cin.get();
	return 0;
}