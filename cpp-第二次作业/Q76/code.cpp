#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct Node
{
	int value;
	Node * next;
};

Node * createList(Node * node, string str);
void print(Node * node);
Node * addList(Node * result, Node * list1, Node * list2);
int length(Node * node);

int main()
{
	string input1 = "", input2 = "";
	cin >> input1 >> input2;
	Node * list1, * list2, * sum;
	list1 = new Node;
	list1 = createList(list1, input1);
	list2 = new Node;
	list2 = createList(list2, input2);
	sum = new Node;
	sum = addList(sum, list1, list2);

	print(sum);
	cout << "null";
	return 0;
}

Node * createList(Node * head, string str)
{
	Node * tail = NULL;
	head = NULL;
	int value = 0;
	int length = str.length();
	for (int i = length-1; i >= 0; i--)
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			Node * node = new Node;
			char ch = str[i];
			value = ch - '0';
			node->value = value;
			if (head == NULL) {
				head = node;
				tail = node;
			}
			else {
				tail->next = node;
				tail = node;
			}
			tail->next = NULL;
		}
	}
	return head;
}

Node * addList(Node * result, Node * list1, Node * list2)
{
	string number = "";
	bool isCarry = false;  //是否产生进位
	while (list1 != NULL || list2 != NULL)
	{
		stringstream ss;
		int value1 = 0, value2 = 0, sum = 0;

		if (list1 != NULL) {
			value1 = list1->value;
			list1 = list1->next;
		}
		if (list2 != NULL) {
			value2 = list2->value;
			list2 = list2->next;
		}
		
		if (isCarry) {
			sum = value1 + value2 + 1;
		}
		else {
			sum = value1 + value2;
		}

		if (sum >= 10) {
			sum = sum - 10;
			isCarry = true;
		}
		else {
			isCarry = false;
		}
	
		string str;
		ss << sum;
		ss >> str;

		number = str + number;
		ss.clear();
	}
	
	if (isCarry)
		number = "1" + number;

	for (int i = 0; i < number.length(); i++) {
		if (number[i]>'0') {
			number = number.substr(i);
			break;
		}
	}
	
	return createList(result, number);
}

void print(Node * node)
{
	int index = 0;
	int nums[100] = { 0 };
	while (node != NULL)
	{
		nums[++index] = node->value;
		node = node->next;
	}
	for (int i = index; i > 0; i--)
		cout << nums[i] << ">";
}

