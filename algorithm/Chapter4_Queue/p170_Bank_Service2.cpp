#include<iostream>
#include<tuple>
#include<random>

using std::cout;
using std::endl;
using std::cin;
using std::tuple;
using std::make_tuple;
using std::get;

#define MAX_QUEUE_SIZE 5

#pragma region CUSTOMER
typedef class element {
	int id;				//고객 번호
	int arrival_time;	//은행 도착시간
	int service_time;	//은행원이 업무처리시 걸리는 시간
public:
	void init() { id = arrival_time = service_time = -1; }
	element() : id(-1), arrival_time(-1), service_time(-1) {};
	element(int id, int arr_time, int ser_time) : id(id), arrival_time(arr_time), service_time(ser_time) {};
	int get_service_time() { return service_time; }
	int get_id() { return id; }
	tuple<int, int, int> getinfo();
}CUSTOMER;

tuple<int, int, int> element::getinfo() {
	return make_tuple(id, arrival_time, service_time);
}
#pragma endregion

#pragma region QUEUE
typedef class queueType {
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
public:
	void init_queue() { front = 0; rear = 0; }
	queueType() { init_queue(); }
	bool is_full() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	bool is_empty() { return front == rear; }
	void enqueue(element item);
	element dequeue();
	element peek();
	void print_queue();
}QUEUE;

void queueType::enqueue(element item) {
	if (is_full()) { cout << "큐가 포화상태 입니다." << endl; return; }
	else {
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		data[rear] = item;
	}
}
element queueType::dequeue() {
	if (is_empty()) { cout << "큐가 공백상태 입니다." << endl; return element(); }
	else {
		element temp;
		front = (front + 1) % MAX_QUEUE_SIZE;
		temp = data[front];
		data[front].init();
		return temp;
	}
}
element queueType::peek() {
	if (is_empty()) { cout << "큐가 공백상태 입니다." << endl; return element(); }
	else {
		return data[front];
	}
}
void queueType::print_queue() {
	int rear = this->rear;
	cout << "고객 대기번호 :";
	if (!is_empty()) {
		int index = 0;
		for (int i = 0; i < MAX_QUEUE_SIZE; i++)
		{
			index = (rear - i + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			int id = data[index].get_id();
			if (id != -1) { cout.width(3); cout << id << " |"; }
		}
	}
	cout << endl;
}
#pragma endregion

#pragma region BANKER
class banker {
	CUSTOMER customer;	//응대중인 고객
	int time;			//응대중인 고객의 남은 업무처리시간
public:
	banker() : time(0) {};
	void set_customer(CUSTOMER c) { customer = c; time = c.get_service_time(); }
	CUSTOMER get_customer() { return customer; }
	int get_time() { return time; }
	void minus_time() { time -= 1; }
};
#pragma endregion

#pragma region BANK
class bank {
	banker worker0;			//은행원0
	const static int worker_of_number = 3;
	banker workers[worker_of_number];

	QUEUE queue;			//고객 대기줄
	int business_hours;		//은행업무시간(단위 : 분)
	int total_customers;	//총 방문 고객수(고객번호)
	int total_wait;			//은행업무시간 중 고객이 기다린 총 시간
public:
	bank() : business_hours(15), total_customers(0), total_wait(0) {};
	void business_start();
};

void bank::business_start() {
	//시드값을 얻기위한 random_device 생성
	std::random_device rd;

	//random_device를 통해 난수생성 엔진을 초기화 한다.
	std::mt19937 gen(rd());

	//정수(0~9)까지 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
	std::uniform_int_distribution<int> random(0, 9);

	cout << "========은행업무 시작=========" << endl;
	for (int i = 0; i < business_hours; i++)
	{
		cout << "-----현재 시간 : " << i << " -----" << endl;

		//==========은행원 상태 확인==========
		for (int j = 0; j < worker_of_number; j++)
		{
			int remaining_time = workers[j].get_time();	//은행원의 남은 업무처리 시간
			if (remaining_time <= 0)
				cout << "은행원[" << j <<"] : 응대준비 완료" << endl;
		}

		//==========고객방문 확인==========
		int rand = random(gen);
		//분당 프로의 확률 : 0, 1, 2, 3, 4
		if (rand < 8) {								//방문했을경우
			int id = total_customers + 1;
			int service_time = rand + 1;			//고객업무 소요시간은 1~5분
			CUSTOMER customer(id, i, service_time);
			tuple<int, int, int> info = customer.getinfo();

			if (!queue.is_full()) {
				queue.enqueue(customer);
				cout << get<0>(info) << "번 고객님이 방문하셨습니다. 방문시간 : " << i << " / 업무처리시간 : " << get<2>(info) << "분" << endl;
				total_customers++;
			}
			else { cout << "은행 대기열이 꽉 찾습니다." << endl; }
		}
		cout << endl;
		//==========은행원 업무 ==========
		for (int k = 0; k < worker_of_number; k++)
		{
			int remaining_time = workers[k].get_time();
			if (remaining_time <= 0) {
				if (!queue.is_empty()) {				//응대준비가 되었고 대기열이 있을경우
					CUSTOMER customer = queue.dequeue();
					workers[k].set_customer(customer);
					tuple<int, int, int> info = customer.getinfo();
					int id = get<0>(info);
					int waiting_time = i - get<1>(info);
					int service_time = get<2>(info);
					cout << "은행원["<< k <<"] : " << id << "번 고객님 업무처리 시작!. 대기시간 : " << waiting_time << "분 소요 / 남은시간 : " << service_time << "분" << endl;
					workers[k].minus_time();
				}
			}
			else {
				int id = workers[k].get_customer().get_id();
				cout << "은행원[" << k << "] : " << id << "번 고객님 업무처리중. 남은시간 : " << remaining_time << "분" << endl;
				workers[k].minus_time();
			}
		}
		queue.print_queue();
	}
	cout << "========은행업무 종료=========" << endl;
}
#pragma endregion


int main()
{
	bank dahan_bank;
	dahan_bank.business_start();
	return 0;
}