#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 10000
vector<string> path1, path2;
vector<string> list1, list2;

struct BinaryTree
{
	string value;
	BinaryTree * left, * right;
};

BinaryTree * createTree(BinaryTree * BT);
void findPath(BinaryTree * root, vector<string> &path, vector<string> &list, string value);
void getPath(vector<string> &path, vector<string> & list);

int main()
{
	BinaryTree * bt = new BinaryTree;

	string value1, value2;
	bt = createTree(bt);

	cin >> value1 >> value2;
	
	list1.emplace_back("list1");
	list2.emplace_back("list2");  //防止vector subscrip out of range

	findPath(bt, path1, list1, value1);
	findPath(bt, path2, list2, value2);
	

	int len1 = list1.size();
	int len2 = list2.size();
	if (len1 < len2) {
		if (list1[len1 - 1] == list2[len1 - 1]) {
			cout << len2 - len1;
		}
		else {
			cout << -1;
		}
	}
	else {
		if (list1[len2 - 1] == list2[len2 - 1]) {
			cout << len1 - len2;
		}
		else {
			cout << -1;
		}
	}
	//system("pause");
}

/*按层次建立二叉树*/
BinaryTree * createTree(BinaryTree * BT)
{
	BinaryTree * p, * queue[MAX];
	int n;
	string value = "";
	int front = 1, rear = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> value;
		p = NULL;
		if (value != "NULL") {
			p = new BinaryTree;
			p->value = value;
			p->left = p->right = NULL;
		}
		rear++;
		queue[rear] = p;

		if (rear == 1) {
			BT = p;      //根节点
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

			if (rear % 2 == 1)
				front++;
		}
	}
	return BT;
}


void findPath(BinaryTree * root, vector<string> &path, vector<string> &list, string value)
{
	if (root == NULL) {
		return;
	}
	path.push_back(root->value);
	if (root->value == value) {
		getPath(path, list);
		return;
	}
	if (root->left != NULL) {
		findPath(root->left, path, list, value);
	}
	if (root->right != NULL) {
		findPath(root->right, path, list, value);
	}
	path.pop_back();
}

void getPath(vector<string> &path, vector<string> & list)
{
	vector<string>::const_iterator iter = path.begin();
	for (; iter != path.end(); ++iter)
	{
		list.emplace_back(* iter);
	}
	
}