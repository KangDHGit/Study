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
#pragma region question_13
class stackType_13 {
	int* data;
	int capacity;
	int top;
public:
	void delete_stack() { delete[] data; }
	void init();
	stackType_13() { init(); }
	bool is_full() { return top == capacity - 1; }
	bool is_empty() { return top == -1; }
	bool resize(int& cap);
	void push(int item);
	int pop();
	int peek();
	~stackType_13() { delete_stack(); }
};
void stackType_13::init() {
	if (data != NULL) { delete_stack(); }
	data = new int[1];
	capacity = 1; top = -1;
}
bool stackType_13::resize(int& cap) {
	int* new_mem = new int[cap];
	if (new_mem == NULL) { return false; }
	else {
		std::copy(&data[0], &data[top + 1], new_mem);
		delete_stack();
		data = new_mem;
		return true;
	}
}
void stackType_13::push(int item) {
	if (is_full()) {
		int cap = capacity * 2;
		if (resize(cap))
			capacity = cap;
		else { cout << "스택 공간확보 실패" << endl; }
	}
	top++; data[top] = item;
}
int stackType_13::pop() {
	if (is_empty()) { cout << "스택 공백에러" << endl; exit(1); }
	else { return data[top--]; }
}
int stackType_13::peek() {
	if (is_empty()) { cout << "스택 공백에러" << endl; exit(1); }
	else { return data[top]; }
}

class question_13 {
	char input[20];
	stackType_13 stack;
public:
	void run();
};
void question_13::run() {
	cout << "정수를 입력하시오 : "; cin >> input;
	/*int len = sizeof(input);
	for (int i = 0; i < len; i++)
	{
		int num = input[i];
		if (stack.is_empty()) { stack.push(num); }
		else if (stack.peek() == (int)input[i]) { continue; }
		else { stack.push(num); }
	}*/
	int i = 0;
	while (input[i] != NULL)
	{
		int num = input[i] - 48;
		i++;
		if (stack.is_empty()) { stack.push(num); }
		else if (stack.peek() == num) { continue; }
		else { cout << stack.pop(); stack.push(num); }
	}

	while (!stack.is_empty())
	{
		cout << stack.pop();
	}
}
#pragma endregion
#pragma region question_14
struct element {
	short r;
	short c;
public:
	element() {};
	element(short row, short col) : r(row), c(col) {};
	void print() { cout << r << ", " << c << " "; }
};

class stackType
{
	element* data;		//동적할당을 위해 포인터로 선언
	int capacity;		//현재크기
	int top;
public:
	void delete_stack() { delete[] data; cout << "데이터 삭제" << endl; }
	void init_stack();
	bool resize_stack(int& cap);
	stackType() { init_stack(); };
	bool is_full() const;
	bool is_empty() const;
	void push(element item);
	element pop();
	element peek();
	void printstack();
	~stackType() { delete_stack(); }
};

#pragma region stackType define
void stackType::init_stack() {
	if (data != NULL) { delete[] data; cout << "기존 데이터를 삭제 했습니다." << endl; }
	data = new element[1];
	top = -1; capacity = 1;
	cout << "스택을 초기화 했습니다." << endl;
}
bool stackType::resize_stack(int& cap) {
	element* new_mem = new element[cap];
	if (new_mem == NULL) return false;
	else {
		std::copy(&data[0], &data[top + 1], new_mem);
		delete[] data;
		data = new_mem;
		return true;
	}
}
bool stackType::is_full() const { return top == capacity - 1; }
bool stackType::is_empty() const { return top == -1; }
void stackType::push(element item) {
	if (is_full()) {
		/*cout << "스택 공간을 추가확보 합니다." << endl;*/
		int cap = capacity * 2;
		if (resize_stack(cap)) {
			/*cout << "공간 추가확보에 성공했습니다." << endl;*/
			capacity = cap;
		}
		else { cout << "공간 추가확보에 실패했습니다." << endl; return; }
	}
	top++;
	data[top] = item;
	//item.print();
}
element stackType::pop() {
	if (is_empty()) { cout << "스택 공백에러!" << endl; exit(1); }
	else { return data[top--]; }
}
element stackType::peek() {
	if (is_empty()) { cout << "스택 공백에러!" << endl; exit(1); }
	else { return data[top]; }
}
void stackType::printstack() {
	for (int i = top + 1; i >= 0; i--)
		data[i].print();
	cout << endl;
}
#pragma endregion

class maze
{
	const static int size = 6;
	element entry;
public:
	char map[size][size] = {
		{'1','1','1','1','1','1'},
		{'e','0','1','0','0','1'},
		{'1','0','0','0','1','1'},
		{'1','0','1','0','1','1'},
		{'1','0','1','0','0','x'},
		{'1','1','1','1','1','1'}
	};
public:
	maze() : entry(1, 0) {};
	element getEntry() { return entry; }
	void print_maze();
};
#pragma region maze_define
void maze::print_maze() {
	cout << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
}
#pragma endregion

class pathManager {
	int around_count = 0;
	int index = 0;
	element paths[50];
	stackType_13 index_stack;
public:
	int get_around() { return around_count; }
	void add_around() { around_count++; }
	void init_around() { around_count = 0; }
	void add_path(element path) {
		if (index < 50) { 
			paths[index++] = path;
			if (around_count > 1)
				index_stack.push(index);

			init_around();
		}
	}
	void delete_path() { index = index_stack.pop(); }
	void print_path();
};
void pathManager::print_path() {
	cout << "최단경로는 : ";
	for (int i = 0; i < index; i++) { paths[i].print(); cout << " > "; }
	cout << endl;
}


class mazeGame {
	stackType stack;	//갈수있는 위치를 저장할 스택자료구조 변수
	element here;		//미로에서의 현재 내 위치
	maze miro;			//미로
	pathManager manager;//최단경로를 저장해줄 매니저
public:
	void push_loc(int r, int c);	//갈수있는 위치인지 판단하고 스택에 저장하는 함수
	void maze_search();				//미로찾기 함수
};

#pragma region mazeGame_define
void mazeGame::push_loc(int r, int c) {
	if (miro.map[r][c] != '.' && miro.map[r][c] != '1') {
		element temp(r, c);
		stack.push(temp);
		manager.add_around();
	}
}
void mazeGame::maze_search() {
	miro.print_maze();
	here = miro.getEntry();

	while (miro.map[here.r][here.c] != 'x')
	{
		int r = here.r, c = here.c;
		miro.map[r][c] = '.';
		miro.print_maze();
		push_loc(r + 1, c);
		push_loc(r - 1, c);
		push_loc(r, c - 1);
		push_loc(r, c + 1);
		if (!stack.is_empty()) {
			if (manager.get_around() > 0)
				manager.add_path(here);
			else
				manager.delete_path();

			here = stack.pop();
		}
		else { cout << "미로찾기 실패!" << endl; break; }
	}

	miro.map[here.r][here.c] = '.';
	
	manager.add_path(here);
	manager.print_path();
	cout << "미로찾기 성공!" << endl;;
}
#pragma endregion

class question_15 {
	mazeGame game;
public:
	void run() {
		game.maze_search();
	}
};
#pragma endregion


int main()
{
	//run_Question_10()
	/*question_11 q11;
	q11.run();*/
	/*qusetion_12 q12;
	q12.run();*/
	/*question_13 q13;
	q13.run();*/
	question_15 q15;
	q15.run();
	return 0;
}