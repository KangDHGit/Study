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
	int id;				//�� ��ȣ
	int arrival_time;	//���� �����ð�
	int service_time;	//������� ����ó���� �ɸ��� �ð�
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
	if (is_full()) { cout << "ť�� ��ȭ���� �Դϴ�." << endl; return; }
	else {
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		data[rear] = item;
	}
}
element queueType::dequeue() {
	if (is_empty()) { cout << "ť�� ������� �Դϴ�." << endl; return element(); }
	else {
		element temp;
		front = (front + 1) % MAX_QUEUE_SIZE;
		temp = data[front];
		data[front].init();
		return temp;
	}
}
element queueType::peek() {
	if (is_empty()) { cout << "ť�� ������� �Դϴ�." << endl; return element(); }
	else {
		return data[front];
	}
}
void queueType::print_queue() {
	int rear = this->rear;
	cout << "�� ����ȣ :";
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
	CUSTOMER customer;	//�������� ��
	int time;			//�������� ���� ���� ����ó���ð�
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
	banker worker0;			//�����0
	const static int worker_of_number = 3;
	banker workers[worker_of_number];

	QUEUE queue;			//�� �����
	int business_hours;		//��������ð�(���� : ��)
	int total_customers;	//�� �湮 ����(����ȣ)
	int total_wait;			//��������ð� �� ���� ��ٸ� �� �ð�
public:
	bank() : business_hours(15), total_customers(0), total_wait(0) {};
	void business_start();
};

void bank::business_start() {
	//�õ尪�� ������� random_device ����
	std::random_device rd;

	//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
	std::mt19937 gen(rd());

	//����(0~9)���� �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
	std::uniform_int_distribution<int> random(0, 9);

	cout << "========������� ����=========" << endl;
	for (int i = 0; i < business_hours; i++)
	{
		cout << "-----���� �ð� : " << i << " -----" << endl;

		//==========����� ���� Ȯ��==========
		for (int j = 0; j < worker_of_number; j++)
		{
			int remaining_time = workers[j].get_time();	//������� ���� ����ó�� �ð�
			if (remaining_time <= 0)
				cout << "�����[" << j <<"] : �����غ� �Ϸ�" << endl;
		}

		//==========���湮 Ȯ��==========
		int rand = random(gen);
		//�д� ������ Ȯ�� : 0, 1, 2, 3, 4
		if (rand < 8) {								//�湮�������
			int id = total_customers + 1;
			int service_time = rand + 1;			//������ �ҿ�ð��� 1~5��
			CUSTOMER customer(id, i, service_time);
			tuple<int, int, int> info = customer.getinfo();

			if (!queue.is_full()) {
				queue.enqueue(customer);
				cout << get<0>(info) << "�� ������ �湮�ϼ̽��ϴ�. �湮�ð� : " << i << " / ����ó���ð� : " << get<2>(info) << "��" << endl;
				total_customers++;
			}
			else { cout << "���� ��⿭�� �� ã���ϴ�." << endl; }
		}
		cout << endl;
		//==========����� ���� ==========
		for (int k = 0; k < worker_of_number; k++)
		{
			int remaining_time = workers[k].get_time();
			if (remaining_time <= 0) {
				if (!queue.is_empty()) {				//�����غ� �Ǿ��� ��⿭�� �������
					CUSTOMER customer = queue.dequeue();
					workers[k].set_customer(customer);
					tuple<int, int, int> info = customer.getinfo();
					int id = get<0>(info);
					int waiting_time = i - get<1>(info);
					int service_time = get<2>(info);
					cout << "�����["<< k <<"] : " << id << "�� ���� ����ó�� ����!. ���ð� : " << waiting_time << "�� �ҿ� / �����ð� : " << service_time << "��" << endl;
					workers[k].minus_time();
				}
			}
			else {
				int id = workers[k].get_customer().get_id();
				cout << "�����[" << k << "] : " << id << "�� ���� ����ó����. �����ð� : " << remaining_time << "��" << endl;
				workers[k].minus_time();
			}
		}
		queue.print_queue();
	}
	cout << "========������� ����=========" << endl;
}
#pragma endregion


int main()
{
	bank dahan_bank;
	dahan_bank.business_start();
	return 0;
}