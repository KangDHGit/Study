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
	Data *data;	//동적할당을 위해 포인터로 선언
	int capacity;	//현재크기
	int top;
public:
	void delete_stack() { delete[] data; cout << "데이터 삭제" << endl; }
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
		cout << "기존데이터를 삭제했습니다." << endl;
	}
	data = new Data[1];
	capacity = 1;
	top = -1;
	cout << "스택 초기화 완료" << endl;
}
bool stackType::resize_stack(int& cap)
{
	Data* new_mem = new Data[cap];			//새로운 공간 할당
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
void stackType::push(Data item)
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
Data stackType::pop()
{
	if (is_empty()) { cout << "스택 공백에러" << endl; delete_stack(); exit(1); }
	else { return data[top--]; }
}
Data stackType::peek()
{
	if (is_empty()) { cout << "스택 공백에러" << endl; delete_stack(); exit(1); }
	else { return data[top]; }
}
#pragma endregion


int main()
{
	stackType class_A;


	Data student0{ 1,"강바람", "서울" };
	Data student1{ 2,"홍길동", "김포" };
	Data student2{ 3,"김철수", "일산" };
	Data student3{ 4,"김영희", "인천" };

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

	return 0;
}