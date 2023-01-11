#include<iostream>

using std::cout;
using std::endl;
using std::cin;

#define MAX_DEQUE_SIZE 5

typedef int Data;

class DequeType {
	Data data[MAX_DEQUE_SIZE];
	int front;
	int rear;
public:
	void error(const char* messege) { cout << messege << endl; exit(-1); }
	void init_data(int MAX_SIZE);
	void init_deque() { front = 0; rear = 0; init_data(MAX_DEQUE_SIZE); }
	DequeType() { init_deque(); }
	bool is_full() { return (rear + 1) % MAX_DEQUE_SIZE == front; }
	bool is_empty() { return front == rear; }
	void add_rear(Data item);
	Data delete_front();
	Data get_front();
	void add_front(Data item);
	Data delete_rear();
	Data get_rear();
	void print_deque();
};

void DequeType::init_data(int MAX_SIZE) {
	for (int i = 0; i < MAX_SIZE; i++)
		data[i] = -1;
}
void DequeType::add_rear(Data item) {
	if (is_full()) { error("데크가 포화상태 입니다."); }
	else {
		rear = (rear + 1) % MAX_DEQUE_SIZE;
		data[rear] = item;
	}
}
Data DequeType::delete_front() {
	if (is_empty()) { error("데크가 공백상태 입니다."); return -1; }
	else {	//뒤로 이동후 삭제
		front = (front + 1) % MAX_DEQUE_SIZE;
		return data[front];
	}
}
Data DequeType::get_front() {
	if (is_empty()) { error("데크가 공백상태 입니다."); return -1; }
	else {
		int result = (front + 1) % MAX_DEQUE_SIZE;
		return data[result];
	}
}
void DequeType::add_front(Data item) {
	//front 변수는 rear변수와 반대로 가야함(즉 앞으로, -인덱스 방향으로)
	if (is_full()) { error("데크가 포화상태 입니다."); }
	else {
		//또한 front인덱스의 의미는 삭제 되어있는, 즉 빈공간 취급이기 때문에
		//데이터 추가를 하고 인덱스를 옮겨야 한다
		//(rear는 이미 차있는 공간 취급으로 인덱스를 먼저 옮기고 데이터 추가)
		data[front] = item;
		//앞으로 이동(-) 및 음수가 나오지 않고 인덱스를 이동할 수 있도록 MAX_SIZE를 더해줌
		front = (front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	}
}
Data DequeType::delete_rear() {
	if (is_empty()) { error("데크가 공백상태 입니다."); return -1; }
	else {									//삭제후 앞으로 이동(즉 리턴후 인덱스를 앞으로)
		int result = rear;					//앞으로 이동 전에 리턴할 인덱스 저장
		//앞으로 이동(-) 및 음수가 나오지 않고 인덱스를 이동할 수 있도록 MAX_SIZE를 더해줌
		rear = (rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
		return data[result];
	}
}
Data DequeType::get_rear() {
	if (is_empty()) { error("데크가 공백상태 입니다."); return -1; }
	else {									
		return data[rear];
	}
}
void DequeType::print_deque() {
	cout << "front : " << front << " rear : " << rear << endl;
	bool forward = front < rear;
	bool empty = is_empty();

	for (int i = 0; i < MAX_DEQUE_SIZE; i++)
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
	DequeType d;
	d.print_deque();
	for (int i = 0; i < 3; i++)
	{
		d.add_front(i);
		d.print_deque();
	}
	for (int i = 0; i < 3; i++)
	{
		d.delete_rear();
		d.print_deque();
	}
	return 0;
}