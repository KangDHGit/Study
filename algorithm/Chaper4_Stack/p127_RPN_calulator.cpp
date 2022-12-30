#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using std::cout;
using std::endl;
using std::cin;

class stackType
{
	char* data;		//동적할당을 위해 포인터로 선언
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
	bool not_oper(char& item) const;
	int eval(const char* exp);
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
	else {
		std::copy(&data[0], &data[top + 1], new_mem);	//할당된 공간에 기존데이터 복사
		delete[] data;									//기존데이터 삭제
		data = new_mem;									//새로운 공간이랑 주소 연결
		return true;
	}
}
bool stackType::is_full()const { if (top == capacity - 1) return true; else return false; }
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
	cout << (int)item << " 추가 성공" << endl;
	cout << "====================" << endl;
}
char stackType::pop()
{
	if (is_empty()) { cout << "스택 공백 에러! 피연산자가 존재하지 않습니다." << endl; exit(1); }
	else { return data[top--]; }
}
char stackType::peek()
{
	if (is_empty()) { cout << "스택 공백 에러! 피연산자가 존재하지 않습니다." << endl; exit(1); }
	else { return data[top]; }
}
bool stackType::not_oper(char& item) const
{
	return item != '+' && item != '-' && item != '*' && item != '/' && item != '%';
}
int stackType::eval(const char* exp)
{
	int op1, op2;				//계산할때 사용할 피연산자 변수
	int value = 0;				//피연산자 일경우 스택에 저장할 변수
	int len = strlen(exp);		//문자배열 exp의 길이
	char ch;					//exp에서 하나씩 문자를 받을 변수;

	for (int i = 0; i < len; i++)
	{
		ch = exp[i];
		if (not_oper(ch))		//연산자가 아닐경우(피연산자 일경우)
		{
			value = ch - '0';	//문자를 숫자로 변환(아스키 코드)
			push(value);		//스택에 저장
		}
		else
		{
			op2 = pop(); op1 = pop();		//나중에 저장된 피연산자부터 가져온다.
			cout << "연산자 감지! : " << op1 << ' ' << ch << ' ' << op2 << endl;
			switch (ch)
			{
			case'+':
				value = op1 + op2; push(value);	//계산후 다시 스택에 저장
				break;
			case'-':
				value = op1 - op2; push(value);
				break;
			case'*':
				value = op1 * op2; push(value);
				break;
			case'/':
				value = op1 / op2; push(value);
				break;
			case'%':
				value = op1 % op2; push(value);
				break;
			}
		}
	}
	return pop();
}
#pragma endregion

int main()
{
	stackType stack;
	int result;
	cout << "(8 / 2) - 3 + (3 * 2)" << endl;
	cout << "후위표기식은 82/3-32*+" << endl;
	result = stack.eval("82/3-32*+");
	cout << "계산결과 : " << result << endl;
}