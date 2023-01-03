#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//10. 배열에 들어가있는 정수의 순서를 거꾸로 하는 프로그램을 작성해보자
#pragma region question_10
class stackType_10 {
	const static int capacity = 6;
	int top = -1;
	int data[capacity];
public:
	int getSize() { return capacity; }
	bool is_full() { return top - 1 == capacity; }
	bool is_empty() { return top == -1; }
	void push(int item);
	int pop();
	int peek();
};
void stackType_10::push(int item) {
	if (is_full()) { cout << "스택 포화에러" << endl; exit(1); }
	else { top++; data[top] = item; }
}
int stackType_10::pop() {
	if (is_empty()) { cout << "스택 공백에러" << endl; exit(1); }
	else { return data[top--]; }
}
int stackType_10::peek() {
	if (is_empty()) { cout << "스택 공백에러" << endl; exit(1); }
	else { return data[top]; }
}

void run_Question_10() {
	stackType_10 stack;
	int size = stack.getSize();
	cout << "정수 배열의 크기 : " << size << endl;
	cout << "정수를 입력하시오 : ";
	for (int i = 0; i < size; i++)
	{
		int item;
		cin >> item;
		stack.push(item);
	}
	cout << endl;
	cout << "반전된 정수 배열 : ";
	for (int j = 0; j < size; j++)
		cout << stack.pop() << " ";
	cout << endl;
}
#pragma endregion
//11. 괄호의 번호를 출력하는 프로그램
#pragma region question_11
class stackType_11 {
	short* data;
	int capacity;
	int top;
public:
	void delete_stack() { delete[] data; }
	void init();
	stackType_11() { init(); }
	bool is_full() { return top == capacity - 1; }
	bool is_empty() { return top == -1; }
	bool resize(int& cap);
	void push(short item);
	short pop();
	short peek();
	~stackType_11() { delete_stack(); }
};
void stackType_11::init() {
	if (data != NULL) { delete_stack(); }
	data = new short[1];
	capacity = 1; top = -1;
}
bool stackType_11::resize(int& cap) {
	short* new_mem = new short[cap];
	if (new_mem == NULL) { return false; }
	else {
		std::copy(&data[0], &data[top + 1], new_mem);
		delete_stack();
		data = new_mem;
		return true;
	}
}
void stackType_11::push(short item) {
	if (is_full()) { 
		int cap = capacity * 2;
		if (resize(cap))
			capacity = cap;
		else { cout << "스택 공간확보 실패" << endl; }
	}
	top++; data[top] = item;
}
short stackType_11::pop() {
	if (is_empty()) { cout << "스택 공백에러" << endl; exit(1); }
	else { return data[top--]; }
}
short stackType_11::peek() {
	if (is_empty()) { cout << "스택 공백에러" << endl; exit(1); }
	else { return data[top]; }
}

class question_11 {
	const char* test0 = "((())(()))";
	const char* test1 = "((((()";
	stackType_11 stack;
public:
	void print_bracket_num(const char* brackets);
	void run();
};
void question_11::print_bracket_num(const char* brackets) {
	int len = strlen(brackets);
	short num = 1;
	for (int i = 0; i < len; i++)
	{
		if (brackets[i] == '(') {
			stack.push(num); cout << stack.peek() << " ";
			num++;
		}
		else if (brackets[i] == ')') {
			cout << stack.pop() << " ";	}
	}
	cout << endl;
	stack.init();
}
void question_11::run() {
	cout << "수식 : " << test0 << endl;
	print_bracket_num(test0);
	cout << "수식 : " << test1 << endl;
	print_bracket_num(test1);
}
#pragma endregion
//12. 런길이 압축(run length) 프로그램
#pragma region question_12
class stackType_12 {
	char* data;
	int capacity;
	int top;
public:
	void delete_stack() { delete[] data; }
	void init();
	stackType_12() { init(); }
	bool is_full() { return top == capacity - 1; }
	bool is_empty() { return top == -1; }
	bool resize(int& cap);
	void push(char item);
	char pop();
	char peek();
	~stackType_12() { delete_stack(); }
};
void stackType_12::init() {
	if (data != NULL) { delete_stack(); }
	data = new char[1];
	capacity = 1; top = -1;
}
bool stackType_12::resize(int& cap) {
	char* new_mem = new char[cap];
	if (new_mem == NULL) { return false; }
	else {
		std::copy(&data[0], &data[top + 1], new_mem);
		delete_stack();
		data = new_mem;
		return true;
	}
}
void stackType_12::push(char item) {
	if (is_full()) {
		int cap = capacity * 2;
		if (resize(cap))
			capacity = cap;
		else { cout << "스택 공간확보 실패" << endl; }
	}
	top++; data[top] = item;
}
char stackType_12::pop() {
	if (is_empty()) { cout << "스택 공백에러" << endl; exit(1); }
	else { return data[top--]; }
}
char stackType_12::peek() {
	if (is_empty()) { cout << "스택 공백에러" << endl; exit(1); }
	else { return data[top]; }
}

class qusetion_12 {
	stackType_12 stack;
	const char* test0 = "aaaAbBb";
	const char* test1 = "aCcbAAaBBbbccC";
public:
	void run_length(const char* str) {
		int len = strlen(str);
		int count = 0;
		for (int i = 0; i < len; i++)
		{
			char chr = tolower(str[i]);
			if (stack.is_empty()) {// 비었으면 넣음
				stack.push(chr); count++;
			}
			else if (stack.peek() == chr)
				count++;
			else if (stack.peek() != chr) {
				cout << count << stack.pop();
				stack.push(chr);  count = 1;
			}
		}
		if(!stack.is_empty())
			cout << count << stack.pop();

		cout << endl;
		stack.init();
	}
	void run()
	{
		run_length(test0);
		run_length(test1);
	}
};
#pragma endregion

int main()
{
	//run_Question_10()
	/*question_11 q11;
	q11.run();*/
	qusetion_12 q12;
	q12.run();
	return 0;
}