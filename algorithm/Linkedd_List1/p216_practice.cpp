#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//9. ���Ḯ��Ʈ �Է�, ���
//10.����Ʈ�� ��� ���� ���
//11.����Ʈ�� ��� ������ ����
//12.����Ʈ�� Ư�� ������ �� ����
//13.����Ʈ�� Ư�� ������ ���� ����
#pragma region question9 ~ 13
typedef int element;
struct NodeType {
	element data;
	NodeType* Link;
};
class ListType {
	NodeType* head;
	NodeType* tail;
	int size;
public:
	ListType() :size(0) { head = NULL; tail = NULL; }
	int GetSize() { return size; }		//10��-1	(����Ʈ���� ���� ���� ���)
	NodeType* GetHead() const { return head; }
	void Pop_front();					//13�� ������ ���� �߰�(head����)
	static int GetSize(ListType* list);	//10��-2	(����Ʈ�� �Ű������� �޾Ƽ� ����ϴ� ���)
	int GetSum();						//11��	(��� ��� �������� ��)
	int Count(element data);			//12��	(data�� ���� ���� ����� ����)
	void DeleteElements(element data);	//13��	(Ư�� ������ �� ���� ����)
	void Push_back(element data);
	void List_Print();
	void Clear();
	~ListType() { delete this; }
};
//10��-2 ����
int ListType::GetSize(ListType* list) {
	NodeType* iter = list->GetHead();
	int size = 0;
	while (iter != NULL)
	{
		size++;
		iter = iter->Link;
	}
	return size;
}
void ListType::Push_back(element data) {
	NodeType* new_node = new NodeType{ data, NULL };
	if (new_node == NULL) { cout << "�޸� �Ҵ� ����" << endl; return; }
	
	if (head == NULL) { head = new_node, tail = new_node; }
	else {
		tail->Link = new_node;
		tail = new_node;
	}
	size++;
}
//9��
void ListType::List_Print() {
	NodeType* iter = head;
	while (iter != NULL)
	{
		cout << iter->data << "->";
		iter = iter->Link;
	}
	cout << "NULL" << endl;
}
void ListType::Clear() {
	NodeType* iter = head;
	NodeType* removed;
	while (iter != NULL)
	{
		removed = iter;
		iter = iter->Link;
		delete removed;
	}
	size = 0;
}
//10��
int ListType::Count(element data) {
	int size = 0;
	NodeType* iter = head;
	while (iter != NULL)
	{
		if (iter->data == data)
			size++;
		iter = iter->Link;
	}
	return size;
}
//11��
int ListType::GetSum() {
	int total = 0;
	NodeType* iter = head;
	while (iter != NULL)
	{
		total += iter->data;
		iter = iter->Link;
	}
	return total;
}
void ListType::Pop_front() {
	if (head == NULL) { cout << "����Ʈ�� NULL �Դϴ�." << endl; return; }
	NodeType* new_head = head->Link;
	delete head;
	head = new_head;
	size--;
}
//12��
void ListType::DeleteElements(element data) {
	NodeType* preIter = head;
	NodeType* removed = NULL;

	while (preIter->data == data)
		Pop_front(); preIter = head;

	removed = preIter->Link;

	while (removed != NULL)
	{
		if (removed->data == data) {
			preIter->Link = removed->Link;
			delete removed;
			removed = preIter->Link; size--;
		}
		else {
			preIter = removed;
			removed = removed->Link;
		}
	}
}

class Question_9 {
public:
	void run() {
		int nodeCount;
		cout << "����� ���� : "; cin >> nodeCount;
		if (nodeCount < 1) { cout << "�ǹٸ��� ���� ���� �Դϴ�." << endl; return; }

		ListType* list = new ListType;
		element data;
		for (int i = 0; i < nodeCount; i++)
		{
			cout << "��� #" << i + 1 << " ������ : ";
			cin >> data; list->Push_back(data);
		}
		cout << "������ ���� ����Ʈ : "; list->List_Print();
	}
};

class Question_10 {
public:
	void run() {
		int nodeCount;
		cout << "����� ���� : "; cin >> nodeCount;
		if (nodeCount < 1) { cout << "�ǹٸ��� ���� ���� �Դϴ�." << endl; return; }

		ListType* list = new ListType;
		element data;
		for (int i = 0; i < nodeCount; i++)
		{
			cout << "��� #" << i + 1 << " ������ : ";
			cin >> data; list->Push_back(data);
		}
		cout << "���� ����Ʈ ����� ����(���1) : " << list->GetSize() << endl;
		cout << "���� ����Ʈ ����� ����(���2) : " << ListType::GetSize(list) << endl;
	}
};

class Question_11 {
public:
	void run() {
		int nodeCount;
		cout << "����� ���� : "; cin >> nodeCount;
		if (nodeCount < 1) { cout << "�ǹٸ��� ���� ���� �Դϴ�." << endl; return; }

		ListType* list = new ListType;
		element data;
		for (int i = 0; i < nodeCount; i++)
		{
			cout << "��� #" << i + 1 << " ������ : ";
			cin >> data; list->Push_back(data);
		}
		cout << "���� ����Ʈ �������� �� : " << list->GetSum() << endl;
	}
};

class Question_12 {
public:
	void run() {
		int nodeCount;
		cout << "����� ���� : "; cin >> nodeCount;
		if (nodeCount < 1) { cout << "�ǹٸ��� ���� ���� �Դϴ�." << endl; return; }

		ListType* list = new ListType;
		element data;
		for (int i = 0; i < nodeCount; i++)
		{
			cout << "��� #" << i + 1 << " ������ : ";
			cin >> data; list->Push_back(data);
		}
		cout << "Ž���� ���� �Է��Ͻÿ� : "; cin >> data;
		int size = list->Count(data);
		if (size == 0) { cout << data << "�� ���Ḯ��Ʈ���� ã�� ���߽��ϴ�." << endl; }
		else
			cout << data << "�� ���Ḯ��Ʈ���� " << size << "�� ã�ҽ��ϴ�." << endl;
	}
};

class Question_13 {
public:
	void run() {
		int nodeCount;
		cout << "����� ���� : "; cin >> nodeCount;
		if (nodeCount < 1) { cout << "�ǹٸ��� ���� ���� �Դϴ�." << endl; return; }

		ListType* list = new ListType;
		element data;
		for (int i = 0; i < nodeCount; i++)
		{
			cout << "��� #" << i + 1 << " ������ : ";
			cin >> data; list->Push_back(data);
		}
		cout << "������ ���� ����Ʈ : "; list->List_Print();
		cout << "������ ���� �Է��Ͻÿ� : "; cin >> data;
		list->DeleteElements(data);
		cout << "������ ���� ����Ʈ : "; list->List_Print();
	}
};
#pragma endregion


int main()
{
	/*Question_9 q9;
	q9.run();*/
	/*Question_10 q10;
	q10.run();*/
	/*Question_11 q11;
	q11.run();*/
	/*Question_12 q12;
	q12.run();*/
	Question_13 q13;
	q13.run();
	return 0;
}