#include<iostream>
#include<tuple>
#include<random>;

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::tuple;

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
	~ListType() { Clear(); delete this; }
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
//12번
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
//13번
void ListType::DeleteElements(element data) {
	NodeType* preIter = head;
	NodeType* removed = NULL;

	while (preIter->data == data) {
		Pop_front(); preIter = head;
	}

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

//14. name, age, height를 저장할 수 있는 단순연결 리스트
#pragma region question14
typedef class Data
{
	string _name;
	int _age;
	float _height;
public:
	Data* Link;
	Data() : _name("Empty"), _age(-1), _height(-1) { Link = NULL; };
	Data(const Data* copy);
	Data(string name, int age, float height) : _name(name), _age(age), _height(height) { Link = NULL; };
	void SetName(string name) { _name = name; }
	void SetAge(int age) { _age = age; }
	void SetHeigh(float height) { _height = height; }
	void SetInfo(string name, int age = -1, float heigh = -1);
	void SetInfo(tuple<string, int, float> info);

	string GetName() const { return _name; }
	int GetAge() const { return _age; }
	float GetHeigh() const { return _height; }
	tuple<string, int, float> GetInfo();
	void Print();
}Person;

Data::Data(const Data* copy) {
	_name = copy->GetName(); _age = copy->GetAge(); _height = copy->GetHeigh();
}
void Data::SetInfo(tuple<string, int, float> info) {

}
void Data::SetInfo(string name, int age, float heigh) {
	_name = name;
	if (age != -1) { _age = age; }
	if (heigh != -1) { _height = heigh; }
}
tuple<string, int, float> Data::GetInfo() {
	tuple<string, int, float> info = std::make_tuple(_name, _age, _height);
	return info;
}
void Data::Print() {
	cout << "이름 : "; cout.width(5); cout << _name << " 나이 : " << _age << " 키 :	" << _height << endl;
}

class ListType_Person {
	Person* head;
	Person* tail;
	int size;
public:
	ListType_Person() :size(0) { head = NULL; tail = NULL; }
	void Push_front(Person data);
	void Push_back(Person data);
	void Insert(Person data, int index);
	void Pop_front();
	void Pop_back();
	int GetSize() const { return size; }
	void Clear();
	~ListType_Person() { Clear(); }
	void Print();
};
void ListType_Person::Push_front(Person data) {
	Person* new_head = new Person(data);
	if (new_head == NULL) { cout << "메모리 할당 에러" << endl; return; }

	if (head == NULL) { head = new_head; tail = new_head; }
	else {
		new_head->Link = head;
		head = new_head;
	}
	size++;
}
void ListType_Person::Push_back(Person data) {
	Person* new_tail = new Person(data);
	if (new_tail == NULL) { cout << "메모리 할당 에러" << endl; return; }

	if (head == NULL) { head = new_tail; tail = new_tail; }
	else {
		tail->Link = new_tail;
		tail = new_tail;
	}
	size++;
}
void ListType_Person::Insert(Person data, int index) {
	if (index < 0 || index > size) { cout << "잘못된 인덱스 번호 입니다." << endl; return; }
	
	Person* new_person = new Person(data);
	if (new_person == NULL) { cout << "메모리 할당 에러	" << endl; return; }

	if (index == 0) { Push_front(data); }
	else if (index == size) { Push_back(data); }
	else {
		Person* pre = head;
		for (int i = 1; i < index; i++)
			pre = pre->Link;
		new_person->Link = pre->Link;
		pre->Link = new_person;
	}
	size++;
}
void ListType_Person::Pop_front() {
	if (head == NULL) { cout << "리스트가 NULL 입니다." << endl; return; }
	else {
		Person* new_head = head->Link;
		delete head;
		head = new_head;
		size--;
	}
}
void ListType_Person::Pop_back() {
	if (head == NULL) { cout << "리스트가 NULL 입니다." << endl; return; }
	else {
		Person* new_tail = head;
		while (new_tail->Link != NULL)
			new_tail = new_tail->Link;
		delete tail;
		tail = new_tail;
		size--;
	}
}
void ListType_Person::Clear() {
	Person* iter = head;
	Person* removed;
	while (iter !=NULL)
	{
		removed = iter;
		iter = iter->Link;
		delete removed;
	}
	size = 0;
}
void ListType_Person::Print() {
	Person* iter = head;
	int index = 0;
	cout << "==========리스트 출력==========" << endl;
	while (iter != NULL)
	{
		cout << index << "번 "; iter->Print();
		index++;
		iter = iter->Link;
	}
	cout << "==============================" << endl;
}
class Question_14 {
public:
	void run() {
		ListType_Person* list = new ListType_Person;

		Person person;
		//person.SetInfo("lee", 48, 1.4);
		//list->Push_front(person);
		
		person.SetInfo("park", 27, 1.2);
		list->Push_front(person);

		person.SetInfo("kim", 34, 1.7);
		list->Push_front(person);

		person.SetInfo("choi", 30, 1.3);
		list->Push_back(person);

		person.SetInfo("lee", 48, 1.4);
		list->Insert(person, 2);

		list->Print();
	}
};
#pragma endregion

//15. 정열되지 않은 정수 리스트의 최대 값과 최소값을 찾는 프로그램
#pragma region question15
class Question_15 {
	ListType* list;
	bool max;
	bool min;

	int Find(ListType* list, bool compare) {
		if (list == NULL || list->GetHead() == NULL) { cout << "리스트가 NULL 입니다." << endl; return -1; }

		NodeType* iter = list->GetHead();
		int result = iter->data;
		iter = iter->Link;
		while (iter != NULL)
		{
			if (compare) {
				if (iter->data > result)
					result = iter->data;
			}
			else {
				if (iter->data < result)
					result = iter->data;
			}
			iter = iter->Link;
		}
		return result;
	}
public:
	Question_15() :max(true), min(false) {}
	void run() {
		list = new ListType;
		//시드값을 얻기위한 random_device 생성
		std::random_device rd;
		//random_device를 통해 난수생성 엔진을 초기화 한다.
		std::mt19937 gen(rd());
		//정수(0~99)까지 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
		std::uniform_int_distribution<int> random(0, 99);

		element data;
		for (int i = 0; i < 10; i++)
		{
			data = random(gen);
			list->Push_back(data);
		}
		list->List_Print();

		int maxNum = Find(list, max);
		int minNum = Find(list, min);
		cout << "최대값 : " << maxNum << " 최소값 : " << minNum << endl;
	}
};
#pragma endregion


class Test {
public:
	int a;
	int b;
};

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
	/*Question_13 q13;
	q13.run();*/
	/*Question_14 q14;
	q14.run();*/
	Question_15 q15;
	q15.run();

	return 0;
}