#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//9. 2개의 스택으로 큐 구현
#pragma region question_9
class stackType {
	const static int MAX_SIZE = 5;
	int data[MAX_SIZE];
	int top;
public:
	stackType() : top(-1) {};
	bool is_full() { return top == MAX_SIZE - 1; }
	bool is_empty() { return top == -1; }
	void push(int item) {
		if (is_full()) { cout << "스택 포화에러" << endl; }
		else { top++; data[top] = item; }
	}
	int pop() {
		if (is_empty()) { cout << "스택 공백에러" << endl; return -1; }
		else { return data[top--]; }
	}
	int peek() {
		if (is_empty()) { cout << "스택 공백에러" << endl; return -1; }
		else { return data[top]; }
	}
};
class queue_stack {
	stackType front;
	stackType rear;
public:
	bool is_full() { return rear.is_full(); }
	bool is_empty() { return (front.is_empty() && rear.is_empty()); }
	void enqueue(int item) {
		if (is_full()) { cout << "큐 포화에러" << endl; }
		else { rear.push(item); }
	}
	int dequeue() {
		if (front.is_empty()) {
			if (rear.is_empty()) { cout << "큐 공백에러" << endl; return -1; }
			else {
				while (!rear.is_empty())
				{
					front.push(rear.pop());
				}
				return front.pop();
			}
		}
		else
			return front.pop();
	}
	int peek() {
		if (front.is_empty()) {
			if (rear.is_empty()) { cout << "큐 공백에러" << endl; return -1; }
			else {
				while (!rear.is_empty())
				{
					front.push(rear.pop());
				}
				return front.peek();
			}
		}
		else
			return front.peek();
	}
};

class question_9 {
	queue_stack queue;
public:
	void run() {
		for (int i = 0; i < 6; i++)
		{
			queue.enqueue(i);
		}
		for (int i = 0; i < 6; i++)
		{
			cout << queue.dequeue() << endl;
		}
	}
};
#pragma endregion

//10. 큐를 활용해서 피보나치 수열 계산하기
#pragma region question_10
class QueueType {
	const static int MAX_SIZE = 5;
	int data[MAX_SIZE];
	int rear;
	int front;
public:
	QueueType() : rear(0), front(0) {};
	bool is_full() { return (rear + 1) % MAX_SIZE == front; }
	bool is_empty() { return front == rear; }
	void enqueue(int item) {
		if (is_full()) { cout << "큐 포화에러" << endl; }
		else{
			rear = (rear + 1) % MAX_SIZE;
			data[rear] = item;
		}
	}
	int dequeue() {
		if (is_empty()) { cout << "큐 공백에러" << endl; return -1; }
		else {
			front = (front + 1) % MAX_SIZE;
			return data[front];
		}
	}
	int peek() {
		if (is_empty()) { cout << "큐 공백에러" << endl; return -1; }
		else {
			int result = (front + 1) % MAX_SIZE;
			return data[result];
		}
	}
};
class question_10 {
	QueueType q;
public:
	int fibo(int n) {
		if (n == 0) return 0;
		else if (n == 1) return 1;

		q.enqueue(0); q.enqueue(1);

		for (int i = 2; i <= n; i++) {
			int nextN = q.dequeue() + q.peek();
			//cout << nextN << endl;
			q.enqueue(nextN);
		}

		int result = 0;
		while (!q.is_empty())
		{
			result = q.dequeue();
		}

		return result;
	}
};

#pragma endregion


int main()
{
	/*question_9 q9;
	q9.run();*/
	question_10 q10;
	cout << q10.fibo(10) << endl;
	return 0;
}