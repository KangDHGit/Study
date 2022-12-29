#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using std::cout;
using std::endl;
using std::cin;

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

class element {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];

public:
	element() : student_no(0), name("empty"), address("empty") {};
	element(int student_no, const char* name, const char* address);
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
	cout << "====================" << endl;
	cout << "Student_No : " << student_no << endl;
	cout << "Name : " << name << endl;
	cout << "Address : " << address << endl;
}
#pragma endregion

class stackType
{
	element data[MAX_STACK_SIZE];
	int top;
public:
	stackType() : top(-1) {};
	bool is_full();
	bool is_empty();
	void push(element item);
	element pop();
	element peek();
};

#pragma region stackType define
bool stackType::is_full() { if (top == MAX_STACK_SIZE) return true; else return false; }
bool stackType::is_empty() { if (top == -1) return true; else return false; }
void stackType::push(element item)
{
	if (is_full()) { cout << "스택 포화에러" << endl; exit(1); }
	else { top++; data[top] = item; }
}
element stackType::pop()
{
	if (is_empty()) { cout << "스택 공백에러" << endl; exit(1); }
	else { return data[top--]; }
}
element stackType::peek()
{
	if (is_empty()) { cout << "스택 공백에러" << endl; exit(1); }
	else { return data[top]; }
}
#pragma endregion


int main()
{
	stackType class_A;

	element student0{ 1,"강대한", "김포" };
	element student1{ 2,"홍길동", "서울" };
	element student2{ 3,"김철수", "일산" };

	class_A.push(student0);
	class_A.push(student1);
	class_A.push(student2);

	class_A.pop().print();
	class_A.pop().print();
	class_A.pop().print();
	class_A.pop().print();
	
	return 0;
}