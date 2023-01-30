#include<iostream>
//반복적 순회

using std::cout;
using std::endl;
using std::cin;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
};

#define MAX_SIZE 100

class NodeStack {
	TreeNode* data[MAX_SIZE];
	int top;
public:
	NodeStack() { top = -1; }
	void Push(TreeNode* node) {
		if (top < MAX_SIZE - 1) {
			top++;
			data[top] = node;
		}
	}
	TreeNode* Pop() {
		TreeNode* result = nullptr;
		if (top >= 0)
			result = data[top--];
		return result;
	}
};

void InOrderIter(NodeStack stack, TreeNode* root) {
	while (true)
	{
		for (; root != nullptr; root = root->left)
			stack.Push(root);
		root = stack.Pop();
		if (root == nullptr)	//Pop함수에서 nullptr을 리턴할때
			break;
		cout << "[" << root->data << "] ";
		root = root->right;
	}
}

//			  15
//		4			20
//	1			16		25
int main()
{
	TreeNode n1 = { 1, nullptr, nullptr };
	TreeNode n2 = { 4, &n1, nullptr };
	TreeNode n3 = { 16, nullptr, nullptr };
	TreeNode n4 = { 25, nullptr, nullptr };
	TreeNode n5 = { 20, &n3, &n4};
	TreeNode n6 = { 15, &n2, &n5 };
	TreeNode* root = &n6;
	
	NodeStack stack;
	InOrderIter(stack, root);
	cout << endl;
	return 0;
}