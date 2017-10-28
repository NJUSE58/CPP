#include<iostream>
#include<string>
#include<sstream>
using namespace std;


#define MAX 100
struct BinaryTree
{
	string value;
	BinaryTree *left, *right;
};

BinaryTree *createTree(BinaryTree * BT, string str);
void inOrderTraverse(BinaryTree * BT);

int main()
{
	string input;
	getline(cin, input);
	BinaryTree * BT;
	BT = new BinaryTree;
	BT = createTree(BT, input);
	inOrderTraverse(BT);
	
	return 0;
}

BinaryTree *createTree(BinaryTree * BT, string str)
{
	BinaryTree *p, *queue[MAX];
	int front = 1, rear = 0;
	string value = "";
	stringstream ss(str);
	while (ss >> value)
	{
		p = NULL;
		if (value != "null") {
			p = new BinaryTree;
			p->value = value;
			p->left = p->right = NULL;
		}
		rear++;
		queue[rear] = p;
		if (rear == 1) {
			BT = p;   //��
		}
		else {
			if (p != NULL && queue[front] != NULL) {
				if (rear % 2 == 0) {
					queue[front]->left = p;
				}
				else {
					queue[front]->right = p;
				}
			}
			if (rear % 2 == 1) {
				front++;  //ÿ��һ�������ĸ��ڵ���������ӽڵ�
			}
		} //��n����pow(2,n)���ڵ�
	}
	ss.clear();
	return BT;
}

void inOrderTraverse(BinaryTree * BT)
{
	if (BT != NULL)
	{
		inOrderTraverse(BT->left);
		cout << BT->value << " ";
		inOrderTraverse(BT->right);
	}
}