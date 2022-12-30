#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using std::cout;
using std::endl;
using std::cin;

class stackType
{
	char* data;	//동적할당을 위해 포인터로 선언
	int capacity;	//현재크기
	int top;
public:
	void delete_stack() { delete[] data; cout << "데이터 삭제" << endl; }
	void init_stack();
	bool resize_stack(int& cap);
	stackType() { init_stack(); };
	bool is_full() const;
	bool is_empty() const;
	void push(char item);
	char pop();
	char peek();
	bool close_bracket_check(char& open, char& close) const;
	bool check_matching(const char* in);
	~stackType() { delete_stack(); }
};

#pragma region stackType define
void stackType::init_stack() 
{
	if (data != NULL)
	{
		delete[] data;
		cout << "기존 데이터를 삭제했습니다" << endl;
	}
	data = new char[1];
	capacity = 1; top = -1;
	cout << "스택을 초기화 했습니다" << endl;
}
bool stackType::resize_stack(int& cap)
{
	char* new_mem = new char[cap];						//새로운 공간 할당
	if (new_mem == NULL) return false;					//할당된 공간이 NULL인지 확인
	else{												
		std::copy(&data[0], &data[top + 1], new_mem);	//할당된 공간에 기존데이터 복사
		delete[] data;									//기존데이터 삭제
		data = new_mem;									//새로운 공간이랑 주소 연결
		return true;
	}
}
bool stackType::is_full() const { if (top == capacity - 1) return true; else return false; }
bool stackType::is_empty() const { if (top == -1) return true; else return false; }
void stackType::push(char item)
{
	if (is_full())
	{
		cout << "스택 공간을 추가 확보 합니다." << endl;
		int cap = capacity * 2;
		if (resize_stack(cap))
		{
			cout << "공간 추가확보에 성공했습니다." << endl;
			capacity = cap;
		}
		else { cout << "공간 추가확보에 실패했습니다." << endl; return; }
	}
	top++;
	data[top] = item;
	cout << item << " 추가 성공" << endl;
	cout << "====================" << endl;
}
char stackType::pop()
{
	if (is_empty()) { cout << "스택 공백에러" << endl; delete_stack(); exit(1); }
	else { return data[top--]; }
}
char stackType::peek()
{
	if (is_empty()) { cout << "스택 공백에러" << endl; delete_stack(); exit(1); }
	else { return data[top]; }
}

bool stackType::close_bracket_check(char& open, char& close) const
{
	switch (open)
	{
	case '(':
		if (close == ')') return true;
	case '{':
		if (close == '}') return true;
	case'[':
		if (close == ']') return true;
	default:
		return false;
	}
}

bool stackType::check_matching(const char* in)
{
	int length = strlen(in);
	for (int i = 0; i < length; i++)
	{
		char chr = in[i];
		switch (chr)
		{
		case '(':
		case '{':
		case '[':
			push(chr); break;	//여는 괄호일경우 스택에 넣음
		case ')':
		case '}':
		case ']':				//닫는 괄호일경우 최근 스택 확인
		{
			cout << chr << " 닫는 괄호 입력 확인" << endl;
			char open_bracket = pop();
			if (!close_bracket_check(open_bracket, chr))
			{
				cout << "여는 괄호의 종류가 맞지 않거나 존재하지 않습니다." << endl;
				return false;	//다를경우 false
			}
			cout << open_bracket << chr << "확인" << endl;;
		}
		default:
			break;
		}
	}
	//스택이 남아있으면 오류, 즉 열고 닫는 괄호 갯수가 안맞는 경우
	if (!is_empty()) { cout << "열고 닫는 괄호의 갯수가 맞지 않습니다." << endl; return false; }
	return true; // 위 과정을 다 통과하면 성공
}
#pragma endregion

int main()
{
	stackType bracket_stack;
	const char* p = "{ A[(i+1)] = 0; }";
	cout << "=====괄호검사 시작=====" << endl;
	if (bracket_stack.check_matching(p))
		cout << "괄호검사 성공" << endl;
	else
		cout << "괄호검사 실패" << endl;
	cout << "=====괄호검사 종료=====" << endl;
	
	return 0;
}