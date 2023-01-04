#include<iostream>

using std::cout;
using std::endl;
using std::cin;

#define MAX_QUEUE_SIZE 5

typedef	int element;

class QueueType {
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
public:
	void init_Queue() { front = 0; rear = 0; }
	QueueType() { init_Queue(); }
	bool is_full() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	bool is_empty() { return front == rear; }
	void error(const char* messege) { cout << messege << endl; exit(1); }
	void enquque(element item);
	element dequque();
	element peek();
	void queue_print();
};
void QueueType::enquque(element item) {
	if (is_full()) { error("ť�� ��ȭ�����Դϴ�."); }
	else {
		rear = (rear + 1) % MAX_QUEUE_SIZE; data[rear] = item;
	}
}
element QueueType::dequque() {
	if (is_empty()) { error("ť�� ��������Դϴ�."); return -1; }
	else { front = (front + 1 ) % MAX_QUEUE_SIZE; return data[front]; }
}
element QueueType::peek() {
	if (is_empty()) { error("ť�� ��������Դϴ�."); return -1; }
	else { return data[front]; }
}
void QueueType::queue_print() {
	int iter = front;
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		// f�� �ڷᰡ ���� ��ġ�̱� ������ ���� i�� �ڷᰡ �ִ� ��ġ�̱� ������ �ʰ�
		if (i == front) {
			cout.width(5); cout << "f |";
		}
		else if (i < front || i > rear) {
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
	QueueType q;
	int element;
	cout << "--������ �߰� �ܰ�--" << endl;
	while (!q.is_full())
	{
		cout << "������ �Է��Ͻÿ� : "; cin >> element;
		q.enquque(element);
		q.queue_print();
	}
	cout << "ť�� ��ȭ���� �Դϴ�." << endl << endl;

	while (!q.is_empty())
	{
		element = q.dequque();
		cout << "������ ���� : " << element << endl;
		q.queue_print();
	}
	cout << "ť�� ������� �Դϴ�." << endl;
	return 0;
}