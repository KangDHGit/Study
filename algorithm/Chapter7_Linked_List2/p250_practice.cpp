#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//3. 원형 연결리스트 구현 및 특정한 값을 탐색하고 노드를 반환하는 search 함수 작성
//4. 원형 연결리스트에 저장된 데이터의 개수를 반환하는 함수 get_size()작성
typedef int element;
#pragma region question_3~4
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
	int GetSize() { return size; }
	int GetSize2();
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
	return nullptr;
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
int CircularList::GetSize2() {
	if (head == nullptr) { cout << "리스트가 이미 비어있습니다." << endl; return 0; }
	NodeType* iter = head;
	int count = 0;
	do
	{
		if (iter == nullptr) { cout << "노드가 NULL 입니다." << endl; return -9999; }
		count++;
		iter = iter->link;
	} while (iter != head);
	return count;
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

class Question_4 {
public:
	void Run() {
		CircularList* list = new CircularList;
		list->InsertFirst(element{ 20 });
		list->InsertFirst(element{ 30 });
		list->InsertFirst(element{ 50 });
		list->InsertFirst(element{ 60 });
		list->Insert(element{ 40 }, 2);
		list->InsertLast(element{ 10 });
		cout << "GetSize : " << list->GetSize() << " GetSize2 : " << list->GetSize2() << endl;
		list->Print();

		delete list;
	}
};
#pragma endregion

//6. 이중 연결리스트를 역순으로 순회하면서 저장된 데이터 값을 출력하는 프로그램 작성
//7. 이중 연결리스트에서 특정한 값을 탐색하고 노드를 반환하는 search 함수 작성
#pragma region question_6~7
struct DoublyNode {
	element data;
	DoublyNode* l_link;
	DoublyNode* r_link;
};

class DoublyList {
	DoublyNode* phead;
	int size;
public:
	DoublyList();
	bool IsEmpty() { return (phead == nullptr || phead->r_link == phead); }
	void Clear();
	void InsertFirst(element item);
	void Insert(element item, int index);
	void InsertLast(element item);
	void DeleteFirst();
	void Delete(element item);
	void Print();
	void ReversePrint();
	DoublyNode* Search(element item);
	~DoublyList() { Clear(); delete phead; cout << "동적 메모리 삭제 완료" << endl; }
};
DoublyList::DoublyList() {
	phead = new DoublyNode;
	size = 0;
	if (phead == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	phead->data = -9999;
	phead->r_link = phead;
	phead->l_link = phead;
}
void DoublyList::Clear() {
	if (IsEmpty()) { cout << "리스트가 이미 비어잇습니다." << endl; return; }
	DoublyNode* iter = phead->r_link;
	DoublyNode* removed = nullptr;
	while (iter != phead)
	{
		removed = iter;
		iter = iter->r_link;
		cout << removed->data << "삭제 ";
		delete removed;
	}
	cout << endl;
	size = 0;
}
void DoublyList::InsertFirst(element item) {
	if (phead == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
	DoublyNode* new_node = new DoublyNode{ item, nullptr, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	DoublyNode* l_node = phead;
	DoublyNode* r_node = phead->r_link;

	new_node->r_link = r_node;
	new_node->l_link = phead;
	r_node->l_link = new_node;
	phead->r_link = new_node;
	size++;
}
void DoublyList::Insert(element item, int index) {
	if (phead == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
	if (index < 0 || index > size) { cout << "옳바르지 않은 인덱스 입니다." << endl; }
	DoublyNode* new_node = new DoublyNode{ item, nullptr, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }

	DoublyNode* l_node = phead;
	for (int i = 0; i < index; i++)
	{
		if (l_node == nullptr) { cout << "노드가 NULL 입니다." << endl; return; }
		l_node = l_node->r_link;
	}
	DoublyNode* r_node = l_node->r_link;

	new_node->r_link = l_node->r_link;
	new_node->l_link = l_node;
	r_node->l_link = new_node;
	l_node->r_link = new_node;
	size++;
}
void DoublyList::InsertLast(element item) {
	if (phead == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
	DoublyNode* new_node = new DoublyNode{ item, nullptr, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }

	DoublyNode* l_node = phead->l_link;
	DoublyNode* r_node = phead;
	
	l_node->r_link = new_node;
	r_node->l_link = new_node;
	new_node->l_link = l_node;
	new_node->r_link = r_node;
}
void DoublyList::DeleteFirst() {
	if (IsEmpty()) { cout << "리스트가 이미 비어있습니다." << endl; return; }

	DoublyNode* removed = phead->r_link;
	DoublyNode* l_node = phead;
	DoublyNode* r_node = removed->r_link;
	l_node->r_link = r_node;
	r_node->l_link = l_node;
	delete removed;
	size--;
}
void DoublyList::Delete(element item) {
	if (IsEmpty()) { cout << "리스트가 이미 비어있습니다." << endl; return; }
	int count = 0;
	DoublyNode* removed = phead->r_link;
	while (removed != phead)
	{
		if (removed == nullptr) { cout << "노드가 NULL 입니다." << endl; return; }
		if (removed->data == item) {
			DoublyNode* l_node = removed->l_link;
			DoublyNode* r_node = removed->r_link;
			l_node->r_link = r_node;
			r_node->l_link = l_node;
			count++; size--;
			delete removed;
			removed = r_node;
		}
		else {
			removed = removed->r_link;
		}
	}
	if (count > 0)
		cout << item << "을 " << count << "개 찾아 삭제했습니다." << endl;
	else
		cout << item << "이 존재하지 않습니다." << endl;
}
void DoublyList::Print() {
	if (IsEmpty()) { cout << "리스트가 비어있습니다." << endl; return; }
	DoublyNode* iter = phead->r_link;
	while (iter != phead)
	{
		if (iter == nullptr) { cout << "노드가 NULL 입니다." << endl; return; }
		cout.width(3); cout << iter->data << "->";
		iter = iter->r_link;
	}
	cout << endl;
}
void DoublyList::ReversePrint() {
	if (IsEmpty()) { cout << "리스트가 비어있습니다." << endl; return; }
	DoublyNode* iter = phead->l_link;
	while (iter != phead)
	{
		if (iter == nullptr) { cout << "노드가 NULL 입니다." << endl; return; }
		cout.width(3); cout << iter->data << "->";
		iter = iter->l_link;
	}
	cout << endl;
}
DoublyNode* DoublyList::Search(element item) {
	if (IsEmpty()) { cout << "리스트가 비어있습니다." << endl; return nullptr; }
	DoublyNode* iter = phead->r_link;
	while (iter != phead)
	{
		if (iter->data == item)
			return iter;
		else
			iter = iter->r_link;
	}
	return nullptr;
}

class Question_6 {
public:
	void Run() {
		DoublyList* list = new DoublyList;
		int count = 0;
		int data;
		cout << "입력할 데이터의 개수를 입력하세요 : "; cin >> count;
		for (int i = 0; i < count; i++)
		{
			cout << "노드 #" << i << "의 데이터를 입력하시오 : "; cin >> data;
			list->InsertLast(element{ data });
		}
		cout << "데이터를 역순 출력 :"; list->ReversePrint();

		delete list;
	}
};

class Question_7 {
public:
	void Run() {
		DoublyList* list = new DoublyList;
		int count = 0;
		int data;
		cout << "입력할 데이터의 개수를 입력하세요 : "; cin >> count;
		for (int i = 0; i < count; i++)
		{
			cout << "노드 #" << i << "의 데이터를 입력하시오 : "; cin >> data;
			list->InsertLast(element{ data });
		}
		cout << "데이터 출력 :"; list->Print();
		
		DoublyNode* search = nullptr;

		while (true)
		{
			cout << "찾을 데이터를 입력하세요 : "; cin >> data;
			search = list->Search(element{ data });
			if (search == nullptr)
				cout << data << "를 찾지 못했습니다." << endl;
			else {
				cout << data << "를 찾았습니다." << endl;
				break;
			}
		}

		delete list;
	}
};
#pragma endregion


int main()
{
	/*Question_3 q3;
	q3.Run();*/
	/*Question_4 q4;
	q4.Run();*/
	/*Question_6 q6;
	q6.Run();*/
	Question_7 q7;
	q7.Run();
	return 0;
}