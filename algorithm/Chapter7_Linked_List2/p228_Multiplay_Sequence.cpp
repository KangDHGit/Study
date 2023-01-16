#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef char element[100];

struct ListNode {
	element data;
	ListNode* link;
	ListNode(element item, ListNode* link) {
		strcpy_s(data, item); this->link = link;
	}
};

class CircularList {
	ListNode* head;
	ListNode* prehead;
	int size;
	void Init() { size = 0; head = nullptr; }
public:
	CircularList() { Init(); }
	void InsertFirst(element item);
	void Print();
	void Clear();
	void TurnChange(int num);
	~CircularList() { Clear(); }
};
void CircularList::InsertFirst(element item) {
	ListNode* new_node = new ListNode(item, nullptr);
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	if (head == nullptr) { 
		head = new_node; 
		new_node->link = head;
		size++;
		return;
	}
	if (head->link == head) { prehead = new_node; }

	new_node->link = head->link;
	head->link = new_node;			//헤드포인터가 마지막을 가리키기 때문에 처음에 삽입하는 위치는 head의 link가 되는것
	size++;
}
void CircularList::Print() {
	if (head == nullptr) { cout << "리스트가 비어있습니다." << endl; return; }

	ListNode* iter = head->link;

	do
	{
		if (iter == nullptr) { cout << "리스트 NULL 오류" << endl; return; }
		cout << iter->data << " ";
		iter = iter->link;
	} while (iter != head->link);
	cout << endl;
}
void CircularList::Clear() {
	if (head == nullptr) { return; }

	ListNode* iter = head;
	ListNode* removed;
	prehead->link = nullptr;

	while (iter != nullptr)
	{
		removed = iter;
		iter = iter->link;
		cout << removed->data << " 삭제 ";
		delete removed;
	}
}

void CircularList::TurnChange(int count) {
	if (head == nullptr) { cout << "리스트가 비었습니다." << endl; return; }

	ListNode* iter = head->link;
	for (int i = 0; i < count; i++)
	{
		if (iter == nullptr) { cout << "노드 NULL 에러" << endl; return; }
		cout << "현재 차례 : " << iter->data << endl;
		iter = iter->link;
	}
}

int main()
{
	CircularList* list = new CircularList;
	list->InsertFirst(element{ "KIM" });
	list->InsertFirst(element{ "PARK" });
	list->InsertFirst(element{ "CHOI" });
	list->TurnChange(10);

	delete list;
	return 0;
}