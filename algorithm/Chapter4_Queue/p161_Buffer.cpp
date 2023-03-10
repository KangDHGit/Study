#include<iostream>
#include<random>

using std::cout;
using std::endl;
using std::cin;

#define MAX_QUEUE_SIZE 5

typedef	int Data;
#pragma region CircularQueue
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
	if (is_full()) { error("큐가 포화상태입니다."); }
	else {
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		data[rear] = item;
	}
}
Data QueueType::dequque() {
	if (is_empty()) { error("큐가 공백상태입니다."); return -1; }
	else {
		front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front];
	}
}
Data QueueType::peek() {
	if (is_empty()) { error("큐가 공백상태입니다."); return -1; }
	else {
		return data[front];
	}
}
void QueueType::queue_print() {
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
#pragma endregion

int main()
{
	//시드값을 얻기위한 random_device 생성
	std::random_device rd;

	//random_device를 통해 난수생성 엔진을 초기화 한다.
	std::mt19937 gen(rd());

	//정수(1~100)까지 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
	std::uniform_int_distribution<int> dis(1, 100);

	QueueType q;
	int Data;
	for (int i = 0; i < 100; i++)
	{
		if (q.is_full()) { cout << "포화상태입니다." << endl; break; }

		if (dis(gen) % 5 == 0) {
			q.enquque(dis(gen));
		}
		q.queue_print();
		if (dis(gen) % 10 == 0) {
			Data = q.dequque();
		}
		q.queue_print();
	}

	return 0;
}