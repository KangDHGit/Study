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
	if (is_full()) { error("큐가 포화상태입니다."); }
	else {
		rear = (rear + 1) % MAX_QUEUE_SIZE; data[rear] = item;
	}
}
element QueueType::dequque() {
	if (is_empty()) { error("큐가 공백상태입니다."); return -1; }
	else { front = (front + 1 ) % MAX_QUEUE_SIZE; return data[front]; }
}
element QueueType::peek() {
	if (is_empty()) { error("큐가 공백상태입니다."); return -1; }
	else { return data[front]; }
}
void QueueType::queue_print() {
	int iter = front;
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		// f는 자료가 없는 위치이기 때문에 이하 i는 자료가 있는 위치이기 때문에 초과
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
	cout << "--데이터 추가 단계--" << endl;
	while (!q.is_full())
	{
		cout << "정수를 입력하시오 : "; cin >> element;
		q.enquque(element);
		q.queue_print();
	}
	cout << "큐는 포화상태 입니다." << endl << endl;

	while (!q.is_empty())
	{
		element = q.dequque();
		cout << "꺼내진 정수 : " << element << endl;
		q.queue_print();
	}
	cout << "큐는 공백상태 입니다." << endl;
	return 0;
}