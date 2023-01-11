#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using std::cout;
using std::endl;
using std::cin;

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

class Data {
	int student_no;
	char _name[MAX_STRING];
	char address[MAX_STRING];

public:
	Data() : student_no(0), _name("empty"), address("empty") {};
	Data(int student_no, const char* _name, const char* address);
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
	cout << "====================" << endl;
	cout << "Student_No : " << student_no << endl;
	cout << "Name : " << _name << endl;
	cout << "Address : " << address << endl;
}
#pragma endregion

class stackType
{
	Data data[MAX_STACK_SIZE];
	int top;
public:
	stackType() : top(-1) {};
	bool is_full();
	bool is_empty();
	void push(Data item);
	Data pop();
	Data peek();
};

#pragma region stackType define
bool stackType::is_full() { if (top == MAX_STACK_SIZE) return true; else return false; }
bool stackType::is_empty() { if (top == -1) return true; else return false; }
void stackType::push(Data item)
{
	if (is_full()) { cout << "스택 포화에러" << endl; exit(1); }
	else { top++; data[top] = item; }
}
Data stackType::pop()
{
	if (is_empty()) { cout << "스택 공백에러" << endl; exit(1); }
	else { return data[top--]; }
}
Data stackType::peek()
{
	if (is_empty()) { cout << "스택 공백에러" << endl; exit(1); }
	else { return data[top]; }
}
#pragma endregion


int main()
{
	stackType class_A;

	Data student0{ 1,"강대한", "김포" };
	Data student1{ 2,"홍길동", "서울" };
	Data student2{ 3,"김철수", "일산" };

	class_A.push(student0);
	class_A.push(student1);
	class_A.push(student2);

	class_A.pop().print();
	class_A.pop().print();
	class_A.pop().print();
	class_A.pop().print();
	
	return 0;
}