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
	element *data;	//동적할당을 위해 포인터로 선언
	int capacity;	//현재크기
	int top;
public:
	void delete_stack() { delete[] data; cout << "데이터 삭제" << endl; }
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
		cout << "기존데이터를 삭제했습니다." << endl;
	}
	data = new element[1];
	capacity = 1;
	top = -1;
	cout << "스택 초기화 완료" << endl;
}
bool stackType::resize_stack(int& cap)
{
	element* new_mem = new element[cap];			//새로운 공간 할당
	if (new_mem == NULL) return false;				//할당된 공간이 NULL인지 확인
	else {
		std::copy(&data[0], &data[top+1], new_mem);	//할당된 공간에 기존데이터 복사
		delete[] data;								//기존데이터 삭제
		data = new_mem;								//새로운 공간이랑 주소 연결
		return true;
	}
}
bool stackType::is_full() { if (top == capacity - 1) return true; else return false; }
bool stackType::is_empty() { if (top == -1) return true; else return false; }
void stackType::push(element item)
{
	if (is_full()) { 
		cout << "스택공간을 추가 확보 합니다." << endl; 
		int cap = capacity * 2;		//2배 확보
		if (resize_stack(cap))
		{
			cout << "공간 추가확보에 성공했습니다." << endl;
			capacity = cap;			//추가 확보에 성공하면 현재 크기 변경
		}
		else { cout << "공간 추가확보에 실패했습니다." << endl; return; }
	}
	top++; data[top] = item;
	cout << data[top].getName() << "님 추가 성공" << endl;
	cout << "====================" << endl;
}
element stackType::pop()
{
	if (is_empty()) { cout << "스택 공백에러" << endl; delete_stack(); exit(1); }
	else { return data[top--]; }
}
element stackType::peek()
{
	if (is_empty()) { cout << "스택 공백에러" << endl; delete_stack(); exit(1); }
	else { return data[top]; }
}
#pragma endregion


int main()
{
	stackType class_A;


	element student0{ 1,"강바람", "서울" };
	element student1{ 2,"홍길동", "김포" };
	element student2{ 3,"김철수", "일산" };
	element student3{ 4,"김영희", "인천" };

	class_A.push(student0);
	class_A.push(student1);
	class_A.push(student2);
	class_A.push(student3);

	class_A.pop().print();
	class_A.pop().print();
	class_A.pop().print();
	class_A.pop().print();
	
	// 초기화 테스트
	class_A.init_stack();
	class_A.push(student3);
	class_A.push(student2);
	class_A.pop().print();
	class_A.pop().print();

	class_A.delete_stack();

	return 0;
}