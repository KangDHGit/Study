#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int element;

struct ListNode {
	element data;
	ListNode* l_link;
	ListNode* r_link;
};

class Doubly_list {
	ListNode* phead;
	int size;
	void Init();
public:
	bool IsEmpty() { return (phead == nullptr || phead->r_link == phead); }
	Doubly_list() { Init(); }
	void Clear();
	void InsertFirst(element item);
	void Insert(element item, int index);
	void DeleteFirst();
	void Delete(element item);
	void Print();
	~Doubly_list() { Clear(); delete phead; cout << "동적 메모리 삭제 완료" << endl; }
};

void Doubly_list::Init() {
	phead = new ListNode;
	if (phead == nullptr) { cout << "메모리 할당 에러" << endl; }
	phead->l_link = phead;
	phead->r_link = phead;
	phead->data = -9999;
	size = 0;
}
void Doubly_list::Clear() {
	if (IsEmpty()) { cout << "리스트가 이미 비어있습니다." << endl; return; }
	phead->l_link->r_link = nullptr;
	ListNode* iter = phead;
	ListNode* removed = nullptr;
	while (iter != nullptr)
	{
		removed = iter;
		iter = iter->r_link;
		cout << removed->data << "삭제 ";
		delete removed;
	}
	cout << endl;
	Init();
}

void Doubly_list::InsertFirst(element item) {
	ListNode* new_node = new ListNode{ item, nullptr, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }

	if (phead == nullptr) { Init(); }
	ListNode* l_node = phead;
	ListNode* r_node = phead->r_link;

	new_node->l_link = phead;
	new_node->r_link = r_node;
	r_node->l_link = new_node;
	l_node->r_link = new_node;
	size++;
}

void Doubly_list::Insert(element item, int index) {
	if (phead == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
	if (index < 0 || index > size) { cout << "옳바르지 않은 인덱스 입니다." << endl; return; }
	ListNode* l_node = phead;
	
	for (int i = 0; i < index; i++) {
		l_node = l_node->r_link;
		if (l_node == nullptr) { cout << i << "번째 노드가 NULL입니다." << endl; return; }
	}
	ListNode* new_node = new ListNode{ item, nullptr, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	ListNode* r_node = l_node->r_link;

	new_node->l_link = l_node;
	new_node->r_link = r_node;
	r_node->l_link = new_node;
	l_node->r_link = new_node;
	size++;
}

void Doubly_list::DeleteFirst() {
	if (IsEmpty()) { cout << "리스트가 이미 비어있습니다." << endl; return; }
	ListNode* removed = phead->r_link;
	ListNode* l_node = phead;
	ListNode* r_node = removed->r_link;
	l_node->r_link = r_node;
	r_node->l_link = l_node;
	delete removed;
	size--;
}

void Doubly_list::Delete(element item) {
	if (phead == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
	ListNode* removed = phead->r_link;
	int count = 0;
	while (removed != phead)
	{
		if (removed == nullptr) { cout << "노드가 NULL 입니다." << endl; return; }
		if (removed->data == item) {
			ListNode* l_node = removed->l_link;
			ListNode* r_node = removed->r_link;
			l_node->r_link = r_node;
			r_node->l_link = l_node;
			delete removed;
			removed = r_node;
			size--;
			count++;
		}
		else {
			removed = removed->r_link;
		}
	}
	if (count > 0)
		cout << "[" << item << "] " << count << "개를 찾아 삭제했습니다." << endl;
	else
		cout << "[" << item << "] " << "이 존재하지 않습니다." << endl;
}

void Doubly_list::Print() {
	if (IsEmpty()) { cout << "리스트가 비어있습니다." << endl; return; }
	ListNode* iter = phead->r_link;
	while (iter != phead)
	{
		cout << iter->data << " ";
		iter = iter->r_link;
	}
	cout << endl;
}
int main()
{
	Doubly_list* list = new Doubly_list;
	for (int i = 0; i < 10; i++)
		list->InsertFirst(element{ i });
	list->Print();

	list->Insert(element{ 20 },0);
	list->Insert(element{ 20 },3);
	list->Insert(element{ 20 },5);

	list->Print();

	list->Delete(element{ 20 });

	list->Print();

	for (int i = 0; i < 5; i++)
		list->DeleteFirst();

	list->Print();

	delete list;
	return 0;
}