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
	~ListType() { Clear();}
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
	head = nullptr;
	tail = nullptr;
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
	if (head == nullptr) { cout << "리스트가 NULL 입니다" << endl; return; }
	NodeType* iter = head;
	NodeType* new_tail = nullptr;

	while (iter->Link != nullptr)
	{
		new_tail = iter;
		iter = iter->Link;
	}
	delete iter;
	tail = new_tail;
	if(tail != nullptr)
		tail->Link = nullptr;
	size--;
}
//13번
void ListType::DeleteElements(element data) {
	if (head == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
	while (head->data == data)
		Pop_front();

	NodeType* preIter = head;
	NodeType* removed = preIter->Link;

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
		delete list;
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
		delete list;
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
		delete list;
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
		delete list;
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
		delete list;
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
		delete list;
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
		delete list;
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
		delete list;
	}
};
#pragma endregion

//17. alternate 함수 작성(두개의 리스트를 하나씩 교차로 합치기)
#pragma region question17
class Question_17 {
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
		ListType* listA = new ListType;
		ListType* listB = new ListType;

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

		delete listA;
		delete listB;
		delete list;
	}
};
#pragma endregion

//18. merge 함수 작성(오름차순으로 정렬되 있는 두개의 리스트를 정렬을 유지고 합치기)
#pragma region question18
class Question_18 {
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
		ListType* listA = new ListType;
		ListType* listB = new ListType;

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

		delete listA;
		delete listB;
		delete list;
	}
};
#pragma endregion

//19. split 함수 작성(리스트 하나를 두개로 분리, 홀수번째 리스트, 짝수번째 리스트)
#pragma region question19
class Question_19 {
	void Split(ListType* list, ListType* outlistA, ListType* outlistB) {
		if (list == nullptr) { cout << "분리할 리스트가 NULL 입니다." << endl; return; }
		if (outlistA == nullptr) { outlistA = new ListType; }
		if (outlistB == nullptr) { outlistB = new ListType; }

		NodeType* iter = list->GetHead();
		bool isOdd = true;
		while (iter != nullptr)
		{
			isOdd ? outlistA->Push_back(iter->data) : outlistB->Push_back(iter->data);
			isOdd = !isOdd;
			iter = iter->Link;
		}
	}
public:
	void Run() {
		ListType* list = new ListType;
		ListType* outlistA = new ListType;
		ListType* outlistB = new ListType;

		//시드값을 얻기위한 random_device 생성
		std::random_device rd;
		//random_device를 통해 난수생성 엔진을 초기화 한다.
		std::mt19937 gen(rd());
		//정수(10~20)까지 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
		std::uniform_int_distribution<int> random(10, 20);
		for (int i = 1; i < random(gen); i++)
			list->Push_back(i);

		Split(list, outlistA, outlistB);

		cout << "list : head : " << list->GetHead()->data << " tail : " << list->GetTail()->data << " size : " << list->GetSize() << endl;
		list->List_Print();
		cout << "outlistA : head : " << outlistA->GetHead()->data << " tail : " << outlistA->GetTail()->data << " size : " << outlistA->GetSize() << endl;
		outlistA->List_Print();
		cout << "outlistB : head : " << outlistB->GetHead()->data << " tail : " << outlistB->GetTail()->data << " size : " << outlistB->GetSize() << endl;
		outlistB->List_Print();

		delete outlistA;
		delete outlistB;
		delete list;
	}
};
#pragma endregion

//20. 다항식을 연결리스트로 나타내고 두 다항식의 합을 구하기
//21. 어떤 실수 x에 대해 다항식의 값을 계산하는 함수 작성
#pragma region question20~21
struct Term
{
	int coef;	//계수
	int expon;	//지수(거듭제곱)
};
struct NodeTerm {
	Term term;
	NodeTerm* link;
	void Print() {
		char oper;
		if (term.coef >= 0) { oper = '+'; }
		else { oper = '-'; }
		cout.width(2); cout << oper;
		cout.width(2); cout << abs(term.coef) << "x^" << term.expon;
	}
};

