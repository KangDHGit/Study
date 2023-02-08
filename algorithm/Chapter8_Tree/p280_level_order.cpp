#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

#define MAX_SIZE 10

class QueueType {
	TreeNode* data[MAX_SIZE];
	int front;
	int rear;

public:
	QueueType() { front = 0; rear = 0; }
	bool IsEmpty() { return front == rear; }
	bool IsFull() { return (rear + 1) % MAX_SIZE == front; }
	void Enqueue(TreeNode* item) {
		if (IsFull()) {
			cout << "큐가 포화상태 입니다." << endl; return;
		}
		rear = (rear + 1) % MAX_SIZE;
		data[rear] = item;
		cout << "rear : " << rear << endl;
	}
	TreeNode* Dequeue() {
		if (IsEmpty()) {
			cout << "큐가 공백상태 입니다." << endl; return nullptr;
		}
		front = (front + 1) % MAX_SIZE;
		return data[front];
	}
};

void LevelOrder(QueueType queue, TreeNode* root) {
	if (root == nullptr) return;
	queue.Enqueue(root);
	TreeNode* order = nullptr;
	while (!queue.IsEmpty())
	{
		order = queue.Dequeue();
		cout << "[" << order->data << "] ";
		if (order->left != nullptr)
			queue.Enqueue(order->left);
		if (order->right != nullptr)
			queue.Enqueue(order->right);
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
	TreeNode n5 = { 20, &n3, &n4 };
	TreeNode n6 = { 15, &n2, &n5 };
	TreeNode* root = &n6;
	
	QueueType queue;
	LevelOrder(queue, root);
	cout << endl;

	return 0;
}