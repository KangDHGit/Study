#include<iostream>

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
		top++;
		data[top] = node;
	}
	TreeNode* Pop() {
		if (top == -1) { cout << "스택이 비어있습니다." << endl; exit(-1); }
		return data[top--];
	}
};

void InOrderIter(TreeNode* head) {

}

int main()
{
	return 0;
}