class Polynomail {
	NodeTerm* head;
	NodeTerm* tail;
	int size;
public:
	void init() { size = 0; head = nullptr; tail = nullptr; }
	Polynomail() { init(); }
	NodeTerm* Gethead() const { return head; }
	void Clear();
	void Pushback(Term term);
	void Print();
	~Polynomail() { Clear(); delete this; }
};
void Polynomail::Clear() {
	NodeTerm* iter = head;
	NodeTerm* removed = nullptr;
	while (iter != nullptr)
	{
		removed = iter;
		iter = iter->link;
		delete removed;
	}
	init();
}
void Polynomail::Pushback(Term term) {
	NodeTerm* new_tail = new NodeTerm{ term, nullptr };
	if (new_tail == nullptr) { cout << "메모리 할당 에러" << endl; return; }

	if (head == nullptr) { head = new_tail; tail = new_tail; }
	else {
		tail->link = new_tail;
		tail = new_tail;
	}
	size++;
}
void Polynomail::Print() {
	NodeTerm* iter = head;
	while (iter != nullptr)
	{
		iter->Print();
		iter = iter->link;
	}
	cout << endl;
}

class Calc {
	const static short ExponCompare(Term a, Term b) {
		if (a.expon > b.expon)
			return 1;
		else if (a.expon == b.expon)
			return 0;
		else
			return -1;
	}
public:
	static Polynomail* Sum(Polynomail* polyA, Polynomail* polyB) {
		if (polyA == nullptr) { return polyB; }
		if (polyB == nullptr) { return polyA; }

		Polynomail* poly = new Polynomail;
		if (poly == nullptr) { cout << "메모리 할당 에러" << endl; return nullptr; }

		NodeTerm* iterA = polyA->Gethead();
		NodeTerm* iterB = polyB->Gethead();

		while (iterA != nullptr && iterB != nullptr)
		{
			const short compare = ExponCompare(iterA->term, iterB->term);
			int coef;
			int expon;
			switch (compare)
			{
			case 1:
				coef = iterA->term.coef;
				expon = iterA->term.expon;
				iterA = iterA->link;
				poly->Pushback(Term{ coef, expon });
				break;
			case 0:
				coef = iterA->term.coef + iterB->term.coef;
				expon = iterA->term.expon;
				iterA = iterA->link;
				iterB = iterB->link;
				if (coef == 0) { continue; }
				poly->Pushback(Term{ coef, expon });
				break;
			case -1:
				coef = iterB->term.coef;
				expon = iterB->term.expon;
				iterB = iterB->link;
				poly->Pushback(Term{ coef, expon });
				break;
			}
		}

		while (iterA != nullptr)
		{
			int coef;
			int expon;
			coef = iterA->term.coef;
			expon = iterA->term.expon;
			iterA = iterA->link;
			poly->Pushback(Term{ coef, expon });
		}

		while (iterB != nullptr)
		{
			int coef;
			int expon;
			coef = iterB->term.coef;
			expon = iterB->term.expon;
			iterB = iterB->link;
			poly->Pushback(Term{ coef, expon });
		}
		return poly;
	}
	static int PolyEval(Polynomail* poly, int x) {
		int total = 0;
		NodeTerm* iter = poly->Gethead();
		while (iter != nullptr)
		{
			total += ((iter->term.coef) * (Power(x, iter->term.expon)));
			iter = iter->link;
		}
		return total;
	}
	static int Power(int num, int expon) {
		if (num == 0) return 0;
		if (expon == 1) return num;
		if (expon == 0) return 1;

		return expon % 2 == 0 ? Power(num * num, expon / 2) : num * Power(num * num, (expon - 1) / 2);
	}
};

class Question_20 {
public:
	void Run() {
		Polynomail* polys[2] = { new Polynomail, new Polynomail };
		Polynomail* sum_poly = new Polynomail;
		if (polys[0] == nullptr || polys[1] == nullptr || sum_poly == nullptr) { cout << "메모리 할당 에러" << endl; return; }

		//시드값을 얻기위한 random_device 생성
		std::random_device rd;
		//random_device를 통해 난수생성 엔진을 초기화 한다.
		std::mt19937 gen(rd());
		//정수를 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
		std::uniform_int_distribution<int> coefRandom(-9, 9);
		std::uniform_int_distribution<int> max_exponRandom(6, 8);
		std::uniform_int_distribution<int> sub_exponRandom(1, 3);

		for (int i = 0; i < 2; i++)
		{
			int max_expon = max_exponRandom(gen);
			while (max_expon >= 0)
			{
				int coef = coefRandom(gen);
				while (coef == 0)
					coef = coefRandom(gen);

				int expon = max_expon;
				max_expon -= sub_exponRandom(gen);
				polys[i]->Pushback(Term{ coef, expon });
			}
		}

		sum_poly = Calc::Sum(polys[0], polys[1]);
		cout << "polys[0] :"; polys[0]->Print();
		cout << "polys[1] :"; polys[1]->Print();
		cout << "sum_poly :"; sum_poly->Print();
	}
};

