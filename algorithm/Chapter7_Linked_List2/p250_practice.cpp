#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//원형 연결리스트 구현 및 특정한 값을 탐색하고 노드를 반환하는 search 함수 작성
typedef int element;
#pragma region question_3
struct NodeType {
	element data;
	NodeType* link;
};

class CircularList {
	NodeType* head;
	int size;
	void Init();
public:
	CircularList() { Init(); }
	void InsertFirst(element item);
	void InsertLast(element	item);
	NodeType* Search(element data);
	void Clear();
	~CircularList() { Clear(); cout << "동적할당 메모리 삭제 완료" << endl; }
};

void CircularList::Init() {
	head = nullptr; size = 0;
}

void CircularList::InsertFirst(element item) {
	NodeType* new_node = new NodeType{ item, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	if (head == nullptr) { head = new_node; new_node->link = head; }
	else {
		new_node->link = head->link;
		head->link = new_node;
	}
	size++;
}
void CircularList::InsertLast(element item) {
	NodeType* new_node = new NodeType{ item, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	if (head == nullptr) { head = new_node; new_node->link = head; }
	else {
		new_node->link = head->link;
		head->link = new_node;
		head = new_node;
	}
}
#pragma endregion


int main()
{
	return 0;
}