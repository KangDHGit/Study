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
	void Insert(element item, int index);
	NodeType* Search(element data);
	void Print();
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
	size++;
}
void CircularList::Insert(element item, int index) {
	if (index < 0 || index > size) { cout << "옳바르지 않은 인덱스 입니다." << endl; return; }

	NodeType* new_node = new NodeType{ item, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	if (head == nullptr) { head = new_node; new_node->link = head; }

	NodeType* iter = head;
	for (int i = 0; i < index; i++)	{
		if (iter == nullptr) { cout << "노드가 NULL 입니다." << endl; return; }
		iter = iter->link;
	}
	new_node->link = iter->link;
	iter->link = new_node;
	if (index == size) { new_node = head; }	//마지막에 추가하는거면 head를 바꿔줌
	size++;
}
NodeType* CircularList::Search(element item) {
	if (head == nullptr) { cout << "리스트가 비어있습니다." << endl; return nullptr; }
	NodeType* iter = head;
	do
	{
		if (iter->data == item)
			return iter;
		else
			iter = iter->link;
	} while (iter->link != head);
}
void CircularList::Print() {
	if (head == nullptr) { cout << "리스트가 비어있습니다." << endl; return; }
	NodeType* iter = head->link;
	do
	{
		if (iter == nullptr) { cout << "노드가 NULL 입니다." << endl; return; }
		cout.width(3); cout << iter->data << "->";
		iter = iter->link;
	} while (iter != head->link);
	cout << endl;
}
void CircularList::Clear() {
	if (head == nullptr) { cout << "리스트가 이미 비어있습니다." << endl; return; }
	NodeType* iter = head->link;
	NodeType* removed = nullptr;
	while (iter != head)
	{
		if (iter == nullptr) { cout << "노드가 NULL 입니다." << endl; return; }
		removed = iter;
		iter = iter->link;
		cout << removed->data << "삭제 ";
		delete removed;
	}
	cout << head->data << "삭제 ";
	delete head;
	Init();
}

class Question_3 {
public:
	void Run() {
		CircularList* list = new CircularList;
		list->InsertFirst(element{ 20 });
		list->InsertFirst(element{ 30 });
		list->InsertFirst(element{ 50 });
		list->InsertFirst(element{ 60 });
		list->Insert(element{ 40 }, 2);
		list->InsertLast(element{ 10 });
		list->Print();

		NodeType* search = list->Search(40);
		if (search != nullptr) { cout << "찾은 값 : " << search->data << endl; }
		else { cout << "찾지 못했습니다." << endl; }

		delete list;
	}
};
#pragma endregion


int main()
{
	Question_3 q3;
	q3.Run();
	return 0;
}