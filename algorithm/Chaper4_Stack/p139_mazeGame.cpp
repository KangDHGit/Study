#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct element {
	short r;
	short c;
};

class stackType
{
	element* data;		//�����Ҵ��� ���� �����ͷ� ����
	int capacity;	//����ũ��
	int top;
public:
	void delete_stack() { delete[] data; cout << "������ ����" << endl; }
	void init_stack();
	bool resize_stack(int& cap);
	stackType() { init_stack(); };
	bool is_full() const;
	bool is_empty() const;
	void push(element item);
	element pop();
	element peek();
	~stackType() { delete_stack(); }
};

#pragma region stackType define
void stackType::init_stack() {
	if (data != NULL) { delete[] data; cout << "���� �����͸� ���� �߽��ϴ�." << endl; }
	data = new element[1];
	top = -1; capacity = 1;
	cout << "������ �ʱ�ȭ �߽��ϴ�." << endl;
}
bool stackType::resize_stack(int& cap) {
	element* new_mem = new element[cap];
	if (new_mem == NULL) return false;
	else {
		std::copy(&data[0], &data[top], new_mem);
		delete[] data;
		data = new_mem;
		return true;
	}
}
bool stackType::is_full() const { return top == capacity - 1; }
bool stackType::is_empty() const { return top == -1; }
void stackType::push(element item) {
	if (is_full()) {
		/*cout << "���� ������ �߰�Ȯ�� �մϴ�." << endl;*/
		int cap = capacity * 2;
		if (resize_stack(cap)) {
			/*cout << "���� �߰�Ȯ���� �����߽��ϴ�." << endl;*/
			capacity = cap;
		}
		else { cout << "���� �߰�Ȯ���� �����߽��ϴ�." << endl; return; }
	}
	top++;
	data[top] = item;
}
element stackType::pop() {
	if (is_empty()) { cout << "���� ���鿡��!" << endl; exit(1); }
	else { return data[top--]; }
}
element stackType::peek() {
	if (is_empty()) { cout << "���� ���鿡��!" << endl; exit(1); }
	else { return data[top]; }
}
#pragma endregion

class maze
{
	const static int size = 6;
	char map[size][size] = {
		{'1','1','1','1','1','1'},
		{'e','0','1','0','0','1'},
		{'1','0','0','0','1','1'},
		{'1','0','1','0','1','1'},
		{'1','0','1','0','0','x'},
		{'1','1','1','1','1','1'}
	};
public:
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


int main()
{
	maze miro;
	miro.print_maze();
	return 0;
}