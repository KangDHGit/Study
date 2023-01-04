#include<iostream>
#include<random>

using std::cout;
using std::endl;
using std::cin;

#define MAX_QUEUE_SIZE 5

typedef	int element;
#pragma region CircularQueue
class QueueType {
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
public:
	void init_Queue() { front = 0; rear = 0; init_data(MAX_QUEUE_SIZE); }
	void init_data(int MAX_SIZE);
	QueueType() { init_Queue(); }
	bool is_full() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	bool is_empty() { return front == rear; }
	void error(const char* messege) { cout << messege << endl; exit(1); }
	void enquque(element item);
	element dequque();
	element peek();
	void queue_print();
};
void QueueType::init_data(int MAX_SIZE) {
	for (int i = 0; i < MAX_SIZE; i++)
		data[i] = -1;
}
void QueueType::enquque(element item) {
	if (is_full()) { error("ť�� ��ȭ�����Դϴ�."); }
	else {
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		data[rear] = item;
	}
}
element QueueType::dequque() {
	if (is_empty()) { error("ť�� ��������Դϴ�."); return -1; }
	else {
		front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front];
	}
}
element QueueType::peek() {
	if (is_empty()) { error("ť�� ��������Դϴ�."); return -1; }
	else {
		return data[front];
	}
}
void QueueType::queue_print() {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (front == i) { cout.width(5); cout << "f |"; }
		else if (data[i] == -1) { cout.width(5); cout << "|"; }
		else { cout.width(3); cout << data[i] << " |"; }
	}
	cout << endl;
}
#pragma endregion

int main()
{
	//�õ尪�� ������� random_device ����
	std::random_device rd;

	//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
	std::mt19937 gen(rd());

	//����(1~100)���� �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
	std::uniform_int_distribution<int> dis(1, 100);

	QueueType q;
	int element;
	for (int i = 0; i < 100; i++)
	{
		if (q.is_full()) { cout << "��ȭ�����Դϴ�." << endl; break; }

		if (dis(gen) % 5 == 0) {
			q.enquque(dis(gen));
		}
		q.queue_print();
		if (dis(gen) % 10 == 0) {
			element = q.dequque();
		}
		q.queue_print();
	}

	return 0;
}