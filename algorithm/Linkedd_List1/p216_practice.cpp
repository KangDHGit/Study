#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//9. 연결리스트 입력, 출력
//10.리스트의 노드 개수 계산
//11.리스트의 노드 데이터 총합
//12.리스트의 특정 데이터 총 개수
#pragma region question9
typedef int element;
struct NodeType {
	element data;
	NodeType* Link;
	~NodeType() { delete this; }
};
class ListType {
	NodeType* head;
	NodeType* tail;
	int count;
public:
	ListType() :count(0) { head = NULL; tail = NULL; }
	int GetSize() { return count; }		//10번-1	(리스트에서 개수 관리 방법)
	NodeType* GetHead() const { return head; }
	static int GetSize(ListType* list);	//10번-2	(리스트를 매개변수로 받아서 계산하는 방법)
	int GetSum();						//11번	(모든 노드 데이터의 합)
	int Count(element data);			//12번	(data의 값과 같은 노드의 개수)
	void Add(element data);
	void List_Print();
	~ListType() { delete this; }
};
//10번-2 구현
int ListType::GetSize(ListType* list) {
	NodeType* iter = list->GetHead();
	int count = 0;
	while (iter != NULL)
	{
		count++;
		iter = iter->Link;
	}
	return count;
}
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
void ListType::Add(element data) {
	NodeType* new_node = new NodeType{ data, NULL };
	if (new_node == NULL) { cout << "메모리 할당 에러" << endl; return; }
	
	if (head == NULL) { head = new_node, tail = new_node; }
	else {
		tail->Link = new_node;
		tail = new_node;
	}
	count++;
}
void ListType::List_Print() {
	NodeType* iter = head;
	while (iter != NULL)
	{
		cout << iter->data << "->";
		iter = iter->Link;
	}
	cout << "NULL" << endl;
}
int ListType::Count(element data) {
	int count = 0;
	NodeType* iter = head;
	while (iter != NULL)
	{
		if (iter->data == data)
			count++;
		iter = iter->Link;
	}
	return count;
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
			cin >> data; list->Add(data);
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
			cin >> data; list->Add(data);
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
			cin >> data; list->Add(data);
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
			cin >> data; list->Add(data);
		}
		cout << "탐색할 값을 입력하시오 : "; cin >> data;
		int count = list->Count(data);
		if (count == 0) { cout << data << "를 연결리스트에서 찾지 못했습니다." << endl; }
		else
			cout << data << "를 연결리스트에서 " << count << "개 찾았습니다." << endl;
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
	Question_12 q12;
	q12.run();
	return 0;
}