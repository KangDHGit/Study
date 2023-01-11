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
	if (is_full()) { error("��ũ�� ��ȭ���� �Դϴ�."); }
	else {
		rear = (rear + 1) % MAX_DEQUE_SIZE;
		data[rear] = item;
	}
}
Data DequeType::delete_front() {
	if (is_empty()) { error("��ũ�� ������� �Դϴ�."); return -1; }
	else {	//�ڷ� �̵��� ����
		front = (front + 1) % MAX_DEQUE_SIZE;
		return data[front];
	}
}
Data DequeType::get_front() {
	if (is_empty()) { error("��ũ�� ������� �Դϴ�."); return -1; }
	else {
		int result = (front + 1) % MAX_DEQUE_SIZE;
		return data[result];
	}
}
void DequeType::add_front(Data item) {
	//front ������ rear������ �ݴ�� ������(�� ������, -�ε��� ��������)
	if (is_full()) { error("��ũ�� ��ȭ���� �Դϴ�."); }
	else {
		//���� front�ε����� �ǹ̴� ���� �Ǿ��ִ�, �� ����� ����̱� ������
		//������ �߰��� �ϰ� �ε����� �Űܾ� �Ѵ�
		//(rear�� �̹� ���ִ� ���� ������� �ε����� ���� �ű�� ������ �߰�)
		data[front] = item;
		//������ �̵�(-) �� ������ ������ �ʰ� �ε����� �̵��� �� �ֵ��� MAX_SIZE�� ������
		front = (front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	}
}
Data DequeType::delete_rear() {
	if (is_empty()) { error("��ũ�� ������� �Դϴ�."); return -1; }
	else {									//������ ������ �̵�(�� ������ �ε����� ������)
		int result = rear;					//������ �̵� ���� ������ �ε��� ����
		//������ �̵�(-) �� ������ ������ �ʰ� �ε����� �̵��� �� �ֵ��� MAX_SIZE�� ������
		rear = (rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
		return data[result];
	}
}
Data DequeType::get_rear() {
	if (is_empty()) { error("��ũ�� ������� �Դϴ�."); return -1; }
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