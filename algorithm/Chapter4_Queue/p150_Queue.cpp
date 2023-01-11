#include<iostream>

using std::cout;
using std::endl;
using std::cin;

#define MAX_QUEUE_SIZE 5

typedef	int Data;

class QueueType {
	Data data[MAX_QUEUE_SIZE];
	int front;
	int rear;
public:
	void init_Queue() { front = -1; rear = -1; }
	QueueType() { init_Queue(); }
	bool is_full() { return rear == MAX_QUEUE_SIZE - 1; }
	bool is_empty() { return front == rear; }
	void error(const char* messege) { cout << messege << endl; exit(1); }
	void enquque(Data item);
	Data dequque();
	Data peek();
	void queue_print();
};
void QueueType::enquque(Data item) {
	if (is_full()) { error("ť�� ��ȭ�����Դϴ�."); }
	else {
		rear++; data[rear] = item;
	}
}
Data QueueType::dequque() {
	if (is_empty()) { error("ť�� ��������Դϴ�."); return -1; }
	else { front++; return data[front]; }
}
Data QueueType::peek() {
	if (is_empty()) { error("ť�� ��������Դϴ�."); return -1; }
	else { return data[front]; }
}
void QueueType::queue_print() {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		// f�� �ڷᰡ ���� ��ġ�̱� ������ ���� i�� �ڷᰡ �ִ� ��ġ�̱� ������ �ʰ�
		if (i <= front || i > rear) {
			cout.width(5); cout << "|";
		}
		else {
			cout.width(3); cout << data[i] << " |";
		}
	}
	cout << endl;
}

int main()
{
	int item = 0;
	QueueType q;
	
	q.enquque(10); q.queue_print();
	q.enquque(20); q.queue_print();
	q.enquque(30); q.queue_print();

	item = q.dequque(); q.queue_print();
	item = q.dequque(); q.queue_print();
	item = q.dequque(); q.queue_print();

	return 0;
}