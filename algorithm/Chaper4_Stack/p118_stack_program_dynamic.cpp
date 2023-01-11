#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using std::cout;
using std::endl;
using std::cin;

#define MAX_STRING 100

class Data {
	int student_no;
	char _name[MAX_STRING];
	char address[MAX_STRING];

public:
	Data() : student_no(0), _name("empty"), address("empty") {};
	Data(int student_no, const char* _name, const char* address);
	char* getName() { return _name; }
	void print();
};

#pragma region Data define
Data::Data(int student_no, const char* _name, const char* address)
{
	this->student_no = student_no;
	strcpy(this->_name, _name);
	strcpy(this->address, address);
}
void Data::print()
{
	cout << "Student_No : " << student_no << endl;
	cout << "Name : " << _name << endl;
	cout << "Address : " << address << endl;
	cout << "====================" << endl;
}
#pragma endregion

class stackType
{
	Data *data;	//�����Ҵ��� ���� �����ͷ� ����
	int capacity;	//����ũ��
	int top;
public:
	void delete_stack() { delete[] data; cout << "������ ����" << endl; }
	void init_stack();
	bool resize_stack(int& cap);
	stackType() { init_stack(); };
	bool is_full();
	bool is_empty();
	void push(Data item);
	Data pop();
	Data peek();
	~stackType() { delete_stack(); }
};

#pragma region stackType define
void stackType::init_stack()
{
	if (data != NULL)
	{
		delete_stack();
		cout << "���������͸� �����߽��ϴ�." << endl;
	}
	data = new Data[1];
	capacity = 1;
	top = -1;
	cout << "���� �ʱ�ȭ �Ϸ�" << endl;
}
bool stackType::resize_stack(int& cap)
{
	Data* new_mem = new Data[cap];			//���ο� ���� �Ҵ�
	if (new_mem == NULL) return false;				//�Ҵ�� ������ NULL���� Ȯ��
	else {
		std::copy(&data[0], &data[top+1], new_mem);	//�Ҵ�� ������ ���������� ����
		delete[] data;								//���������� ����
		data = new_mem;								//���ο� �����̶� �ּ� ����
		return true;
	}
}
bool stackType::is_full() { if (top == capacity - 1) return true; else return false; }
bool stackType::is_empty() { if (top == -1) return true; else return false; }
void stackType::push(Data item)
{
	if (is_full()) { 
		cout << "���ð����� �߰� Ȯ�� �մϴ�." << endl; 
		int cap = capacity * 2;		//2�� Ȯ��
		if (resize_stack(cap))
		{
			cout << "���� �߰�Ȯ���� �����߽��ϴ�." << endl;
			capacity = cap;			//�߰� Ȯ���� �����ϸ� ���� ũ�� ����
		}
		else { cout << "���� �߰�Ȯ���� �����߽��ϴ�." << endl; return; }
	}
	top++; data[top] = item;
	cout << data[top].getName() << "�� �߰� ����" << endl;
	cout << "====================" << endl;
}
Data stackType::pop()
{
	if (is_empty()) { cout << "���� ���鿡��" << endl; delete_stack(); exit(1); }
	else { return data[top--]; }
}
Data stackType::peek()
{
	if (is_empty()) { cout << "���� ���鿡��" << endl; delete_stack(); exit(1); }
	else { return data[top]; }
}
#pragma endregion


int main()
{
	stackType class_A;


	Data student0{ 1,"���ٶ�", "����" };
	Data student1{ 2,"ȫ�浿", "����" };
	Data student2{ 3,"��ö��", "�ϻ�" };
	Data student3{ 4,"�迵��", "��õ" };

	class_A.push(student0);
	class_A.push(student1);
	class_A.push(student2);
	class_A.push(student3);

	class_A.pop().print();
	class_A.pop().print();
	class_A.pop().print();
	class_A.pop().print();
	
	// �ʱ�ȭ �׽�Ʈ
	class_A.init_stack();
	class_A.push(student3);
	class_A.push(student2);
	class_A.pop().print();
	class_A.pop().print();

	return 0;
}