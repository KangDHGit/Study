#include<iostream>

using std::cout;
using std::endl;
using std::cin;

#define MAX_STACK_SIZE 100

typedef int Data;

class stackType
{
	Data data[MAX_STACK_SIZE];
	int top;
public:
	stackType() : top(-1) {};
	bool is_full();
	bool is_empty();
	void push(Data data);
	Data pop();
	Data peek();
};

#pragma region stackType define
bool stackType::is_full()
{
	if (top == MAX_STACK_SIZE) return true;
	else return false;
}

bool stackType::is_empty()
{
	if (top == -1) return true;
	else return false;
}

void stackType::push(Data item)
{
	if (is_full()) { cout << "스택 포화 에러" << endl; return; }
	else
	{
		top++;
		data[top] = item;
	}
}

Data stackType::pop()
{
	if (is_empty()) { cout << "스택 공백 에러" << endl; exit(1); }
	else
		return data[top--];
}

Data stackType::peek()
{
	if (is_empty()) { cout << "스택 공백 에러" << endl; exit(1); }
	else
		return data[top];
}
#pragma endregion

int main()
{
	stackType stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;

	return 0;
}