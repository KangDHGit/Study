#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//9. 연결리스트 입력, 출력
//10.리스트의 노드 개수 계산
//11.리스트의 노드 데이터 총합
//12.리스트의 특정 데이터 총 개수
//13.리스트의 특정 데이터 전부 삭제
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
	int GetSize() { return size; }		//10번-1	(리스트에서 개수 관리 방법)
	NodeType* GetHead() const { return head; }
	void Pop_front();					//13번 문제를 위해 추가(head삭제)
	static int GetSize(ListType* list);	//10번-2	(리스트를 매개변수로 받아서 계산하는 방법)
	int GetSum();						//11번	(모든 노드 데이터의 합)
	int Count(element data);			//12번	(data의 값과 같은 노드의 개수)
	void DeleteElements(element data);	//13번	(특정 데이터 값 전부 삭제)
	void Push_back(element data);
	void List_Print();
	void Clear();
	~ListType() { delete this; }
};
//10번-2 구현
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
	if (new_node == NULL) { cout << "메모리 할당 에러" << endl; return; }
	
	if (head == NULL) { head = new_node, tail = new_node; }
	else {
		tail->Link = new_node;
		tail = new_node;
	}
	size++;
}
//9번
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
//10번
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
//11번
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
	if (head == NULL) { cout << "리스트가 NULL 입니다." << endl; return; }
	NodeType* new_head = head->Link;
	delete head;
	head = new_head;
	size--;
}
//12번
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
		cout << "노드의 개수 : "; cin >> nodeCount;
		if (nodeCount < 1) { cout << "옳바르지 않은 개수 입니다." << endl; return; }

		ListType* list = new ListType;
		element data;
		for (int i = 0; i < nodeCount; i++)
		{
			cout << "노드 #" << i + 1 << " 데이터 : ";
			cin >> data; list->Push_back(data);
		}
		cout << "생성된 연결 리스트 : "; list->List_Print();
	}
};

class Question_10 {
public:
	void run() {
		int nodeCount;
		cout << "노드의 개수 : "; cin >> nodeCount;
		if (nodeCount < 1) { cout << "옳바르지 않은 개수 입니다." << endl; return; }

		ListType* list = new ListType;
		element data;
		for (int i = 0; i < nodeCount; i++)
		{
			cout << "노드 #" << i + 1 << " 데이터 : ";
			cin >> data; list->Push_back(data);
		}
		cout << "연결 리스트 노드의 개수(방법1) : " << list->GetSize() << endl;
		cout << "연결 리스트 노드의 개수(방법2) : " << ListType::GetSize(list) << endl;
	}
};

class Question_11 {
public:
	void run() {
		int nodeCount;
		cout << "노드의 개수 : "; cin >> nodeCount;
		if (nodeCount < 1) { cout << "옳바르지 않은 개수 입니다." << endl; return; }

		ListType* list = new ListType;
		element data;
		for (int i = 0; i < nodeCount; i++)
		{
			cout << "노드 #" << i + 1 << " 데이터 : ";
			cin >> data; list->Push_back(data);
		}
		cout << "연결 리스트 데이터의 합 : " << list->GetSum() << endl;
	}
};

class Question_12 {
public:
	void run() {
		int nodeCount;
		cout << "노드의 개수 : "; cin >> nodeCount;
		if (nodeCount < 1) { cout << "옳바르지 않은 개수 입니다." << endl; return; }

		ListType* list = new ListType;
		element data;
		for (int i = 0; i < nodeCount; i++)
		{
			cout << "노드 #" << i + 1 << " 데이터 : ";
			cin >> data; list->Push_back(data);
		}
		cout << "탐색할 값을 입력하시오 : "; cin >> data;
		int size = list->Count(data);
		if (size == 0) { cout << data << "를 연결리스트에서 찾지 못했습니다." << endl; }
		else
			cout << data << "를 연결리스트에서 " << size << "개 찾았습니다." << endl;
	}
};

class Question_13 {
public:
	void run() {
		int nodeCount;
		cout << "노드의 개수 : "; cin >> nodeCount;
		if (nodeCount < 1) { cout << "옳바르지 않은 개수 입니다." << endl; return; }

		ListType* list = new ListType;
		element data;
		for (int i = 0; i < nodeCount; i++)
		{
			cout << "노드 #" << i + 1 << " 데이터 : ";
			cin >> data; list->Push_back(data);
		}
		cout << "생성된 연결 리스트 : "; list->List_Print();
		cout << "삭제할 값을 입력하시오 : "; cin >> data;
		list->DeleteElements(data);
		cout << "삭제후 연결 리스트 : "; list->List_Print();
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