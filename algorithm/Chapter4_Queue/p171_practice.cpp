#include<iostream>
#include<random>

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

//11. 데크를 활용해서 회문 판독하기
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
		if (is_full()) { cout << "데크 포화에러" << endl; }
		else {
			rear = (rear + 1) % MAX_SIZE;
			data[rear] = item;
		}
	}
	char delete_front() {
		if (is_empty()) { cout << "데크 공백에러" << endl; }
		else {
			front = (front + 1) % MAX_SIZE;
			return data[front];
		}
	}
	void add_front(char item) {
		if (is_full()) { cout << "데크 포화에러" << endl; } 
		else {
			data[front] = item;
			front = (front - 1 + MAX_SIZE) % MAX_SIZE;
		}
	}
	char delete_rear() {
		if (is_empty()) { cout << "데크 공백에러" << endl; }
		else{
			char result = data[rear];
			rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
			return result;
		}
	}
	char peek_front() {
		if (is_empty()) { cout << "데크 공백에러" << endl; }
		else {
			char result = (front + 1) % MAX_SIZE;
			return data[result];
		}
	}
	char peek_rear() {
		if (is_empty()) { cout << "데크 공백에러" << endl; }
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
		// (입력 문자열, 출력문자열, 출력문자열의 길이)
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
		if (palindrome(str0)) { cout << "회문입니다." << endl; }
		else { cout << "회문이 아닙니다." << endl; }
		if (palindrome(str1)) { cout << "회문입니다." << endl; }
		else { cout << "회문이 아닙니다." << endl; }
		if (palindrome(str2)) { cout << "회문입니다." << endl; }
		else { cout << "회문이 아닙니다." << endl; }
	}
};
#pragma endregion

//12. 간단한 A-Steal 알고리즘 구현하기
#pragma region question_12
//CPU에 들어갈 task(작업) 클래스
struct task {
	int id;			//작업번호
	int time;		//작업시 소요시간
};

//A_Steel 알고리즘 스캐줄링에 의해 task(작업)을 입력받고 처리할 dequeCpu(CPU) 클래스
//데크(deque) 자료구조에서 변수, 함수 추가
typedef class dequeCpu {
	const static int MAX_SIZE = 5;
	task tasks[MAX_SIZE];
	int front;
	int rear;

	int cpuNum;		//CPU번호
	int taskCount;	//tasks의 task개수(현재 작업개수)
public:
	void init() { front = 0; rear = 0; taskCount = 0; }
	dequeCpu() : cpuNum(0) { init(); }
	dequeCpu(int num) : cpuNum(num) { init(); }
	int get_taskCount() { return taskCount; }	//작업개수 반환
	bool is_full() { return (rear + 1) % MAX_SIZE == front; }
	bool is_empty() { return front == rear; }

	//A_Steel에게 작업을 입력받을때 사용(데이터의 후단 추가)
	void add_rear(task item) {
		if (is_full()) { cout << cpuNum << "번 cpu덱이 꽉 찼습니다." << endl; }
		else {
			taskCount++;
			rear = (rear + 1) % MAX_SIZE;
			tasks[rear] = item;
		}
	}

	//현재 처리중인 작업이 끝났을때 사용(데이터의 전단 삭제)
	task delete_front() {
		if (is_empty()) { cout << cpuNum << "번 cpu덱이 비었습니다." << endl; return task{ -1,-1 }; }
		else {
			taskCount--;
			front = (front + 1) % MAX_SIZE;
			return tasks[front];
		}
	}

	//사용안되는 함수(전단추가)
	void add_front(task item) {
		if(is_full()) { cout << cpuNum << "번 cpu덱이 꽉 찼습니다." << endl; }
		else {
			taskCount++;
			tasks[front] = item;
			front = (front - 1 + MAX_SIZE) % MAX_SIZE;
		}
	}

	//다른 CPU에서 가장 후입된 작업(task)을 가져갈때(steal) 사용(데이터의 후단삭제)
	task delete_rear() {
		if (is_empty()) { cout << cpuNum << "번 cpu덱이 비었습니다." << endl; return task{ -1, -1 }; }
		else {
			taskCount--;
			int result = rear;
			rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
			return tasks[result];
		}
	}
	task peek_front() {
		if (is_empty()) { cout << cpuNum << "번 cpu덱이 비었습니다." << endl; return task{ -1, -1 }; }
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
		cout << endl << "현재작업 남은시간 : " << time << endl;;
	}

	//CPU 작업처리 함수(전단의 task시간 감소처리 및 삭제)
	void run() {
		if (!is_empty()) {						
			int now = (front + 1) % MAX_SIZE;
			tasks[now].time--;
			if (tasks[now].time <= 0)
				delete_front();
		}
	}
}CPU;

//작업개수를 입력받아 CPU들에 작업을 분배해주고, CPU간의 작업교환(Steel)을 처리할
//A_Steal(SCHEDULING) 클래스
typedef class A_Steal {
	const static int CPU_COUNT = 3;	//CPU 개수
	CPU cpus[CPU_COUNT];			
public:
	A_Steal() {
		for (int i = 0; i < CPU_COUNT; i++)
			cpus[i] = CPU(i);
	}

	//CPU의 작업개수(taskCount)를 비교해 가장 적은 CPU에 작업(task)를 추가하는 함수
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
		cout << "CPU[" << compare << "]에 task[" << item.id << "] 추가" << endl;
	}
	void print_cpus() {
		for (size_t i = 0; i < CPU_COUNT; i++)
			cpus[i].print_deque();
		cout << "------------------------------" << endl;
	}

	//CPU들의 작업처리와 CPU간의 작업교환(steal)을 하는 함수
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
						cout << "CPU[" << i << "]이 CPU[" << other << "]의 task를 steal" << endl;
					}
				}
			}
		}
	}
}SCHEDULING;


class question_12 {
	SCHEDULING scheduler;
public:
	//프로그램 실행시간을 입력받아 일정확률로 작업을 생성, 알고리즘에게 작업입력 지시
	void run(int duration) {
		//시드값을 얻기위한 random_device 생성
		std::random_device rd;
		//random_device를 통해 난수생성 엔진을 초기화 한다.
		std::mt19937 gen(rd());
		//정수(0~9)까지 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
		std::uniform_int_distribution<int> random(0, 9);

		cout << "==========프로그램 실행시작==========" << endl;
		int totaltask = 0;
		for (int i = 0; i < duration; i++) {
			cout << "실행시간 : " << i << endl;
			int rand = random(gen);

			//80프로확률로 작업생성, 생성된 작업의 소요시간은 2~6
			if (rand < 8) {
				int tasktime = (rand % 5) + 2;
				task t{totaltask, tasktime};
				scheduler.add_task(t);
				totaltask++;
			}
			scheduler.run();
			scheduler.print_cpus();
		}
		cout << "==========프로그램 종료==========" << endl;
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