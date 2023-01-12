#include<iostream>
#include<tuple>
#include<random>

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
	ListType() :size(0) { head = nullptr; tail = nullptr; }
	int GetSize() { return size; }		//10번-1	(리스트에서 개수 관리 방법)
	NodeType* GetHead() const { return head; }
	NodeType* GetTail() const { return tail; }
	void Pop_front();					//13번 문제를 위해 추가(head삭제)
	void Pop_back();					//16번 문제를 위해 추가(tail삭제)
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
	while (iter != nullptr)
	{
		size++;
		iter = iter->Link;
	}
	return size;
}
void ListType::Push_back(element data) {
	NodeType* new_node = new NodeType{ data, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	
	if (head == nullptr) { head = new_node, tail = new_node; }
	else {
		tail->Link = new_node;
		tail = new_node;
	}
	size++;
}
//9번
void ListType::List_Print() {
	NodeType* iter = head;
	while (iter != nullptr)
	{
		cout << iter->data << "->";
		iter = iter->Link;
	}
	cout << "NULL" << endl;
}
void ListType::Clear() {
	NodeType* iter = head;
	NodeType* removed;
	while (iter != nullptr)
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
	while (iter != nullptr)
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
	while (iter != nullptr)
	{
		total += iter->data;
		iter = iter->Link;
	}
	return total;
}
void ListType::Pop_front() {
	if (head == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
	NodeType* new_head = head->Link;
	delete head;
	head = new_head;
	size--;
}
void ListType::Pop_back() {
	NodeType* iter = head;
	NodeType* new_tail = nullptr;
	if (iter == nullptr) { cout << "리스트가 NULL 입니다" << endl; return; }

	while (iter->Link != nullptr)
	{
		new_tail = iter;
		iter = iter->Link;
	}
	delete iter;
	tail = new_tail;
	tail->Link = nullptr;
}
//13번
void ListType::DeleteElements(element data) {
	NodeType* preIter = head;
	NodeType* removed = nullptr;

	while (preIter->data == data) {
		Pop_front(); preIter = head;
	}

	removed = preIter->Link;

	while (removed != nullptr)
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
	Data() : _name("Empty"), _age(-1), _height(-1) { Link = nullptr; };
	Data(const Data* copy);
	Data(string name, int age, float height) : _name(name), _age(age), _height(height) { Link = nullptr; };
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
	ListType_Person() :size(0) { head = nullptr; tail = nullptr; }
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
	if (new_head == nullptr) { cout << "메모리 할당 에러" << endl; return; }

	if (head == nullptr) { head = new_head; tail = new_head; }
	else {
		new_head->Link = head;
		head = new_head;
	}
	size++;
}
void ListType_Person::Push_back(Person data) {
	Person* new_tail = new Person(data);
	if (new_tail == nullptr) { cout << "메모리 할당 에러" << endl; return; }

	if (head == nullptr) { head = new_tail; tail = new_tail; }
	else {
		tail->Link = new_tail;
		tail = new_tail;
	}
	size++;
}
void ListType_Person::Insert(Person data, int index) {
	if (index < 0 || index > size) { cout << "잘못된 인덱스 번호 입니다." << endl; return; }
	
	Person* new_person = new Person(data);
	if (new_person == nullptr) { cout << "메모리 할당 에러	" << endl; return; }

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
	if (head == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
	else {
		Person* new_head = head->Link;
		delete head;
		head = new_head;
		size--;
	}
}
void ListType_Person::Pop_back() {
	if (head == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
	else {
		Person* new_tail = head;
		while (new_tail->Link != nullptr)
			new_tail = new_tail->Link;
		delete tail; tail = nullptr;
		tail = new_tail;
		size--;
	}
}
void ListType_Person::Clear() {
	Person* iter = head;
	Person* removed;
	while (iter != nullptr)
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
	while (iter != nullptr)
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
		
		person.SetInfo("park", 27, 1.2f);
		list->Push_front(person);

		person.SetInfo("kim", 34, 1.7f);
		list->Push_front(person);

		person.SetInfo("choi", 30, 1.3f);
		list->Push_back(person);

		person.SetInfo("lee", 48, 1.4f);
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
		if (list == nullptr || list->GetHead() == nullptr) { cout << "리스트가 NULL 입니다." << endl; return -1; }

		NodeType* iter = list->GetHead();
		int result = iter->data;
		iter = iter->Link;
		while (iter != nullptr)
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

//16. 홀수번째 있는 노드들을 삭제하는 프로그램
#pragma region question16
class Question_16 {
	ListType* list;
	void oddDelete(ListType* list) {
		NodeType* even = list->GetHead()->Link;
		NodeType* odd = nullptr;
		list->Pop_front();

		while (even->Link != nullptr)		//짝수노드가 tail이 아닐때 까지
		{
			odd = even->Link;			//홀수노드 주소를 넘겨줌
			if (odd->Link == nullptr) {	//홀수노드 다음이 NULL(즉 홀수노드가 tail이면)
				list->Pop_back(); break;
			}
			
			even->Link = odd->Link;		//짝수번째 끼리 연결
			delete odd;					//홀수 노드 삭제
			even = even->Link;			//다음짝수 노드로 이동
		}
	}
public:
	void run() {
		list = new ListType;
	
		//시드값을 얻기위한 random_device 생성
		std::random_device rd;
		//random_device를 통해 난수생성 엔진을 초기화 한다.
		std::mt19937 gen(rd());
		//정수(10~20)까지 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
		std::uniform_int_distribution<int> random(10, 20);

		int rand = random(gen);
		for (int i = 1; i < rand; i++)
			list->Push_back(element{ i });

		cout << "삭제전 : head = " << list->GetHead()->data << " tail = " << list->GetTail()->data << endl;
		list->List_Print();
		oddDelete(list);
		cout << "삭제후 : head = " << list->GetHead()->data << " tail = " << list->GetTail()->data << endl;
		list->List_Print();
	}
};
#pragma endregion

//17. alternate 함수 작성(두개의 리스트를 하나씩 교차로 합치기)
#pragma region question17
class Question_17 {
	ListType* listA;
	ListType* listB;
	ListType* Alternate(ListType* listA, ListType* listB) {
		if (listA == nullptr) { return listB; }
		if (listB == nullptr) { return listA; }

		ListType* listC = new ListType;
		NodeType* iterA = listA->GetHead();
		NodeType* iterB = listB->GetHead();
		while (iterA != nullptr && iterB != nullptr)
		{
			listC->Push_back(iterA->data);
			listC->Push_back(iterB->data);
			iterA = iterA->Link;
			iterB = iterB->Link;
		}

		while (iterA != nullptr)
		{
			listC->Push_back(iterA->data);
			iterA = iterA->Link;
		}

		while (iterB != nullptr)
		{
			listC->Push_back(iterB->data);
			iterB = iterB->Link;
		}
		return listC;
	}
public:
	void run() {
		listA = new ListType;
		listB = new ListType;


		//시드값을 얻기위한 random_device 생성
		std::random_device rd;
		//random_device를 통해 난수생성 엔진을 초기화 한다.
		std::mt19937 gen(rd());
		//정수(5~10)까지 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
		std::uniform_int_distribution<int> random(5, 10);

		for (int i = 0; i < random(gen); i++)
			listA->Push_back(element{ i });
		for (int i = 0; i < random(gen); i++)
			listB->Push_back(element{ i });
		cout << "listA : head : " << listA->GetHead()->data << " tail : " << listA->GetTail()->data  << " size : " << listA->GetSize() << endl;
		listA->List_Print();
		cout << "listB : head : " << listB->GetHead()->data << " tail : " << listB->GetTail()->data << " size : " << listB->GetSize() << endl;
		listB->List_Print();

		ListType* list = Alternate(listA, listB);
		cout << "list : head : " << list->GetHead()->data << " tail : " << list->GetTail()->data << " size : " << list->GetSize() << endl;
		list->List_Print();
	}
};
#pragma endregion

//18. merge 함수 작성(오름차순으로 정렬되 있는 두개의 리스트를 정렬을 유지고 합치기)
#pragma region question18
class Question_18 {
	ListType* listA;
	ListType* listB;
public:
	ListType* Merge(ListType* listA, ListType* listB) {
		if (listA == nullptr) { return listB; }
		if (listB == nullptr) { return listA; }

		ListType* list = new ListType;
		NodeType* iterA = listA->GetHead();
		NodeType* iterB = listB->GetHead();
		while (iterA != nullptr && iterB != nullptr)
		{
			if (iterA->data == iterB->data) {
				list->Push_back(iterA->data);
				list->Push_back(iterB->data);
				iterA = iterA->Link;
				iterB = iterB->Link;
			}
			else if (iterA->data < iterB->data) {
				list->Push_back(iterA->data);
				iterA = iterA->Link;
			}
			else {
				list->Push_back(iterB->data);
				iterB = iterB->Link;
			}
		}
		while (iterA != nullptr)
		{
			list->Push_back(iterA->data);
			iterA = iterA->Link;
		}
		while (iterB != nullptr)
		{
			list->Push_back(iterB->data);
			iterB = iterB->Link;
		}
		return list;
	}
	void run() {
		listA = new ListType;
		listB = new ListType;

		//시드값을 얻기위한 random_device 생성
		std::random_device rd;
		//random_device를 통해 난수생성 엔진을 초기화 한다.
		std::mt19937 gen(rd());
		//정수(5~10)까지 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
		std::uniform_int_distribution<int> randomCount(5, 10);
		std::uniform_int_distribution<int> randomPlus(1, 3);

		int num = 0;
		for (int i = 0; i < randomCount(gen); i++) {
			num += randomPlus(gen);
			listA->Push_back(num);
		}
		
		num = 0;
		for (int i = 0; i < randomCount(gen); i++) {
			num += randomPlus(gen);
			listB->Push_back(num);
		}

		cout << "listA : head : " << listA->GetHead()->data << " tail : " << listA->GetTail()->data << " size : " << listA->GetSize() << endl;
		listA->List_Print();
		cout << "listB : head : " << listB->GetHead()->data << " tail : " << listB->GetTail()->data << " size : " << listB->GetSize() << endl;
		listB->List_Print();

		ListType* list = Merge(listA, listB);
		cout << "list : head : " << list->GetHead()->data << " tail : " << list->GetTail()->data << " size : " << list->GetSize() << endl;
		list->List_Print();
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
	/*Question_15 q15;
	q15.run();*/
	/*Question_16 q16;
	q16.run();*/
	/*Question_17 q17;
	q17.run();*/
	Question_18 q18;
	q18.run();

	return 0;
}