class Question_21 {
public:
	void Run() {
		Polynomail* poly = new Polynomail;

		//시드값을 얻기위한 random_device 생성
		std::random_device rd;
		//random_device를 통해 난수생성 엔진을 초기화 한다.
		std::mt19937 gen(rd());
		//정수를 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
		std::uniform_int_distribution<int> coefRandom(-9, 9);
		std::uniform_int_distribution<int> max_exponRandom(6, 8);
		std::uniform_int_distribution<int> sub_exponRandom(1, 3);
		std::uniform_int_distribution<int> numberRandom(2, 4);

		int max_expon = max_exponRandom(gen);
		while (max_expon>= 0)
		{
			int coef = coefRandom(gen);
			int expon = max_expon;
			while (coef == 0)
				coef = coefRandom(gen);
			poly->Pushback(Term{ coef, expon });
			max_expon -= sub_exponRandom(gen);
		}

		cout << "poly :"; poly->Print();
		int number = numberRandom(gen);
		cout << "PolyEval : x = " << number << " total = " << Calc::PolyEval(poly, number) << endl;
	}
};
#pragma endregion

//22. 배열로 SortedList 구현하기
#pragma region question22
class Arr_SortedList {
public:
	const static int MAX_SIZE = 10;
private:
	element data[MAX_SIZE];
	int top;
public:
	Arr_SortedList() :top(-1){}
	bool Is_empty() { return top == -1; }
	bool Is_full() { return top == MAX_SIZE - 1; }
	int GetLength() { return top + 1; }
	void Add(element item);
	void Delete(element item);
	void Clear() { top = -1; }
	bool Contain(element item);
	void Print();
	~Arr_SortedList() { Clear(); }
};
void Arr_SortedList::Add(element item) {
	if (Is_full()) { cout << "리스트 포화 에러" << endl; return; }
	if (Is_empty()) { top++; data[top] = item; return; }

	
	for (int i = 0; i < top + 1; i++)
	{
		if (item < data[i]) {	// 0 1 3 4 에 2삽입
			for (int j = top + 1; j > i; j--)	// 0 1 _ 3 4
			{
				data[j] = data[j - 1];
			}
			data[i] = item;
			top++;
			return;
		}
	}
	top++;
	data[top] = item;
}
void Arr_SortedList::Delete(element item) {
	int deleteCount = 0;
	for (int i = 0; i < top + 1; i++)
	{
		if (data[i] == item) {
			for (int j = i; j < top; j++)
			{
				data[j] = data[j + 1];
			}
			i--;	//한칸씩 당겨지기 때문에 제자리 한번더 검사
			deleteCount++;
			top--;
		}
	}
	if (deleteCount > 0) { cout << "["<< item << "] " << deleteCount << "개를 찾아서 삭제 했습니다." << endl; }
	else { cout << "[" << item << "] 삭제 실패 : 존재하지 않는 데이터 입니다." << endl; }
}
bool Arr_SortedList::Contain(element item) {
	for (int i = 0; i <= top; i++)
	{
		if (data[i] == item)
			return true;
	}
	return false;
}
void Arr_SortedList::Print() {
	for (int i = 0; i < top + 1; i++)
	{
		cout.width(3); cout << data[i] << ",";
	}
	cout << endl;
}
class Question_22 {
public:
	void Run() {
		Arr_SortedList list;
		//시드값을 얻기위한 random_device 생성
		std::random_device rd;
		//random_device를 통해 난수생성 엔진을 초기화 한다.
		std::mt19937 gen(rd());
		//정수를 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
		std::uniform_int_distribution<int> random(0, 25);
		
		for (int i = 0; i < list.MAX_SIZE; i++)
		{
			list.Add(random(gen));
		}
		cout << "list : length = " << list.GetLength() << endl; list.Print();
		cout << endl;

		for (int i = 0; i < 5; i++)
		{
			int num = random(gen);
			if (list.Contain(element{ num })){
				cout << "[" << num << "] 은 리스트에 포함 돼있습니다" << endl;
			}
			else {
				cout << "[" << num << "] 은 리스트에 포함 돼있지않습니다." << endl;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			int num = random(gen);
			list.Delete(num);
			cout << "list : length = " << list.GetLength() << endl; list.Print();
			cout << endl;
		}
	}
};
#pragma endregion

//23. 단순 연결 리스트로 SortedList 구현하기
#pragma region question23
class Link_SortedList {
	NodeType* head;
	NodeType* tail;
	int size;
	void PushFront(NodeType* node);
	void PushBack(NodeType* node);
	void PopFront();
	void PopBack(NodeType* pretail = nullptr);
public:
	void Init() { size = 0; head = nullptr; tail = nullptr; }
	Link_SortedList() { Init(); }
	bool Is_empty() { return size == 0; }
	int GetLength() { return size; }
	void Add(element item);
	void Delete(element item);
	void Clear();
	bool Contain(element item);
	void Print();
	~Link_SortedList() { 
		Clear(); 
		cout << "동적메모리 삭제 완료" << endl; }
};
void Link_SortedList::PushFront(NodeType* node) {
	node->Link = head;
	head = node;
	size++;
}
void Link_SortedList::PushBack(NodeType* node) {
	tail->Link = node;
	tail = node;
	size++;
}
void Link_SortedList::PopFront() {
	if (head == nullptr) { cout << "리스트가 NULL 입니다." << endl; tail = nullptr; return; }
	NodeType* new_head = head->Link;
	delete head;
	head = new_head;
	size--;
}
void Link_SortedList::PopBack(NodeType* pretail) {
	if (head == nullptr) { cout << "리스트가 NULL 입니다." << endl; tail = nullptr; return; }

	if (pretail == nullptr) {
	NodeType* new_tail = nullptr;
	NodeType* iter = head;
		while (iter->Link != nullptr)
		{
			new_tail = iter;
			iter = iter->Link;
		}
		delete iter;
		tail = new_tail;
		if(tail !=nullptr)
			tail->Link = nullptr;
		size--;
	}
	else {
		delete tail;
		tail = pretail;
		pretail->Link = nullptr;
		size--;
	}
}
void Link_SortedList::Add(element item) {
	NodeType* new_node = new NodeType{ item, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	if (Is_empty()) { head = new_node; tail = new_node; size++; return; }
	if (item < head->data) { PushFront(new_node); return; }

	NodeType* preNode = head;
	NodeType* iter = head->Link;

	while (iter != nullptr)
	{
		if (item < iter->data) {
			preNode->Link = new_node;
			new_node->Link = iter;
			size++;
			return;
		}
		preNode = iter;
		iter = iter->Link;
	}
	PushBack(new_node);
}
void Link_SortedList::Delete(element item) {
	if (head == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
	int deleteCount = 0;

	while (head->data == item)	//삭제할 데이터가 head인경우
	{
		PopFront(); deleteCount++;
	}
	NodeType* preIter = head;
	NodeType* removed = nullptr;
	element tailData = tail->data;		//삭제한 노드가 꼬리인지 확인할 변수

	removed = preIter->Link;
	while (removed != nullptr)
	{
		if (removed->data == item) {
			element removedData = removed->data;

			preIter->Link = removed->Link;	//삭제할 노드 앞이랑 뒤 연결
			delete removed; size--;			
			removed = preIter->Link;		//뒤 노드를 다시 삭제할 노드에 연결
			deleteCount++;

			if (removedData == tailData) {	//삭제한 노드가 꼬리라면
				tail = preIter; tail->Link = nullptr;
			}
		}
		else {
			preIter = removed;
			removed = removed->Link;
		}
	}

	if (deleteCount > 0)
		cout << "[" << item << "] " << deleteCount << "개를 찾아서 삭제했습니다." << endl;
	else
		cout << "[" << item << "] 삭제 실패 : 존재하지 않는 데이터 입니다." << endl;
}
void Link_SortedList::Clear() {
	NodeType* iter = head;
	NodeType* removed = nullptr;
	while (iter != nullptr)
	{
		removed = iter;
		iter = iter->Link;
		delete removed;
	}
	Init();
}
bool Link_SortedList::Contain(element item) {
	if (head == nullptr) { cout << "리스트가 NULL 입니다." << endl; return false; }
	NodeType* iter = head;
	while (iter != nullptr)
	{
		if (iter->data == item)
			return true;
		iter = iter->Link;
	}
	return false;
}
void Link_SortedList::Print() {
	NodeType* iter = head;
		cout << "head : " << head->data << " tail : " << tail->data << endl;
	while (iter != nullptr)
	{
		cout.width(3); cout << iter->data <<",";
		iter = iter->Link;
	}
	cout << endl;
}

class Question_23 {
public:
	void Run() {
		Link_SortedList* list = new Link_SortedList;
		//시드값을 얻기위한 random_device 생성
		std::random_device rd;
		//random_device를 통해 난수생성 엔진을 초기화 한다.
		std::mt19937 gen(rd());
		//정수를 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
		std::uniform_int_distribution<int> random(0, 25);

		for (int i = 0; i < 10; i++)
			list->Add(element{ random(gen) });

		cout << "list : length = " << list->GetLength() << endl;
		list->Print();

		for (int i = 0; i < 5; i++)
		{
			int num = random(gen);
			if (list->Contain(element{ num })) {
				cout << "[" << num << "] 은 리스트에 포함 돼있습니다" << endl;
			}
			else {
				cout << "[" << num << "] 은 리스트에 포함 돼있지않습니다." << endl;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			int num = random(gen);
			list->Delete(num);
			cout << "list : length = " << list->GetLength() << endl; list->Print();
			cout << endl;
		}
		delete list;
	}
};
#pragma endregion

//24. 연결리스트를 활용한 희소행렬 구현하기
#pragma region question24
struct MatrixElement {
	int row;
	int col;
	int value;
};
struct MatrixNode {
	MatrixElement data;
	MatrixNode* link;
};
class Matrix {
	MatrixNode* head;
	MatrixNode* tail;
	int size;
	void PushFront(MatrixNode* new_head);
	void PushBack(MatrixNode* new_tail);
	void PopFront();
	void PopBack(MatrixNode* pre_tail = nullptr);
	int Compare(MatrixNode* nodeA, MatrixNode* nodeB); //행렬이 A가 작으면 1 같으면 0 크면 -1
public:
	void Init() { size = 0; head = nullptr; tail = nullptr; }
	Matrix() { Init(); }
	int GetLength() { return size; }
	bool is_empty() { return size == 0; }
	void Add(MatrixElement item);
	void Delete(int value);
	void Clear();
	bool Contain(int value);
	void Print();
	~Matrix() { Clear(); cout << "동적 메모리 삭제 완료" << endl; }
};
void Matrix::PushFront(MatrixNode* new_head) {
	if (head == nullptr) { head = new_head; tail = new_head; return; }
	new_head->link = head;
	head = new_head;
	size++;
}
void Matrix::PushBack(MatrixNode* new_tail) {
	if (head == nullptr) { head = new_tail; tail = new_tail; return; }
	tail->link = new_tail;
	tail = new_tail;
	size++;
}
void Matrix::PopFront() {
	if (head == nullptr) { cout << "리스트가 NULL 입니다." << endl; tail = nullptr; return; }
	MatrixNode* new_head = head->link;
	delete head;
	head = new_head;
	size--;
}
void Matrix::PopBack(MatrixNode* pre_tail) {
	if (pre_tail == nullptr) {
		if (head == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
		MatrixNode* new_tail = nullptr;
		MatrixNode* iter = head;

		while (iter->link != nullptr)
		{
			new_tail = iter;
			iter = iter->link;
		}
		delete iter;
		tail = new_tail;
		if(tail != nullptr)
			tail->link = nullptr;
		size--;
	}
	else {
		delete tail;
		tail = pre_tail;
		tail->link = nullptr;
		size--;
	}
}
int Matrix::Compare(MatrixNode* nodeA, MatrixNode* nodeB) {
	if (nodeA->data.row < nodeB->data.row)
		return 1;
	else if (nodeA->data.row == nodeB->data.row) {
		if (nodeA->data.col < nodeB->data.col)
			return 1;
		else if (nodeA->data.col == nodeB->data.col)
			return 0;
		else
			return -1;
	}
	else
		return -1;
}
void Matrix::Add(MatrixElement item) {
	MatrixNode* new_node = new MatrixNode{ item, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	if (head == nullptr) { head = new_node; tail = new_node; size++; return; }
	if (item.row < head->data.row) { PushFront(new_node); return; }

	MatrixNode* pre_node = head;
	MatrixNode* iter = head->link;
	while (iter != nullptr)
	{
		switch (Compare(new_node, iter))
		{
		case 1:	//new_node가 작을때
			pre_node->link = new_node;
			new_node->link = iter;
			size++;
			return;
		case 0:	//같을때
			cout << "이미 존재하는 [" << iter->data.row << "][" << iter->data.col << "] 행렬의 값을 " << iter->data.value << "에서 " << new_node->data.value << "로 바꿨습니다." << endl;
			iter->data.value = new_node->data.value;
			delete new_node; return;
		case -1: //new_node가 클때
			pre_node = iter;
			iter = iter->link;
		}
	}
	PushBack(new_node);
}
void Matrix::Delete(int value) {
	if (head == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
	int deleteCount = 0;
	int tail_value = tail->data.value;

	if (head->data.value == value) {
		PopFront(); deleteCount++;
	}

	MatrixNode* pre_node = head;
	MatrixNode* removed = head->link;
	while (removed != nullptr)
	{
		if (removed->data.value == value) {
			pre_node->link = removed->link;
			delete removed;
			removed = pre_node->link;
			deleteCount++;
			size--;
			if (value == tail_value) {
				tail = pre_node; tail->link = nullptr;
			}
		}
		else {
			pre_node = removed;
			removed = removed->link;
		}
	}
	if (deleteCount > 0) { cout << "[" << value << "] " << deleteCount << "개를 찾아서 삭제 했습니다." << endl; }
	else { cout << "[" << value << "] 삭제 실패 : 존재하지 않는 데이터 입니다." << endl; }
}
void Matrix::Clear() {
	if (head == nullptr) { cout << "리스트가 NULL 입니다. " << endl; return; }
	MatrixNode* iter = head;
	MatrixNode* removed = nullptr;

	while (iter != nullptr)
	{
		removed = iter;
		iter = iter->link;
		delete removed;
	}
	Init();
}
bool Matrix::Contain(int value) {
	if (head == nullptr) { cout << "리스트가 NULL 입니다. " << endl; return false; }
	MatrixNode* iter = head;
	while (iter != nullptr)
	{
		if (iter->data.value == value)
			return true;
		iter = iter->link;
	}
	return false;
}
void Matrix::Print() {
	if (head == nullptr) { cout << "리스트가 NULL 입니다. " << endl; return; }
	MatrixNode* iter = head;
	
	while (iter != nullptr)
	{
		cout << "("; cout.width(2); cout << iter->data.row << ",";
		cout.width(2); cout << iter->data.col << ",";
		cout.width(2); cout << iter->data.value << ")";
		cout << endl;
		iter = iter->link;
	}
}
class Question_24 {
public:
	void Run() {
		Matrix* matrix = new Matrix;
		int max_element = 10;

		//시드값을 얻기위한 random_device 생성
		std::random_device rd;
		//random_device를 통해 난수생성 엔진을 초기화 한다.
		std::mt19937 gen(rd());
		//정수를 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
		std::uniform_int_distribution<int> random(0, 20);

		for (int i = 0; i < max_element; i++)
		{
			int randrow = random(gen);
			int randcol = random(gen);
			int randvalue = random(gen);

			matrix->Add(MatrixElement{ randrow, randcol, randvalue });
		}

		cout << "matrix : length = " << matrix->GetLength() << endl; matrix->Print();
		cout << endl;

		for (int i = 0; i < 5; i++)
		{
			int num = random(gen);
			if(matrix->Contain(num)) {
				cout << "[" << num << "] 은 리스트에 포함 돼있습니다" << endl;
			}
			else {
				cout << "[" << num << "] 은 리스트에 포함 돼있지않습니다." << endl;
			}
		}
		cout << endl;

		for (int i = 0; i < 5; i++)
		{
			int num = random(gen);
			matrix->Delete(num);
			cout << "matrix : length = " << matrix->GetLength() << endl; matrix->Print();
			cout << endl;
		}
		delete matrix;
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
	/*Question_18 q18;
	q18.run();*/
	/*Question_19 q19;
	q19.Run();*/
	/*Question_20 q20;
	q20.Run();*/
	/*Question_21 q21;
	q21.Run();*/
	/*Question_22 q22;
	q22.Run();*/
	/*Question_23 q23;
	q23.Run();*/
	Question_24 q24;
	q24.Run();

	return 0;
}