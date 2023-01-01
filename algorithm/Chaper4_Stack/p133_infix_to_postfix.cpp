#include<iostream>

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
void stackType::init_stack() {
	if (data != NULL) {
		delete[] data; cout << "기존 데이터를 삭제 했습니다." << endl;
	}
	data = new char[1];
	capacity = 1; top = -1;
	/*cout << "스택을 초기화 했습니다." << endl;*/
}
bool stackType::resize_stack(int& cap) {
	char* new_mem = new char[cap];
	if (new_mem == NULL) { return false; }
	else {
		std::copy(&data[0], &data[top + 1], new_mem);
		delete[] data;
		data = new_mem;
		return true;
	}
}
bool stackType::is_full() const { return (top == capacity - 1); }
bool stackType::is_empty() const { cout << "top : " << top << endl; return (top == -1); }
void stackType::push(char item) {
	if (is_full()) {
		/*cout << "스택 공간을 추가확보 합니다." << endl;*/
		int cap = capacity * 2;
		if (resize_stack(cap)) {
			/*cout << "공간 추가확보에 성공했습니다." << endl;*/
			capacity = cap;
		}
		else { /*cout << "공간 추가확보에 실패했습니다." << endl;*/ return; }
	}
	top++;
	data[top] = item;
	/*cout << item << " 추가 성공" << endl;
	cout << "====================" << endl;*/
}
char stackType::pop() {
	if (is_empty()) { cout << "스택 공백 에러!" << endl; exit(1); }
	else { return data[top--]; }
}
char stackType::peek() {
	if (is_empty()) { cout << "스택 공백 에러!" << endl; exit(1); }
	else { return data[top]; }
}
#pragma endregion

int prec(char op)
{
	switch (op)
	{
	case '(':
	case ')':
		return 0;
	case'+':
	case'-':
		return 1;
	case'*':
	case'/':
	case'%':
		return 2;
	default:
		return -1;
	}
}

void infix_to_postfix(const char exp[])
{
	char ch, top_op;
	int len = strlen(exp);
	stackType stack;

	for (int i = 0; i < len; i++)
	{
		// 1. 피연산자 일경우 바로출력 default
		// 2. 사칙연산자일경우 if(맨 위 연산자랑 비교)
		//	true. 맨 위 연산자 더 크거나 같으면 맨 위 연산자 출력
		//	false. 아니면 스택에 저장 
		// 3. 여는 괄호 일경우 무조건 스택에 저장
		// 4. 닫는 괄호 일경우 여는 연산자가 pop될때까지 출력
		ch = exp[i];
		switch (ch)
		{
		case '+':
		case '-':
		case'*':
		case '/':
		case'%':
			while (!stack.is_empty() && prec(stack.peek()) >= prec(ch)) { cout << stack.pop(); break; }
			stack.push(ch); break;
		case'(':
			stack.push(ch);
			break;
		case')':
			top_op = stack.pop();
			while (top_op != '(')
			{
				cout << top_op;
				top_op = stack.pop();
			}
			break;
		default:
			cout << ch;
			break;
		}
	}
	while (!stack.is_empty())
		cout << stack.pop();
	cout << endl;
}

int main()
{
	const char* s = "(2+3)*4+9";
	cout << "중위표기수식 : " << s << endl;
	cout << "후위표기수식 : "; infix_to_postfix(s);
	return 0;
}