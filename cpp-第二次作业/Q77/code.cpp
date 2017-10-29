#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool checkTag(string tag);
string check(string str);

int main()
{
	string str;
	getline(cin, str);
	cout << check(str);
	cin.get();
	cin.get();
}

bool checkTag(string tag)
{
	if (tag.length() < 1 || tag.length() > 9) {
		return false;
	}
	for (int i = 0; i < tag.length(); i++) {
		if (!isupper(tag[i])) {
			return false;
		}
	}
	return true;
}

string check(string str)
{
	stack<string> ss = {};
	int length = str.length();
	int i = 0;
	

	while (i < length) {
		if (str[i] == '<') {
			string tag = "";

			if (str[i + 1] == '/') {
				i++;
				while (str[i+1] != '>') {
					i++;
					tag += str[i];
				}
				i++;

				if (ss.top() != tag) {
					return "False";
				}
				else {
					ss.pop();
				}

				continue;
			}

			/* <--COMMENT--> µÄÇé¿ö*/
			if (str[i + 1] == '!' && str[i + 2] == '-' && str[i + 3] == '-') {
				i += 4;
				while (!(str[i] == '-' && str[i + 1] == '-' && str[i+2] == '>'))
					i++;
				i += 3;
				continue;
			}

			while (str[i+1] != '>') {
				i++;
				tag = tag + str[i];
			}
			i++;


			if (checkTag(tag)) {
				ss.push(tag);
			}
			else {
				return "False";
			}
		}

		else if (str[i] == '(') {
			i++;
			while (str[i] != ')') {
				i++;
			}
			i++;
		}
		else if (str[i] == ')') {
			return "False";
		}

		else {
			i++;
		}

	}
	
	if (ss.empty()) {
		return "True";
	}
	else {
		return "False";
	}
}