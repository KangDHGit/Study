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
	void init_Queue() { front = 0; rear = 0; init_data(MAX_QUEUE_SIZE); }
	void init_data(int MAX_SIZE);
	QueueType() { init_Queue(); }
	bool is_full() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	bool is_empty() { return front == rear; }
	void error(const char* messege) { cout << messege << endl; exit(1); }
	void enquque(Data item);
	Data dequque();
	Data peek();
	void queue_print();
};
void QueueType::init_data(int MAX_SIZE) {
	for (int i = 0; i < MAX_SIZE; i++)
		data[i] = -1;
}
void QueueType::enquque(Data item) {
	if (is_full()) { error("ť�� ��ȭ�����Դϴ�."); }
	else {
		rear = (rear + 1) % MAX_QUEUE_SIZE; data[rear] = item;
	}
}
Data QueueType::dequque() {
	if (is_empty()) { error("ť�� ��������Դϴ�."); return -1; }
	else { front = (front + 1 ) % MAX_QUEUE_SIZE; return data[front]; }
}
Data QueueType::peek() {
	if (is_empty()) { error("ť�� ��������Դϴ�."); return -1; }
	else {
		int result = (front + 1) % MAX_QUEUE_SIZE;
		return data[result];
	}
}
void QueueType::queue_print() {
	cout << "front : " << front << " rear : " << rear << endl;
	bool forward = front < rear;
	bool empty = is_empty();

	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (empty) {
			if (front == i) { cout.width(6); cout << "fr |"; }
			else { cout.width(6); cout << "|"; }
		}
		else if (front == i) { cout.width(6); cout << "f |"; }
		else if (rear == i) { cout.width(3); cout << data[i] << "r |"; }
		else if (forward && (i < front || rear < i)) { cout.width(6); cout << "|"; }
		else if (!forward && (rear < i && i < front)) { cout.width(6); cout << "|"; }
		else { cout.width(4); cout << data[i] << " |"; }
	}
	cout << endl;
}

int main()
{
	QueueType q;
	int Data;
	cout << "--������ �߰� �ܰ�--" << endl;
	while (!q.is_full())
	{
		cout << "������ �Է��Ͻÿ� : "; cin >> Data;
		q.enquque(Data);
		q.queue_print();
		if (q.is_full())
		{
			Data = q.dequque();
			cout << "������ ���� : " << Data << endl;
			q.queue_print();
		}
	}
	cout << "ť�� ��ȭ���� �Դϴ�." << endl << endl;

	while (!q.is_empty())
	{
		Data = q.dequque();
		cout << "������ ���� : " << Data << endl;
		q.queue_print();
	}
	cout << "ť�� ������� �Դϴ�." << endl;
	return 0;
}