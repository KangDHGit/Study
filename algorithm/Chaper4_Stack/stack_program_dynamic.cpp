#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using std::cout;
using std::endl;
using std::cin;

#define MAX_STRING 100

class element {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];

public:
	element() : student_no(0), name("empty"), address("empty") {};
	element(int student_no, const char* name, const char* address);
	char* getName() { return name; }
	void print();
};

#pragma region element define
element::element(int student_no, const char* name, const char* address)
{
	this->student_no = student_no;
	strcpy(this->name, name);
	strcpy(this->address, address);
}
void element::print()
{
	cout << "Student_No : " << student_no << endl;
	cout << "Name : " << name << endl;
	cout << "Address : " << address << endl;
	cout << "====================" << endl;
}
#pragma endregion

class stackType
{
	element *data;	//�����Ҵ��� ���� �����ͷ� ����
	int capacity;	//����ũ��
	int top;
public:
	void delete_stack() { delete[] data; cout << "������ ����" << endl; }
	void init_stack();
	bool resize_stack(int& cap);
	stackType() { init_stack(); };
	bool is_full();
	bool is_empty();
	void push(element item);
	element pop();
	element peek();
};

#pragma region stackType define
void stackType::init_stack()
{
	if (data != NULL)
	{
		delete_stack();
		cout << "���������͸� �����߽��ϴ�." << endl;
	}
	data = new element[1];
	capacity = 1;
	top = -1;
	cout << "���� �ʱ�ȭ �Ϸ�" << endl;
}
bool stackType::resize_stack(int& cap)
{
	element* new_mem = new element[cap];			//���ο� ���� �Ҵ�
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
void stackType::push(element item)
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
element stackType::pop()
{
	if (is_empty()) { cout << "���� ���鿡��" << endl; delete_stack(); exit(1); }
	else { return data[top--]; }
}
element stackType::peek()
{
	if (is_empty()) { cout << "���� ���鿡��" << endl; delete_stack(); exit(1); }
	else { return data[top]; }
}
#pragma endregion


int main()
{
	stackType class_A;


	element student0{ 1,"���ٶ�", "����" };
	element student1{ 2,"ȫ�浿", "����" };
	element student2{ 3,"��ö��", "�ϻ�" };
	element student3{ 4,"�迵��", "��õ" };

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

	class_A.delete_stack();

	return 0;
}