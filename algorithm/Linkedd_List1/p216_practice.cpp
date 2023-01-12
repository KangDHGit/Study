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
		for (int i = 1; i < 6; i++)
			list->Push_back(element{ i });

		cout << "������ : head = " << list->GetHead()->data << " tail = " << list->GetTail()->data << endl;
		list->List_Print();
		oddDelete(list);
		cout << "������ : head = " << list->GetHead()->data << " tail = " << list->GetTail()->data << endl;
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
	Question_16 q16;
	q16.run();

	return 0;
}