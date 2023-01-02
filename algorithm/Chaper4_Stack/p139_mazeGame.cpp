#include<iostream>

using std::cout;
using std::endl;
using std::cin;

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
	int capacity;	//현재크기
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
			cout << map[i][j] <<" ";
		cout << endl;
	}
}
#pragma endregion

class mazeGame {
	stackType stack;	//갈수있는 위치를 저장할 스택자료구조 변수
	element here;		//미로에서의 현재 내 위치
	maze miro;			//미로
public:
	void push_loc(int r, int c);	//갈수있는 위치인지 판단하고 스택에 저장하는 함수
	void maze_search();				//미로찾기 함수
};

#pragma region mazeGame
void mazeGame::push_loc(int r, int c) {
	if (r >= 0 && c >= 0) {
		if ((miro.map[r][c] != '.') && (miro.map[r][c] != '1')) {
			element temp(r, c);
			stack.push(temp);
		}
	}
}
void mazeGame::maze_search() {
	here = miro.getEntry();
	while (miro.map[here.r][here.c] != 'x')
	{
		int r = here.r;
		int c = here.c;
		miro.map[here.r][here.c] = '.';	// 지나온길 표시		
		miro.print_maze();
		//상하좌우 갈수있는 위치를 탐색후 스택에 저장
		push_loc(r + 1, c);
		push_loc(r - 1, c);
		push_loc(r, c - 1);
		push_loc(r, c + 1);
		//갈수있는 곳이 없으면 실패 아니면 가장 최근에 저장한 위치로 이동
		if (stack.is_empty()) { cout << "실패" << endl; return; }
		else {
			here = stack.pop();
		}
		//stack.printstack();
	}
	cout << "성공" << endl;
}
#pragma endregion


int main()
{
	mazeGame game;
	game.maze_search();
	return 0;
}