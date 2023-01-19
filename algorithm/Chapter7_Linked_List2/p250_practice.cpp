#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//3. ���� ���Ḯ��Ʈ ���� �� Ư���� ���� Ž���ϰ� ��带 ��ȯ�ϴ� search �Լ� �ۼ�
//4. ���� ���Ḯ��Ʈ�� ����� �������� ������ ��ȯ�ϴ� �Լ� get_size()�ۼ�
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
	~CircularList() { Clear(); cout << "�����Ҵ� �޸� ���� �Ϸ�" << endl; }
};

void CircularList::Init() {
	head = nullptr; size = 0;
}

void CircularList::InsertFirst(element item) {
	NodeType* new_node = new NodeType{ item, nullptr };
	if (new_node == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }
	if (head == nullptr) { head = new_node; new_node->link = head; }
	else {
		new_node->link = head->link;
		head->link = new_node;
	}
	size++;
}
void CircularList::InsertLast(element item) {
	NodeType* new_node = new NodeType{ item, nullptr };
	if (new_node == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }
	if (head == nullptr) { head = new_node; new_node->link = head; }
	else {
		new_node->link = head->link;
		head->link = new_node;
		head = new_node;
	}
	size++;
}
void CircularList::Insert(element item, int index) {
	if (index < 0 || index > size) { cout << "�ǹٸ��� ���� �ε��� �Դϴ�." << endl; return; }

	NodeType* new_node = new NodeType{ item, nullptr };
	if (new_node == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }
	if (head == nullptr) { head = new_node; new_node->link = head; }

	NodeType* iter = head;
	for (int i = 0; i < index; i++)	{
		if (iter == nullptr) { cout << "��尡 NULL �Դϴ�." << endl; return; }
		iter = iter->link;
	}
	new_node->link = iter->link;
	iter->link = new_node;
	if (index == size) { new_node = head; }	//�������� �߰��ϴ°Ÿ� head�� �ٲ���
	size++;
}
NodeType* CircularList::Search(element item) {
	if (head == nullptr) { cout << "����Ʈ�� ����ֽ��ϴ�." << endl; return nullptr; }
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
	if (head == nullptr) { cout << "����Ʈ�� ����ֽ��ϴ�." << endl; return; }
	NodeType* iter = head->link;
	do
	{
		if (iter == nullptr) { cout << "��尡 NULL �Դϴ�." << endl; return; }
		cout.width(3); cout << iter->data << "->";
		iter = iter->link;
	} while (iter != head->link);
	cout << endl;
}
void CircularList::Clear() {
	if (head == nullptr) { cout << "����Ʈ�� �̹� ����ֽ��ϴ�." << endl; return; }
	NodeType* iter = head->link;
	NodeType* removed = nullptr;
	while (iter != head)
	{
		if (iter == nullptr) { cout << "��尡 NULL �Դϴ�." << endl; return; }
		removed = iter;
		iter = iter->link;
		cout << removed->data << "���� ";
		delete removed;
	}
	cout << head->data << "���� ";
	delete head;
	Init();
}
int CircularList::GetSize2() {
	if (head == nullptr) { cout << "����Ʈ�� �̹� ����ֽ��ϴ�." << endl; return 0; }
	NodeType* iter = head;
	int count = 0;
	do
	{
		if (iter == nullptr) { cout << "��尡 NULL �Դϴ�." << endl; return -9999; }
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
		if (search != nullptr) { cout << "ã�� �� : " << search->data << endl; }
		else { cout << "ã�� ���߽��ϴ�." << endl; }

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

//6. ���� ���Ḯ��Ʈ�� �������� ��ȸ�ϸ鼭 ����� ������ ���� ����ϴ� ���α׷� �ۼ�
//7. ���� ���Ḯ��Ʈ���� Ư���� ���� Ž���ϰ� ��带 ��ȯ�ϴ� search �Լ� �ۼ�
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
	~DoublyList() { Clear(); delete phead; cout << "���� �޸� ���� �Ϸ�" << endl; }
};
DoublyList::DoublyList() {
	phead = new DoublyNode;
	size = 0;
	if (phead == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }
	phead->data = -9999;
	phead->r_link = phead;
	phead->l_link = phead;
}
void DoublyList::Clear() {
	if (IsEmpty()) { cout << "����Ʈ�� �̹� ����ս��ϴ�." << endl; return; }
	DoublyNode* iter = phead->r_link;
	DoublyNode* removed = nullptr;
	while (iter != phead)
	{
		removed = iter;
		iter = iter->r_link;
		cout << removed->data << "���� ";
		delete removed;
	}
	cout << endl;
	size = 0;
}
void DoublyList::InsertFirst(element item) {
	if (phead == nullptr) { cout << "����Ʈ�� NULL �Դϴ�." << endl; return; }
	DoublyNode* new_node = new DoublyNode{ item, nullptr, nullptr };
	if (new_node == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }
	DoublyNode* l_node = phead;
	DoublyNode* r_node = phead->r_link;

	new_node->r_link = r_node;
	new_node->l_link = phead;
	r_node->l_link = new_node;
	phead->r_link = new_node;
	size++;
}
void DoublyList::Insert(element item, int index) {
	if (phead == nullptr) { cout << "����Ʈ�� NULL �Դϴ�." << endl; return; }
	if (index < 0 || index > size) { cout << "�ǹٸ��� ���� �ε��� �Դϴ�." << endl; }
	DoublyNode* new_node = new DoublyNode{ item, nullptr, nullptr };
	if (new_node == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }

	DoublyNode* l_node = phead;
	for (int i = 0; i < index; i++)
	{
		if (l_node == nullptr) { cout << "��尡 NULL �Դϴ�." << endl; return; }
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
	if (phead == nullptr) { cout << "����Ʈ�� NULL �Դϴ�." << endl; return; }
	DoublyNode* new_node = new DoublyNode{ item, nullptr, nullptr };
	if (new_node == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }

	DoublyNode* l_node = phead->l_link;
	DoublyNode* r_node = phead;
	
	l_node->r_link = new_node;
	r_node->l_link = new_node;
	new_node->l_link = l_node;
	new_node->r_link = r_node;
}
void DoublyList::DeleteFirst() {
	if (IsEmpty()) { cout << "����Ʈ�� �̹� ����ֽ��ϴ�." << endl; return; }

	DoublyNode* removed = phead->r_link;
	DoublyNode* l_node = phead;
	DoublyNode* r_node = removed->r_link;
	l_node->r_link = r_node;
	r_node->l_link = l_node;
	delete removed;
	size--;
}
void DoublyList::Delete(element item) {
	if (IsEmpty()) { cout << "����Ʈ�� �̹� ����ֽ��ϴ�." << endl; return; }
	int count = 0;
	DoublyNode* removed = phead->r_link;
	while (removed != phead)
	{
		if (removed == nullptr) { cout << "��尡 NULL �Դϴ�." << endl; return; }
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
		cout << item << "�� " << count << "�� ã�� �����߽��ϴ�." << endl;
	else
		cout << item << "�� �������� �ʽ��ϴ�." << endl;
}
void DoublyList::Print() {
	if (IsEmpty()) { cout << "����Ʈ�� ����ֽ��ϴ�." << endl; return; }
	DoublyNode* iter = phead->r_link;
	while (iter != phead)
	{
		if (iter == nullptr) { cout << "��尡 NULL �Դϴ�." << endl; return; }
		cout.width(3); cout << iter->data << "->";
		iter = iter->r_link;
	}
	cout << endl;
}
void DoublyList::ReversePrint() {
	if (IsEmpty()) { cout << "����Ʈ�� ����ֽ��ϴ�." << endl; return; }
	DoublyNode* iter = phead->l_link;
	while (iter != phead)
	{
		if (iter == nullptr) { cout << "��尡 NULL �Դϴ�." << endl; return; }
		cout.width(3); cout << iter->data << "->";
		iter = iter->l_link;
	}
	cout << endl;
}
DoublyNode* DoublyList::Search(element item) {
	if (IsEmpty()) { cout << "����Ʈ�� ����ֽ��ϴ�." << endl; return nullptr; }
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
		cout << "�Է��� �������� ������ �Է��ϼ��� : "; cin >> count;
		for (int i = 0; i < count; i++)
		{
			cout << "��� #" << i << "�� �����͸� �Է��Ͻÿ� : "; cin >> data;
			list->InsertLast(element{ data });
		}
		cout << "�����͸� ���� ��� :"; list->ReversePrint();

		delete list;
	}
};

class Question_7 {
public:
	void Run() {
		DoublyList* list = new DoublyList;
		int count = 0;
		int data;
		cout << "�Է��� �������� ������ �Է��ϼ��� : "; cin >> count;
		for (int i = 0; i < count; i++)
		{
			cout << "��� #" << i << "�� �����͸� �Է��Ͻÿ� : "; cin >> data;
			list->InsertLast(element{ data });
		}
		cout << "������ ��� :"; list->Print();
		
		DoublyNode* search = nullptr;

		while (true)
		{
			cout << "ã�� �����͸� �Է��ϼ��� : "; cin >> data;
			search = list->Search(element{ data });
			if (search == nullptr)
				cout << data << "�� ã�� ���߽��ϴ�." << endl;
			else {
				cout << data << "�� ã�ҽ��ϴ�." << endl;
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