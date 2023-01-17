#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int element;

struct StackNode {
	element data;
	StackNode* link;
};

class LinkedStackType {
	StackNode* top;
	int size = 0;
	void Init();
public:
	LinkedStackType() { Init(); }
	bool IsEmpty() { return top == nullptr; }
	bool IsFull() { return false; }
	int GetSize() { return size; }
	void Push(element item);
	element Pop();
	element Peek();
	void Clear();
	void Print();
	~LinkedStackType() { Clear(); cout << "동적 할당 메모리 삭제 완료" << endl; }
};

void LinkedStackType::Init() {
	top = nullptr;
	size = 0;
}

void LinkedStackType::Push(element item) {
	StackNode* new_node = new StackNode{ item, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	if (IsEmpty()) {
		top = new_node;
	}
	else {
		new_node->link = top;
		top = new_node;
	}
	size++;
}

element LinkedStackType::Pop() {
	if (IsEmpty()) { cout << "리스트 공백 에러" << endl; return element{ -9999 }; }
	StackNode* removed = top;
	element pop_data = removed->data;
	top = top->link;
	size--;
	delete removed;
	return pop_data;
}
element LinkedStackType::Peek() {
	if (IsEmpty()) { cout << "리스트 공백 에러" << endl; return element{ -9999 }; }
	return top->data;
}

void LinkedStackType::Print() {
	StackNode* iter = top;
	while (iter != nullptr)
	{
		cout.width(2); cout << iter->data << "->";
		iter = iter->link;
	}
	cout << "NULL" << endl;
}

void LinkedStackType::Clear() {
	StackNode* iter = top;
	StackNode* removed = nullptr;
	while (iter != nullptr)
	{
		removed = iter;
		iter = iter->link;
		delete removed;
	}
	size = 0;
}

int main()
{
	LinkedStackType* stack = new LinkedStackType;
	for (int i = 0; i < 5; i++)
		stack->Push(i);

	stack->Print();
	for (int i = 0; i < 3; i++)
		stack->Pop();

	stack->Print();
	delete stack;
	return 0;
}