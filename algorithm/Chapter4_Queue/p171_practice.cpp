#include<iostream>
#include<random>

using std::cout;
using std::endl;
using std::cin;

//9. 2���� �������� ť ����
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
		if (is_full()) { cout << "���� ��ȭ����" << endl; }
		else { top++; data[top] = item; }
	}
	int pop() {
		if (is_empty()) { cout << "���� ���鿡��" << endl; return -1; }
		else { return data[top--]; }
	}
	int peek() {
		if (is_empty()) { cout << "���� ���鿡��" << endl; return -1; }
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
		if (is_full()) { cout << "ť ��ȭ����" << endl; }
		else { rear.push(item); }
	}
	int dequeue() {
		if (front.is_empty()) {
			if (rear.is_empty()) { cout << "ť ���鿡��" << endl; return -1; }
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
			if (rear.is_empty()) { cout << "ť ���鿡��" << endl; return -1; }
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

//10. ť�� Ȱ���ؼ� �Ǻ���ġ ���� ����ϱ�
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
		if (is_full()) { cout << "ť ��ȭ����" << endl; }
		else{
			rear = (rear + 1) % MAX_SIZE;
			data[rear] = item;
		}
	}
	int dequeue() {
		if (is_empty()) { cout << "ť ���鿡��" << endl; return -1; }
		else {
			front = (front + 1) % MAX_SIZE;
			return data[front];
		}
	}
	int peek() {
		if (is_empty()) { cout << "ť ���鿡��" << endl; return -1; }
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

//11. ��ũ�� Ȱ���ؼ� ȸ�� �ǵ��ϱ�
#pragma region question_11
class dequeType {
	const static int MAX_SIZE = 10;
	char data[MAX_SIZE];
	int rear;
	int front;
public:
	dequeType() { init(); }
	void init() { front = 0; rear = 0; }
	bool is_full() { return (rear + 1) % MAX_SIZE == front; }
	bool is_empty() { return rear == front; }
	void add_rear(char item) {
		if (is_full()) { cout << "��ũ ��ȭ����" << endl; }
		else {
			rear = (rear + 1) % MAX_SIZE;
			data[rear] = item;
		}
	}
	char delete_front() {
		if (is_empty()) { cout << "��ũ ���鿡��" << endl; }
		else {
			front = (front + 1) % MAX_SIZE;
			return data[front];
		}
	}
	void add_front(char item) {
		if (is_full()) { cout << "��ũ ��ȭ����" << endl; } 
		else {
			data[front] = item;
			front = (front - 1 + MAX_SIZE) % MAX_SIZE;
		}
	}
	char delete_rear() {
		if (is_empty()) { cout << "��ũ ���鿡��" << endl; }
		else{
			char result = data[rear];
			rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
			return result;
		}
	}
	char peek_front() {
		if (is_empty()) { cout << "��ũ ���鿡��" << endl; }
		else {
			char result = (front + 1) % MAX_SIZE;
			return data[result];
		}
	}
	char peek_rear() {
		if (is_empty()) { cout << "��ũ ���鿡��" << endl; }
		else{
			return data[rear];
		}
	}
};

class question_11 {
	dequeType deque;
	char str0[7] = "E_y  e";
	char str1[9] = "ma2dA_m";
	char str2[9] = "R*a)dAr";
public:
	void reword(char in[], char* out, int* outcount) {
		// (�Է� ���ڿ�, ��¹��ڿ�, ��¹��ڿ��� ����)
		int len = strlen(in);
		for (int i = 0; i < len; i++)
		{
			char chr = in[i];
			if (chr >= 'a' && chr <= 'z') {
				out[(*outcount)++] = chr;
			}
			else if (chr >= 'A' && chr <= 'Z') {
				char low = tolower(chr);
				out[(*outcount)++] = low;
			}
		}
	}

	bool palindrome(char str[]) {
		deque.init();
		char word[10];
		int wordindex = 0;

		reword(str, word, &wordindex);

		for (int j = 0; j < wordindex; j++)
		{
			deque.add_rear(word[j]);
		}
		int count = wordindex / 2;
		for (int i = 0; i < count; i++)
		{
			cout << deque.peek_front() << " | " << deque.peek_rear() << endl;
			if (deque.delete_front() != deque.delete_rear())
				return false;
		}
		return true;
	}

	void run() {
		if (palindrome(str0)) { cout << "ȸ���Դϴ�." << endl; }
		else { cout << "ȸ���� �ƴմϴ�." << endl; }
		if (palindrome(str1)) { cout << "ȸ���Դϴ�." << endl; }
		else { cout << "ȸ���� �ƴմϴ�." << endl; }
		if (palindrome(str2)) { cout << "ȸ���Դϴ�." << endl; }
		else { cout << "ȸ���� �ƴմϴ�." << endl; }
	}
};
#pragma endregion

//12. ������ A-Steal �˰��� �����ϱ�
#pragma region question_12
//CPU�� �� task(�۾�) Ŭ����
struct task {
	int id;			//�۾���ȣ
	int time;		//�۾��� �ҿ�ð�
};

//A_Steel �˰��� ��ĳ�ٸ��� ���� task(�۾�)�� �Է¹ް� ó���� dequeCpu(CPU) Ŭ����
//��ũ(deque) �ڷᱸ������ ����, �Լ� �߰�
typedef class dequeCpu {
	const static int MAX_SIZE = 5;
	task tasks[MAX_SIZE];
	int front;
	int rear;

	int cpuNum;		//CPU��ȣ
	int taskCount;	//tasks�� task����(���� �۾�����)
public:
	void init() { front = 0; rear = 0; taskCount = 0; }
	dequeCpu() : cpuNum(0) { init(); }
	dequeCpu(int num) : cpuNum(num) { init(); }
	int get_taskCount() { return taskCount; }	//�۾����� ��ȯ
	bool is_full() { return (rear + 1) % MAX_SIZE == front; }
	bool is_empty() { return front == rear; }

	//A_Steel���� �۾��� �Է¹����� ���(�������� �Ĵ� �߰�)
	void add_rear(task item) {
		if (is_full()) { cout << cpuNum << "�� cpu���� �� á���ϴ�." << endl; }
		else {
			taskCount++;
			rear = (rear + 1) % MAX_SIZE;
			tasks[rear] = item;
		}
	}

	//���� ó������ �۾��� �������� ���(�������� ���� ����)
	task delete_front() {
		if (is_empty()) { cout << cpuNum << "�� cpu���� ������ϴ�." << endl; return task{ -1,-1 }; }
		else {
			taskCount--;
			front = (front + 1) % MAX_SIZE;
			return tasks[front];
		}
	}

	//���ȵǴ� �Լ�(�����߰�)
	void add_front(task item) {
		if(is_full()) { cout << cpuNum << "�� cpu���� �� á���ϴ�." << endl; }
		else {
			taskCount++;
			tasks[front] = item;
			front = (front - 1 + MAX_SIZE) % MAX_SIZE;
		}
	}

	//�ٸ� CPU���� ���� ���Ե� �۾�(task)�� ��������(steal) ���(�������� �Ĵܻ���)
	task delete_rear() {
		if (is_empty()) { cout << cpuNum << "�� cpu���� ������ϴ�." << endl; return task{ -1, -1 }; }
		else {
			taskCount--;
			int result = rear;
			rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
			return tasks[result];
		}
	}
	task peek_front() {
		if (is_empty()) { cout << cpuNum << "�� cpu���� ������ϴ�." << endl; return task{ -1, -1 }; }
		else {
			int result = (front + 1) % MAX_SIZE;
			task task = tasks[result];
			return task;
		}
	}
	void print_deque() {
		cout << "CPU[" << cpuNum << "] :";
		for (int i = 0; i < taskCount; i++)
		{
			int result = (front + 1 + i) % MAX_SIZE;
			cout.width(3); cout << tasks[result].id << " |";
		}
		int time = is_empty() ? 0 : peek_front().time;
		cout << endl << "�����۾� �����ð� : " << time << endl;;
	}

	//CPU �۾�ó�� �Լ�(������ task�ð� ����ó�� �� ����)
	void run() {
		if (!is_empty()) {						
			int now = (front + 1) % MAX_SIZE;
			tasks[now].time--;
			if (tasks[now].time <= 0)
				delete_front();
		}
	}
}CPU;

//�۾������� �Է¹޾� CPU�鿡 �۾��� �й����ְ�, CPU���� �۾���ȯ(Steel)�� ó����
//A_Steal(SCHEDULING) Ŭ����
typedef class A_Steal {
	const static int CPU_COUNT = 3;	//CPU ����
	CPU cpus[CPU_COUNT];			
public:
	A_Steal() {
		for (int i = 0; i < CPU_COUNT; i++)
			cpus[i] = CPU(i);
	}

	//CPU�� �۾�����(taskCount)�� ���� ���� ���� CPU�� �۾�(task)�� �߰��ϴ� �Լ�
	void add_task(task item) {
		int compare = 0;
		int minCount = cpus[0].get_taskCount();
		for (int i = 1; i < CPU_COUNT; i++)
		{
			if (cpus[i].get_taskCount() < minCount) {
				minCount = cpus[i].get_taskCount();
				compare = i;
			}
		}
		cpus[compare].add_rear(item);
		cout << "CPU[" << compare << "]�� task[" << item.id << "] �߰�" << endl;
	}
	void print_cpus() {
		for (size_t i = 0; i < CPU_COUNT; i++)
			cpus[i].print_deque();
		cout << "------------------------------" << endl;
	}

	//CPU���� �۾�ó���� CPU���� �۾���ȯ(steal)�� �ϴ� �Լ�
	void run() {
		for (int i = 0; i < CPU_COUNT; i++)
			cpus[i].run();

		if (CPU_COUNT > 1) {
			for (int i = 0; i < CPU_COUNT; i++)
			{
				if (cpus[i].is_empty()) {
					int other = (i - 1) % CPU_COUNT;
					if (cpus[other].get_taskCount() > 1) {
						cpus[i].add_rear(cpus[other].delete_rear());
						cout << "CPU[" << i << "]�� CPU[" << other << "]�� task�� steal" << endl;
					}
				}
			}
		}
	}
}SCHEDULING;


class question_12 {
	SCHEDULING scheduler;
public:
	//���α׷� ����ð��� �Է¹޾� ����Ȯ���� �۾��� ����, �˰��򿡰� �۾��Է� ����
	void run(int duration) {
		//�õ尪�� ������� random_device ����
		std::random_device rd;
		//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
		std::mt19937 gen(rd());
		//����(0~9)���� �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
		std::uniform_int_distribution<int> random(0, 9);

		cout << "==========���α׷� �������==========" << endl;
		int totaltask = 0;
		for (int i = 0; i < duration; i++) {
			cout << "����ð� : " << i << endl;
			int rand = random(gen);

			//80����Ȯ���� �۾�����, ������ �۾��� �ҿ�ð��� 2~6
			if (rand < 8) {
				int tasktime = (rand % 5) + 2;
				task t{totaltask, tasktime};
				scheduler.add_task(t);
				totaltask++;
			}
			scheduler.run();
			scheduler.print_cpus();
		}
		cout << "==========���α׷� ����==========" << endl;
	}
};
#pragma endregion


int main()
{
	/*question_9 q9;
	q9.run();*/
	/*question_10 q10;
	cout << q10.fibo(10) << endl;*/
	/*question_11 q11;
	q11.run();*/
	question_12 q12;
	q12.run(50);
	return 0;
}