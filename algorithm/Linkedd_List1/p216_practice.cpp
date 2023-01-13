#include<iostream>
#include<tuple>
#include<random>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::tuple;

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
	ListType() :size(0) { head = nullptr; tail = nullptr; }
	int GetSize() { return size; }		//10��-1	(����Ʈ���� ���� ���� ���)
	NodeType* GetHead() const { return head; }
	NodeType* GetTail() const { return tail; }
	void Pop_front();					//13�� ������ ���� �߰�(head����)
	void Pop_back();					//16�� ������ ���� �߰�(tail����)
	static int GetSize(ListType* list);	//10��-2	(����Ʈ�� �Ű������� �޾Ƽ� ����ϴ� ���)
	int GetSum();						//11��	(��� ��� �������� ��)
	int Count(element data);			//12��	(data�� ���� ���� ����� ����)
	void DeleteElements(element data);	//13��	(Ư�� ������ �� ���� ����)
	void Push_back(element data);
	void List_Print();
	void Clear();
	~ListType() { Clear(); delete this; }
};
//10��-2 ����
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
	if (new_node == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }
	
	if (head == nullptr) { head = new_node, tail = new_node; }
	else {
		tail->Link = new_node;
		tail = new_node;
	}
	size++;
}
//9��
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
//12��
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
//11��
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
	if (head == nullptr) { cout << "����Ʈ�� NULL �Դϴ�." << endl; return; }
	NodeType* new_head = head->Link;
	delete head;
	head = new_head;
	size--;
}
void ListType::Pop_back() {
	NodeType* iter = head;
	NodeType* new_tail = nullptr;
	if (iter == nullptr) { cout << "����Ʈ�� NULL �Դϴ�" << endl; return; }

	while (iter->Link != nullptr)
	{
		new_tail = iter;
		iter = iter->Link;
	}
	delete iter;
	tail = new_tail;
	tail->Link = nullptr;
}
//13��
void ListType::DeleteElements(element data) {
	if (head == nullptr) { cout << "����Ʈ�� NULL �Դϴ�." << endl; return; }
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

//14. name, age, height�� ������ �� �ִ� �ܼ����� ����Ʈ
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
	cout << "�̸� : "; cout.width(5); cout << _name << " ���� : " << _age << " Ű :	" << _height << endl;
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
	if (new_head == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }

	if (head == nullptr) { head = new_head; tail = new_head; }
	else {
		new_head->Link = head;
		head = new_head;
	}
	size++;
}
void ListType_Person::Push_back(Person data) {
	Person* new_tail = new Person(data);
	if (new_tail == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }

	if (head == nullptr) { head = new_tail; tail = new_tail; }
	else {
		tail->Link = new_tail;
		tail = new_tail;
	}
	size++;
}
void ListType_Person::Insert(Person data, int index) {
	if (index < 0 || index > size) { cout << "�߸��� �ε��� ��ȣ �Դϴ�." << endl; return; }
	
	Person* new_person = new Person(data);
	if (new_person == nullptr) { cout << "�޸� �Ҵ� ����	" << endl; return; }

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
	if (head == nullptr) { cout << "����Ʈ�� NULL �Դϴ�." << endl; return; }
	else {
		Person* new_head = head->Link;
		delete head;
		head = new_head;
		size--;
	}
}
void ListType_Person::Pop_back() {
	if (head == nullptr) { cout << "����Ʈ�� NULL �Դϴ�." << endl; return; }
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
	cout << "==========����Ʈ ���==========" << endl;
	while (iter != nullptr)
	{
		cout << index << "�� "; iter->Print();
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

//15. �������� ���� ���� ����Ʈ�� �ִ� ���� �ּҰ��� ã�� ���α׷�
#pragma region question15
class Question_15 {
	ListType* list;
	bool max;
	bool min;

	int Find(ListType* list, bool compare) {
		if (list == nullptr || list->GetHead() == nullptr) { cout << "����Ʈ�� NULL �Դϴ�." << endl; return -1; }

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
		//�õ尪�� ������� random_device ����
		std::random_device rd;
		//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
		std::mt19937 gen(rd());
		//����(0~99)���� �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
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
		cout << "�ִ밪 : " << maxNum << " �ּҰ� : " << minNum << endl;
	}
};
#pragma endregion

//16. Ȧ����° �ִ� ������ �����ϴ� ���α׷�
#pragma region question16
class Question_16 {
	ListType* list;
	void oddDelete(ListType* list) {
		NodeType* even = list->GetHead()->Link;
		NodeType* odd = nullptr;
		list->Pop_front();

		while (even->Link != nullptr)		//¦����尡 tail�� �ƴҶ� ����
		{
			odd = even->Link;			//Ȧ����� �ּҸ� �Ѱ���
			if (odd->Link == nullptr) {	//Ȧ����� ������ NULL(�� Ȧ����尡 tail�̸�)
				list->Pop_back(); break;
			}
			
			even->Link = odd->Link;		//¦����° ���� ����
			delete odd;					//Ȧ�� ��� ����
			even = even->Link;			//����¦�� ���� �̵�
		}
	}
public:
	void run() {
		list = new ListType;
	
		//�õ尪�� ������� random_device ����
		std::random_device rd;
		//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
		std::mt19937 gen(rd());
		//����(10~20)���� �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
		std::uniform_int_distribution<int> random(10, 20);

		int rand = random(gen);
		for (int i = 1; i < rand; i++)
			list->Push_back(element{ i });

		cout << "������ : head = " << list->GetHead()->data << " tail = " << list->GetTail()->data << endl;
		list->List_Print();
		oddDelete(list);
		cout << "������ : head = " << list->GetHead()->data << " tail = " << list->GetTail()->data << endl;
		list->List_Print();
	}
};
#pragma endregion

//17. alternate �Լ� �ۼ�(�ΰ��� ����Ʈ�� �ϳ��� ������ ��ġ��)
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


		//�õ尪�� ������� random_device ����
		std::random_device rd;
		//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
		std::mt19937 gen(rd());
		//����(5~10)���� �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
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

//18. merge �Լ� �ۼ�(������������ ���ĵ� �ִ� �ΰ��� ����Ʈ�� ������ ������ ��ġ��)
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

		//�õ尪�� ������� random_device ����
		std::random_device rd;
		//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
		std::mt19937 gen(rd());
		//����(5~10)���� �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
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

//19. split �Լ� �ۼ�(����Ʈ �ϳ��� �ΰ��� �и�, Ȧ����° ����Ʈ, ¦����° ����Ʈ)
#pragma region question19
class Question_19 {
	void Split(ListType* list, ListType* outlistA, ListType* outlistB) {
		if (list == nullptr) { cout << "�и��� ����Ʈ�� NULL �Դϴ�." << endl; return; }
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

		//�õ尪�� ������� random_device ����
		std::random_device rd;
		//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
		std::mt19937 gen(rd());
		//����(10~20)���� �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
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
	}
};
#pragma endregion

//20. ���׽��� ���Ḯ��Ʈ�� ��Ÿ���� �� ���׽��� ���� ���ϱ�
//21. � �Ǽ� x�� ���� ���׽��� ���� ����ϴ� �Լ� �ۼ�
#pragma region question20~21
struct Term
{
	int coef;	//���
	int expon;	//����(�ŵ�����)
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
	if (new_tail == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }

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
		if (poly == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return nullptr; }

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
		if (polys[0] == nullptr || polys[1] == nullptr || sum_poly == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }

		//�õ尪�� ������� random_device ����
		std::random_device rd;
		//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
		std::mt19937 gen(rd());
		//������ �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
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

		//�õ尪�� ������� random_device ����
		std::random_device rd;
		//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
		std::mt19937 gen(rd());
		//������ �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
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

//22. �迭�� SortedList �����ϱ�
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
	~Arr_SortedList() { Clear(); delete this; }
};
void Arr_SortedList::Add(element item) {
	if (Is_full()) { cout << "����Ʈ ��ȭ ����" << endl; return; }
	if (Is_empty()) { top++; data[top] = item; return; }

	
	for (int i = 0; i < top + 1; i++)
	{
		if (item < data[i]) {	// 0 1 3 4 �� 2����
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
			i--;	//��ĭ�� ������� ������ ���ڸ� �ѹ��� �˻�
			deleteCount++;
			top--;
		}
	}
	if (deleteCount > 0) { cout << "["<< item << "] " << deleteCount << "���� ã�Ƽ� ���� �߽��ϴ�." << endl; }
	else { cout << "[" << item << "] ���� ���� : �������� �ʴ� ������ �Դϴ�." << endl; }
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
		//�õ尪�� ������� random_device ����
		std::random_device rd;
		//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
		std::mt19937 gen(rd());
		//������ �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
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
				cout << "[" << num << "] �� ����Ʈ�� ���� ���ֽ��ϴ�" << endl;
			}
			else {
				cout << "[" << num << "] �� ����Ʈ�� ���� �������ʽ��ϴ�." << endl;
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

//23. �ܼ� ���� ����Ʈ�� SortedList �����ϱ�
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
	if (head == nullptr) { cout << "����Ʈ�� NULL �Դϴ�." << endl; tail = nullptr; return; }
	NodeType* new_head = head->Link;
	delete head;
	head = new_head;
	size--;
}
void Link_SortedList::PopBack(NodeType* pretail) {
	NodeType* new_tail = nullptr;
	NodeType* iter = head;
	if (iter == nullptr) { cout << "����Ʈ�� NULL �Դϴ�." << endl; tail = nullptr; return; }

	if (pretail == nullptr) {
		while (iter->Link != nullptr)
		{
			new_tail = iter;
			iter = iter->Link;
		}
		delete iter;
		tail = new_tail;
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
	if (new_node == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }
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
	if (head == nullptr) { cout << "����Ʈ�� NULL �Դϴ�." << endl; return; }
	NodeType* preIter = head;
	NodeType* removed = nullptr;
	int count = 0;
	int deleteCount = 0;
	while (head->data == item)
	{
		PopFront(); preIter = head;
		deleteCount++;
		count++;
	}

	removed = preIter->Link;
	while (removed != nullptr)
	{
		if (removed->data == item) {
			preIter->Link = removed->Link;	//������ ��� ���̶� �� ����
			delete removed; size--;			
			removed = preIter->Link;		//�� ��带 �ٽ� ������ ��忡 ����
			deleteCount++;
			count++;

			if (count == size)				//������ ��尡 �������
				tail = preIter;
		}
		else {
			preIter = removed;
			removed = removed->Link;
		}
	}
	if (deleteCount > 0)
		cout << "[" << item << "] " << deleteCount << "���� ã�Ƽ� �����߽��ϴ�." << endl;
	else
		cout << "[" << item << "] ���� ���� : �������� �ʴ� ������ �Դϴ�." << endl;
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
		list->Add(element{ 2 });
		list->Add(element{ 0 });
		list->Add(element{ 1 });
		list->Add(element{ 3 });
		list->Delete(0);
		list->Print();
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
	Question_23 q23;
	q23.Run();

	return 0;
}