#include<iostream>
#include<random>

using std::cout;
using std::endl;
using std::cin;

typedef int element;

struct ListNode {
	element data;
	ListNode* link;
};

class CircularList {
	ListNode* head;
	ListNode* prehead;
	int size;
public:
	void Init() { size = 0; head = nullptr; }
	CircularList() { Init(); }
	int GetLength() { return size; }
	void InsertFirst(element item);
	void InsertLast(element item);
	void Print();
	void Clear();
	~CircularList() { Clear(); cout << "동적메모리 삭제 성공" << endl; }
};
void CircularList::InsertFirst(element item) {
	ListNode* new_node = new ListNode{ item, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	if (head == nullptr) {
		head = new_node;
		new_node->link = head;	//원형이니 끝에끼리 연결
		size++;
		return;
	}
	if (head->link == head) { prehead = new_node; }
	new_node->link = head->link;
	head->link = new_node;
	size++;
}
void CircularList::InsertLast(element item) {
	ListNode* new_node = new ListNode{ item, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	if (head == nullptr) {
		head = new_node;
		new_node->link = head;	//원형이니 끝에끼리 연결
		size++;
		return;
	}

	new_node->link = head->link;
	head->link = new_node;
	prehead = head;
	head = new_node;
	size++;
}
void CircularList::Print() {
	if (head == nullptr) { cout << "리스트가 비어있습니다." << endl; return; }
	ListNode* iter = head->link;
	do
	{
		if (iter->link == nullptr) { cout << "리스트 NULL 오류" << endl; return; }
		cout.width(3); cout << iter->data;
		iter = iter->link;
	} while (iter != head->link);
	cout << endl;
}

void CircularList::Clear() {
	if (head == nullptr) { return; }

	ListNode* iter = head;
	ListNode* removed = nullptr;
	prehead->link = nullptr;
	while (iter != nullptr)
	{
		removed = iter;
		iter = iter->link;
		cout << removed->data << "삭제 ";
		delete removed;
	}
	Init();
}

int main()
{
	CircularList* list = new CircularList;
	list->InsertLast(20);
	list->InsertLast(30);
	list->InsertLast(40);
	list->InsertFirst(10);
	list->Print();
	delete list;

	return 0;
}