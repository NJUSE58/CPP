#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	string str;
	cin >> n >> str;
	int max = 0;
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = i + 1; j < str.size(); j++)
		{
			int t1, t2;
			for (t1 = i, t2 = j; t1<t2; t1++, t2--)
			{
				if (str[t1] != str[t2])
					break;
			}

			if ((t1 >= t2) && (j - i>max))
				max = j - i + 1;
		}
	}
	
	if (max>0) cout << max;
	else cout << 1;

	cin.get();
	cin.get();
	return 0;
}